using namespace System;
using namespace System::Xml;
using namespace System::Xml::XPath;

String ^indent(int depth)
{
    String ^ind = "";
    return ind->PadLeft(depth*4, ' ');
}

void Navigate(XPathNavigator ^nav, int depth)
{
    Console::WriteLine("{0}: Name='{1}' Value='{2}'",
        String::Concat(indent(depth), nav->NodeType.ToString()),
        nav->Name, nav->Value);

    if (nav->HasAttributes)
    {
        nav->MoveToFirstAttribute();
        do {
            Console::WriteLine("{0} Attribute: Name='{1}' Value='{2}'",
                indent(depth+1),nav->Name, nav->Value);
        }
        while(nav->MoveToNextAttribute());
        nav->MoveToParent();
    }

    if (nav->MoveToFirstChild())
    {
        Navigate(nav, depth+1);
        nav->MoveToParent();
    }
    if (nav->MoveToNext())
        Navigate(nav, depth);
}

void main()
{
    XmlDocument ^doc = gcnew XmlDocument();
    try
    {
        doc->Load("Monsters.xml");
        XPathNavigator ^nav = doc->CreateNavigator();
        nav->MoveToRoot();
        Navigate(nav, 0);
    }
    catch (Exception ^e)
    {
        Console::WriteLine("Error Occurred: {0}", e->Message);
    }
}