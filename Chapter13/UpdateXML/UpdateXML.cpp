using namespace System;
using namespace System::Xml;

void main()
{
    XmlReader ^reader;
    XmlWriter ^writer;
    try
    {
        reader = XmlReader::Create("Monsters.xml");

        XmlWriterSettings ^settings = gcnew XmlWriterSettings();
        settings->Indent = true;
        settings->IndentChars = ("   ");

        writer = XmlWriter::Create("New_Monsters.xml", settings);

        while (reader->Read())
        {
            switch (reader->NodeType)
            {
                case XmlNodeType::Comment:
                    writer->WriteComment(reader->Value);
                    break;
                case XmlNodeType::Element:
                    writer->WriteStartElement(reader->Name);
                    writer->WriteAttributes(reader, false);
                    if (reader->IsEmptyElement)
                        writer->WriteEndElement();
                   break;
                case XmlNodeType::EndElement:
                    writer->WriteEndElement();

                    // *** Add new Monster Element
                    if (reader->Name->Equals("Name"))
                    {
                        writer->WriteStartElement("Encountered");
                        writer->WriteString("False");
                        writer->WriteEndElement();
                    }
                    break;
                case XmlNodeType::Text:
                    writer->WriteString(reader->Value);
                    break;
                case XmlNodeType::XmlDeclaration:
                    writer->WriteStartDocument();
                    break;
            }
        }
        writer->Flush();

        Console::WriteLine("Done");
    }
    catch (Exception ^e)
    {
        Console::WriteLine("XML Update Aborted -- {0}", e->Message);
    }
    finally
    {
        if (writer->WriteState != WriteState::Closed)
        {
            writer->Close();
        }
        if (reader->ReadState != ReadState::Closed)
        {
            reader->Close();
        }
    }
}
