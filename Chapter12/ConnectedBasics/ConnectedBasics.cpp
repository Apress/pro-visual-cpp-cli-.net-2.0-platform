using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;

void main()
{
    SqlConnection^ connection = gcnew SqlConnection();

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
        connection->Open();
        Console::WriteLine("We got a connection!");
    }
    catch (SqlException ^e)
    {
        Console::WriteLine("No connection the following error occurred: {0}",
            e->Message);
    }
    finally
    {
        connection->Close();
        Console::WriteLine("The connection to the database has been closed");
    }
}
