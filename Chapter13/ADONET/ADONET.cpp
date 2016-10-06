#using <System.EnterpriseServices.dll>
#using <System.Transactions.dll>

using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Xml;

String ^indent(int depth)
{
    String ^ind = "";
    return ind->PadLeft(depth*4, ' ');
}

void Navigate(XmlNode ^node, int depth)
{
    if (node == nullptr)
        return;

    Console::WriteLine("{0}: Name='{1}' Value='{2}'",
        String::Concat(indent(depth),node->NodeType.ToString()),
        node->Name, node->Value);

    if (node->Attributes != nullptr)
    {
        for (int i = 0; i < node->Attributes->Count; i++)
        {
            Console::WriteLine("{0}Attribute: Name='{1}' Value='{2}'",
                indent(depth+1),node->Attributes[i]->Name, 
                node->Attributes[i]->Value);
        }
    }

    Navigate(node->FirstChild, depth+1);
    Navigate(node->NextSibling, depth);
}


void main()
{
    XmlDocument ^doc = gcnew XmlDocument();

    try
    {
        SqlConnection ^connect = gcnew SqlConnection();

#ifdef SQLAuth
        //  SQL Server authentication
        connect->ConnectionString = 
            "User ID=sa; Password=;"
            "Data Source=(local); Initial Catalog=DCV_DB;";
#else
        //  Windows Integrated Security
        connect->ConnectionString = 
            "Persist Security Info=False; Integrated Security=SSPI;"
            "Data Source=(local); Initial Catalog=DCV_DB;";
#endif
        SqlDataAdapter ^dAdapt = gcnew SqlDataAdapter();
        DataSet ^dSet          = gcnew DataSet();
        dAdapt->SelectCommand  = gcnew SqlCommand("SELECT * FROM Authors", connect);
        
        dAdapt->Fill(dSet, "Authors");
        XmlDataDocument ^doc = gcnew XmlDataDocument(dSet);

        // Recursive navigation of the DOM tree
        Navigate(doc->DocumentElement, 0);
    }
    catch (Exception ^e)
    {
        Console::WriteLine("Error Occurred: {0}", e->Message);
    }
}