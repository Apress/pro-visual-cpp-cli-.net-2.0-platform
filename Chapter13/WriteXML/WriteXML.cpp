using namespace System;
using namespace System::Xml;

void main()
{
    XmlWriter ^writer;
    try
    {
        XmlWriterSettings ^settings = gcnew XmlWriterSettings();
        settings->Indent = true;
        settings->IndentChars = ("   ");
        settings->NewLineOnAttributes = true;

        writer = XmlWriter::Create("Goblin.xml", settings);

        writer->WriteStartDocument();

        writer->WriteStartElement("MonsterList");

        writer->WriteComment("Program Generated Easy Monster");
        writer->WriteStartElement("Monster");

        writer->WriteStartElement("Name");
        writer->WriteString("Goblin");
        writer->WriteEndElement();

        writer->WriteStartElement("HitDice");
        writer->WriteAttributeString("Dice", "1d8");
        writer->WriteAttributeString("Default", "4");
        writer->WriteEndElement();

        writer->WriteStartElement("Weapon");
        writer->WriteAttributeString("Number", "1");
        writer->WriteAttributeString("Damage", "1d4");
        writer->WriteString("Dagger");
        writer->WriteEndElement();

        // The folling not needed with WriteEndDocument
        // writer->WriteEndElement();
        // writer->WriteEndElement();

        writer->WriteEndDocument();

        writer->Flush();
    }
    catch (Exception ^e)
    {
        Console::WriteLine("XML Writer Aborted -- {0}", e->Message);
    }
    finally
    {
        if (writer->WriteState != WriteState::Closed)
        {
            writer->Close();
        }
    }
}