#using <System.EnterpriseServices.dll>
#using <System.Transactions.dll>

using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;

void main()
{
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
       connection->Open();

       cmd->CommandType = CommandType::Text;
       cmd->CommandText = "SELECT COUNT(*) FROM Authors";

       Object ^NumAuthors = cmd->ExecuteScalar();
       Console::WriteLine("The number of Authors are {0}", NumAuthors);

       cmd->CommandType = CommandType::Text;
       cmd->CommandText = "SELECT SUM(AuthorID) FROM Authors";

       Object ^UselessNum = cmd->ExecuteScalar();
       Console::WriteLine("The Sum of AuthorIDs for fun is {0}", UselessNum);
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