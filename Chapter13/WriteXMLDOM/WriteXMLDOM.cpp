using namespace System;
using namespace System::Xml;

XmlElement ^CreateMonster(XmlDocument ^doc)
{
    XmlElement ^skeleton = doc->CreateElement("Monster");

    // <Name>Skeleton</Name>
    XmlElement ^name = doc->CreateElement("Name");
    name->AppendChild(doc->CreateTextNode("Skeleton"));
    skeleton->AppendChild(name);

    // <HitDice Dice=”1/2 d12” Default=”3” />
    XmlElement ^hitdice = doc->CreateElement("HitDice");
    XmlAttribute ^att = doc->CreateAttribute("Dice");
    att->Value = "1/2 d12";
    hitdice->Attributes->Append(att);
    att = doc->CreateAttribute("Default");
    att->Value = "3";
    hitdice->Attributes->Append(att);
    skeleton->AppendChild(hitdice);

    // <Weapon Number=”2” Damage=”1d3-1”>Claw</Weapon>
    XmlElement ^weapon = doc->CreateElement("Weapon");
    att = doc->CreateAttribute("Number");
    att->Value = "2";
    weapon->Attributes->Append(att);
    att = doc->CreateAttribute("Damage");
    att->Value = "1d3-1";
    weapon->Attributes->Append(att);
    weapon->AppendChild(doc->CreateTextNode("Claw"));
    skeleton->AppendChild(weapon);

    return skeleton;
}

void main()
{
    XmlDocument ^doc = gcnew XmlDocument();

    try
    {
        doc->Load("Monsters.xml");
        XmlNode ^root = doc->DocumentElement; 

        // Skip comment and goblin
        XmlNode ^child = root->FirstChild->NextSibling;

        // Insert new monster
        root->InsertAfter(CreateMonster(doc), child);
 
        doc->Save("New_Monsters.xml");
    }
    catch (Exception ^e)
    {
        Console::WriteLine("Error Occurred: {0}", e->Message );
    }
}
