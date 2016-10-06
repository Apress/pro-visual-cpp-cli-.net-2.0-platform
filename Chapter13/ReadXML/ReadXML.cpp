#using <system.xml.dll>

using namespace System;
using namespace System::Xml;


String ^indent(Int32 depth)
{
    String ^ind = "";
    return ind->PadLeft(depth*3, ' ');
}

void main()
{
    XmlReader ^reader;
    
    try
    {
        reader = XmlReader::Create("Monsters.xml");

        while (reader->Read())
        {
            switch (reader->NodeType)
            {
                case XmlNodeType::Comment:
                    Console::WriteLine(
                        "{0}Comment node: Value='{1}'",
                        indent(reader->Depth), reader->Value);
                    break;
                case XmlNodeType::Element:
                    Console::WriteLine(
                        "{0}Element node: Name='{1}'",
                        indent(reader->Depth), reader->Name);

                    if (reader->HasAttributes)
                    {
                        while (reader->MoveToNextAttribute())
                        {
                            Console::WriteLine(
                                "{0}Attribute node: Name='{1}' Value='{2}'",
                                indent(reader->Depth), reader->Name, 
                                reader->Value);
                        }
                        reader->MoveToElement();
                    }

                    if (reader->IsEmptyElement)
                    {
                        Console::WriteLine(
                            "{0}End Element node: Name='{1}'",
                            indent(reader->Depth), reader->Name);
                    }
                    break;
                case XmlNodeType::EndElement:
                    Console::WriteLine(
                        "{0}End Element node: Name='{1}'",
                        indent(reader->Depth), reader->Name);
                    break;
                case XmlNodeType::Text:
                    Console::WriteLine(
                        "{0}Text node: Value='{1}'",
                        indent(reader->Depth), reader->Value);
                    break;
                case XmlNodeType::XmlDeclaration:
                    Console::WriteLine(
                        "Xml Declaration node: Name='{1}'",
                        indent(reader->Depth), reader->Name);

                    if (reader->HasAttributes)
                    {
                        while (reader->MoveToNextAttribute())
                        {
                            Console::WriteLine(
                                "{0}Attribute node: Name='{1}' Value='{2}'",
                                indent(reader->Depth), reader->Name, 
                                reader->Value);
                        }
                    }
                    reader->MoveToElement();
                    Console::WriteLine(
                        "End Xml Declaration node: Name='{1}'",
                        indent(reader->Depth), reader->Name);
                    break;
                case XmlNodeType::Whitespace:
                    // Ignore white space
                    break;
                default:
                    Console::WriteLine(
                        "***UKNOWN*** node: Name='{1}' Value='{2}'",
                        indent(reader->Depth), reader->Name, reader->Value);
            }
        }
    }
    catch (XmlException ^e)
    {
        Console::WriteLine("\nReadXML Aborted with error: {0}",
            e->Message);
    }
    finally
    {
        if (reader->ReadState != ReadState::Closed)
        {
            reader->Close();
        }
    }
}