// FindZipCodeClass.h

#pragma once

using namespace System;
using namespace System::Web;
using namespace System::Web::Services;

namespace FindZipCode {

    [WebServiceBinding(ConformsTo=WsiProfiles::BasicProfile1_1,
                       EmitConformanceClaims = true)]
    [WebService(Namespace="http://managedcpp.net", 
                Description = "Zip code retrieval service")]
    public ref class FindZipCodeClass : public WebService
    {

    public:
        FindZipCodeClass()
        {
            InitializeComponent();
        }

    protected:
        ~FindZipCodeClass()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
        void InitializeComponent()
        {
        }
#pragma endregion

    public:
       [WebMethod(Description = "Get the zip code from city and state")] 
       int GetZip(String ^city, String ^state);
    };
}
