using namespace System;
using namespace System::Collections;

void main()
{
    array<int>^ IntList = gcnew array<int> { 1, 2, 3, 4, 5 };


    IEnumerable ^collection = (IEnumerable^)IntList;  //Not really needed
    IEnumerator ^enumerator = collection->GetEnumerator();

    Console::WriteLine("IEnumerator\n-----------");

    while (enumerator->MoveNext())
    {
        int i = (int)enumerator->Current;
        Console::WriteLine(i);
    }

    Console::WriteLine("\nfor each\n--------");

    for each (int i in IntList)
        Console::WriteLine(i);

    Console::WriteLine();
}
