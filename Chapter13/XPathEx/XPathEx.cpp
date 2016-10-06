using namespace System;
using namespace System::Xml;
using namespace System::Xml::XPath;
using namespace System::Collections;

void GetMonsters(XPathNavigator ^nav)
{
    XPathNodeIterator ^list = 
        nav->Select("/MonsterList/Monster/Name");

    Console::WriteLine("Monsters\n--------");
    while (list->MoveNext())
    {
        XPathNavigator ^n = list->Current;
        Console::WriteLine(n->Value);
    }

//  The required code to do the same as above if no
//  XPathNavigator concatenation occurred.
/*
    list = nav->Select("/MonsterList/Monster/Name");

    Console::WriteLine("Monsters\n--------");
    while (list->MoveNext())
    {
        XPathNavigator ^n = list->Current;
        n->MoveToFirstChild();
        Console::WriteLine(n->Value);
    }
*/
}

void GetDragonsWeapons(XmlNode ^node)
{
    XmlNodeList ^list = 
        node->SelectNodes("//Monster[Name='Red Dragon']/Weapon");

    Console::WriteLine("\nDragon's Weapons\n----------------");

    IEnumerator ^en = list->GetEnumerator();
    while (en->MoveNext())
    {
        XmlNode ^n = (XmlNode^)en->Current;
        Console::WriteLine(n->FirstChild->Value);
    }
}

void GetGoblinSuccubusHitDice(XPathNavigator ^nav)
{
    XPathNodeIterator ^list = 
        nav->Select("//Monster[Name='Goblin' or Name='Succubus']/HitDice/@Dice");

    Console::WriteLine("\nGoblin & Succubus HD\n--------------------");
    while (list->MoveNext())
    {
        XPathNavigator ^n = list->Current;
        Console::WriteLine(n->Value);
    }
}

void GetSingleAttackWeapons(XPathNavigator ^nav)
{
    XPathNodeIterator ^list = 
        nav->Select("//Weapon[@Number <= 1]");

    Console::WriteLine("\nSingle Attack Weapons\n---------------------");
    while (list->MoveNext())
    {
        XPathNavigator ^n = list->Current;
        Console::WriteLine(n->Value);
    }
}

void main()
{
    XmlDocument ^doc = gcnew XmlDocument();

    try
    {
        doc->Load("Monsters.xml");
        XPathNavigator ^nav = doc->CreateNavigator();
        nav->MoveToRoot();

        GetMonsters(nav);
        GetDragonsWeapons(doc->DocumentElement);
        GetGoblinSuccubusHitDice(nav);
        GetSingleAttackWeapons(nav);
    }
    catch (Exception ^e)
    {
        Console::WriteLine("Error Occurred: {0}", e->Message );
    }
}