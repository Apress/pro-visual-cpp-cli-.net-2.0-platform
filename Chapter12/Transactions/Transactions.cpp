#using <System.EnterpriseServices.dll>
#using <System.Transactions.dll>

using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;

void main()
{
    String ^Name = "Doors";

    SqlConnection  ^connection = gcnew SqlConnection();
    SqlTransaction ^transaction; 

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

       SqlCommand ^cmd = gcnew SqlCommand();

       transaction = connection->BeginTransaction(
           IsolationLevel::Serializable, "AuthorTransaction");

       cmd->Connection  = connection;
       cmd->Transaction = transaction;

       cmd->CommandType = CommandType::StoredProcedure;
       cmd->CommandText = "InsertAuthor";

      cmd->Parameters->Add(gcnew SqlParameter("@LastName", SqlDbType::Char,32));
      cmd->Parameters->Add(gcnew SqlParameter("@FirstName",SqlDbType::Char,32));

       cmd->Parameters["@LastName"]->Value  = "Dope";
       cmd->Parameters["@FirstName"]->Value = "John";

       int affected = cmd->ExecuteNonQuery();
       if (affected <= 0)
           throw gcnew Exception("Insert Failed");
       Console::WriteLine("Insert - {0} rows are affected", affected);

       cmd->CommandType = CommandType::Text;
       cmd->CommandText = "UPDATE Authors SET LastName = 'Doe'"
                          "WHERE LastName = 'Dope'";

       affected = cmd->ExecuteNonQuery();
       if (affected <= 0)
           throw gcnew Exception("Insert Failed");
       Console::WriteLine("Update - {0} rows are affected", affected);

       // This transaction will return 0 affected rows 
       // because "Does" does not exist.
       // Thus, the if condition throws an execption which causes all 
       // Transactions to be rolled back.
       cmd->CommandType = CommandType::Text;
       cmd->CommandText = "DELETE FROM Authors WHERE LastName = 'Does'";

       affected = cmd->ExecuteNonQuery();
       if (affected <= 0)
           throw gcnew Exception("Insert Failed");
       Console::WriteLine("Delete - {0} rows are affected", affected);

       transaction->Commit();
    }
    catch (Exception ^e)
    {
        transaction->Rollback("AuthorTransaction");
        Console::WriteLine("Transaction Not completed");
        Console::WriteLine("SQL error occurred: {0}", e->Message);
    }
    finally
    {
        connection->Close();
    }
}