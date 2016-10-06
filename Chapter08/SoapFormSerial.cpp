#using <system.runtime.serialization.formatters.soap.dll>

using namespace System;
using namespace System::IO;
using namespace System::Runtime::Serialization::Formatters::Soap;

// --------- Player Attribute class ------------------------------------

[Serializable]
ref class PlayerAttr
{
public:
    property int Strength;
    property int Dexterity;
    property int Constitution;
    property int Intelligence;
    property int Wisdom;
    property int Charisma;

    PlayerAttr(int Str, int Dex, int Con, int Int, int Wis, int Cha);
    void Print();
};

PlayerAttr::PlayerAttr(int Str, int Dex, int Con, int Int, int Wis, int Cha)
{
    this->Strength     = Str;
    this->Dexterity    = Dex;
    this->Constitution = Con;
    this->Intelligence = Int;
    this->Wisdom       = Wis;
    this->Charisma     = Cha;
}

void PlayerAttr::Print()
{
    Console::WriteLine("Str: {0}, Dex: {1}, Con {2}", 
        Strength, Dexterity, Constitution);
    Console::WriteLine("Int: {0}, Wis: {1}, Cha {2}", 
        Intelligence, Wisdom, Charisma);
}

// -------- Player class ---------------------------------------

[Serializable]
ref class Player
{
public:
    property String ^Name;
    property String ^Race;
    property String ^Class;
    property PlayerAttr ^pattr;

    Player (String ^Name, String ^Race, String ^Class,
        int Str, int Dex, int Con, int Int, int Wis, int Cha);
    void Print();
};

Player::Player (String ^Name, String ^Race, String ^Class,
    int Str, int Dex, int Con, int Int, int Wis, int Cha)
{
    this->Name  = Name;
    this->Race  = Race;
    this->Class = Class;
    this->pattr = gcnew PlayerAttr(Str, Dex, Con, Int, Wis, Cha);
}

void Player::Print()
{
    Console::WriteLine("Name:  {0}", Name);
    Console::WriteLine("Race:  {0}", Race);
    Console::WriteLine("Class: {0}", Class);
    pattr->Print();
}

// -------- Main Function ----------------------------------------------


int main(void)
{
    Player ^Joe = gcnew Player("Joe", "Human", "Thief", 10, 18, 9, 13,10, 11);

    Console::WriteLine("Original Joe");
    Joe->Print();

    FileStream ^plStream = File::Create("Player.xml");

    SoapFormatter ^sf = gcnew SoapFormatter();
    sf->Serialize(plStream, Joe);
    plStream->Close();

    plStream = File::OpenRead("Player.xml");

    Player ^JoeClone = (Player^)sf->Deserialize(plStream);
    plStream->Close();

    Console::WriteLine("\nCloned Joe");
    JoeClone->Print();
}