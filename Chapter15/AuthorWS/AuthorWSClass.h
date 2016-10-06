// AuthorWSClass.h

#pragma once

using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Web;
using namespace System::Web::Services;

namespace AuthorWS {

    [WebServiceBinding(ConformsTo=WsiProfiles::BasicProfile1_1,
                       EmitConformanceClaims = true)]
    [WebService(Namespace="http://managedcpp.net", 
                Description = "Author table access Web Service")]
    public ref class AuthorWSClass : public System::Web::Services::WebService
    {

    public:
        AuthorWSClass()
        {
            InitializeComponent();
        }

    protected:
        ~AuthorWSClass()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Data::SqlClient::SqlConnection^  sqlConnection;
        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

        void InitializeComponent()
        {
            this->sqlConnection = gcnew System::Data::SqlClient::SqlConnection();
            // 
            // sqlConnection
            // 
            this->sqlConnection->ConnectionString = L"Server=Amidala;Integrated Security=True;Database=DCV_DB";

            this->sqlConnection->FireInfoMessageEventOnUserErrors = false;
        }

#pragma endregion

    public:
        [WebMethod(Description = "Method to retrieve All Authors from the database")]
        DataSet ^GetAuthors(); 

        [WebMethod(Description = "Method to Commit changed made on client with Server database")]
        void UpdateAuthors(DataSet ^dSet);
    };
}
