using namespace System;
using namespace System::Xml;
using namespace System::Xml::Schema;

ref class ValidateXML
{
public:
    ValidateXML(String ^filename)
    {
        XmlReader ^vreader;
        try
        {
            XmlReaderSettings ^settings = gcnew XmlReaderSettings();
            settings->ProhibitDtd = false;
            settings->ValidationType = ValidationType::DTD;
            settings->ValidationEventHandler += 
                gcnew ValidationEventHandler(this, 
                                             &ValidateXML::ValidationHandler);

            vreader = XmlReader::Create("Monsters.xml", settings);
     
            while(vreader->Read())
            {
                // ... Process nodes just like XmlTextReader()
            }
            Console::WriteLine("Finished Processing");
        }
        catch (Exception ^e)
        {
            Console::WriteLine(e->Message);
        }
        finally
        {
            if (vreader->ReadState != ReadState::Closed)
            {
                vreader->Close();
            }
        }
    }

    void ValidationHandler(Object ^sender, ValidationEventArgs ^e)
    {
        Console::WriteLine(e->Message);
    }
};

void main()
{
    gcnew ValidateXML("Monsters.xml");
}