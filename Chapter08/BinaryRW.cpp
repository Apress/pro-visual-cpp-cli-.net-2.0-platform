using namespace System;
using namespace System::IO;
using namespace System::Runtime::Serialization::Formatters::Binary;

// ------ Player class ---------------------------------------------

ref class Player
{
    String ^Name;
    Int32   Strength;
    Boolean IsMale;
    DateTime CreateDate;

public:
    Player();
    Player (String ^Name, int Str, bool IsMale);

    void Print();
    void Save(String ^fname);
    void Load(String ^fname);
};

Player::Player()
{
}

Player::Player (String ^Name, int Str, bool IsMale)
{
    this->Name     = Name;
    this->Strength = Str;
    this->IsMale   = IsMale;
    this->CreateDate = DateTime::Now;
}

void Player::Print()
{
    Console::WriteLine("Name: {0} ({1})", Name, (IsMale ? "M" : "F"));
    Console::WriteLine("Str:  {0}", Strength);
    Console::WriteLine("Date: {0}", CreateDate.ToString());
}

void Player::Save(String ^fname)
{
    FileStream   ^fs = File::OpenWrite(fname);
    BinaryWriter ^bw = gcnew BinaryWriter(fs);

    bw->Write(Name);
    bw->Write(Strength);
    bw->Write(IsMale);

    // Due to multicultures this is a safe way of storing DateTimes
    bw->Write(CreateDate.Ticks);  

    bw->Close();
    fs->Close();
}

void Player::Load(String ^fname)
{
    FileStream   ^fs = File::OpenRead(fname);
    BinaryReader ^br = gcnew BinaryReader(fs);

    Name     = br->ReadString();
    Strength = br->ReadInt32();
    IsMale   = br->ReadBoolean();

    // Due to multicultures this is a safe way of retrieving DateTimes
    CreateDate = DateTime( br->ReadInt64() );

    br->Close();
    fs->Close();
}

// ------- Main Function ---------------------------------------------

void main()
{
    Player ^Joe = gcnew Player("Joe", 10, true);
    Joe->Save("Player.dat");

    Console::WriteLine("Original Joe");
    Joe->Print();

    Player ^JoeClone = gcnew Player();
    JoeClone->Load("Player.dat");

    Console::WriteLine("\nCloned Joe");
    JoeClone->Print();
}