#using <system.dll>

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Specialized;

void main()
{
    StringCollection ^strcol = gcnew StringCollection();

    strcol->Add("The first String");

    array<String^>^ tmpstr = gcnew array<String^> {"Third", "Fourth" };
    strcol->AddRange(tmpstr);

    strcol->Insert(1, "Second");

    strcol[0] = "First";

    StringEnumerator ^strenum = strcol->GetEnumerator();
    while ( strenum->MoveNext())
    {
        Console::WriteLine(strenum->Current);
    }

    Console::WriteLine("\n'for each' works as well");

    for each (String^ s in strcol)
        Console::WriteLine(s);

    Console::WriteLine();
}