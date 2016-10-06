#using <system.dll>

using namespace System;
using namespace System::Collections::Generic;

void main()
{
    Queue<String^>^ que = gcnew Queue<String^>();
    Stack<String^>^ stk = gcnew Stack<String^>();

    array<String^>^ entry = gcnew array<String^> {
        "First", "Second", "Third", "Fourth" 
    };

    Console::WriteLine("Queue\t\tStack");

    Console::WriteLine("** ON **");
    for (int i = 0; i < entry->Length; i++)
    {
        que->Enqueue(entry[i]);
        stk->Push(entry[i]);  

        Console::WriteLine("{0}\t\t{1}", entry[i], entry[i]);
    }

    Console::WriteLine("\n** OFF **");
    while ((que->Count > 0) && (stk->Count > 0))
    {
        Console::WriteLine("{0}\t\t{1}", que->Dequeue(), stk->Pop());
    }

    que->Clear();
    stk->Clear();

    Console::WriteLine("\n");
}
