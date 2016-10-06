#using <System.EnterpriseServices.dll>
#using <System.Transactions.dll>

using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;

void main()
{
    String ^Name = "Doors";

    SqlConnection ^connection = gcnew SqlConnection();

#ifdef SQLAuth
    //  SQL Server authentication
    connection->ConnectionString = 
        "User ID=sa; Password=;"
        "Data Source=(local); Initial Catalog=DCV_DB;";
#else
    //  Windows Integrated Security
    connection->ConnectionString = 
        "Persist Security Info=False; Integrated Security=SSPI;"
        "Data Source=(local); Initial Catalog=DCV_DB;";
#endif

    try
    {
        SqlCommand ^cmd = gcnew SqlCommand();
        cmd->Connection = connection;

        cmd->CommandType = CommandType::Text;
        cmd->CommandText = 
            String::Format("SELECT FirstName, LastName FROM Authors " 
			               "WHERE LastName = '{0}'", 
                           Name);

        connection->Open();

        SqlDataReader ^reader = cmd->ExecuteReader();

        while(reader->Read())
        {
            Console::WriteLine("{0} {1}", 
                reader["FirstName"], reader["LastName"]);
        }
        reader->Close();

        // CREATE PROCEDURE dbo.StoriesWhereLastName
        //   (
        //      @LastName NVARCHAR(32) = NULL
        //   )
        // AS
        //   /* SET NOCOUNT ON */

        //   SELECT StoryID, Headline, Story FROM Stories
        //   WHERE  LastName = @LastName
        //
        //   RETURN 

        cmd->CommandType = CommandType::StoredProcedure;
        cmd->CommandText = "StoriesWhereLastName";

		cmd->Parameters->Add(gcnew SqlParameter("@LastName",SqlDbType::VarChar));
        cmd->Parameters["@LastName"]->Value = Name;

        reader = cmd->ExecuteReader();

        Console::WriteLine("------------------------------------------------");
        while(reader->Read())
        {
            Console::WriteLine(reader["StoryID"]);
            Console::WriteLine(reader["Headline"]);
            Console::WriteLine(reader["Story"]);
            Console::WriteLine();
        }
        reader->Close();
    }
    catch (SqlException ^e)
    {
        Console::WriteLine("No connection the following error occurred: {0}",
            e->Message);
    }
    finally
    {
        connection->Close();
    }
}