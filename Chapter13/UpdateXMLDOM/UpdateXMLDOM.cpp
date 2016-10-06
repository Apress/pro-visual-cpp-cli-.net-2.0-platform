using namespace System;
using namespace System::Xml;

void Navigate(XmlNode ^node)
{
    if (node == nullptr)
        return;

    if (node->Value != nullptr && node->Value->Equals("Dagger"))
    {
        if (node->ParentNode->ParentNode["Name"]->FirstChild->Value->
            Equals("Goblin"))
        {
            node->Value = "Saber";
            node->ParentNode->Attributes["Damage"]->Value = "1d8";
        }
    }

    Navigate(node->FirstChild);
    Navigate(node->NextSibling);
}


void main()
{
    XmlDocument ^doc = gcnew XmlDocument();

    try
    {
        doc->Load("Monsters.xml");
        XmlNode ^root = doc->DocumentElement; 

        // Recursive navigation of the DOM tree
        Navigate(root);

        doc->Save("New_Monsters.xml");
    }
    catch (Exception ^e)
    {
        Console::WriteLine("Error Occurred: {0}", e->Message );
    }
}