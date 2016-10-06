#using <system.dll>

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Specialized;

void main()
{
    ListDictionary ^ldict = gcnew ListDictionary();

    ldict->Add("A", "First");
    ldict->Add("B", "Second");
    ldict->Add("C", "Third");
    ldict["D"] = "Fourth";

    try {
        ldict->Add("C", "Third Replaced");
    }
    catch (ArgumentException ^e)
    {
        Console::WriteLine("ldict->Add(\"C\", \"Third Replaced\");");
        Console::WriteLine("Throws exception: {0}", e->Message);
    }
    ldict["B"] = "Second Replaced";

    Console::WriteLine("\nEnumerate");
    IEnumerator ^keys = ldict->Keys->GetEnumerator();
    IEnumerator ^vals = ldict->Values->GetEnumerator();
    while ( keys->MoveNext() && vals->MoveNext())
    {
        Console::WriteLine("{0}\t\t{1}", keys->Current, vals->Current);
    }

    Console::WriteLine();
}