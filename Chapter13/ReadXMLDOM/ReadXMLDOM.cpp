using namespace System;
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
        XmlReader ^reader = XmlReader::Create("Monsters.xml");
        doc->Load(reader);
        reader->Close();

        XmlNode ^node = doc->FirstChild;  // I want the Xml Declaration 

        // Recursive navigation of the DOM tree
        Navigate(node, 0);
    }
    catch (Exception ^e)
    {
        Console::WriteLine("Error Occurred: {0}", e->Message);
    }
}