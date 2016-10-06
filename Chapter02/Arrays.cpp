using namespace System;

// Arrays in Action
void main()
{
    // Single dimension
    array<int>^ a = gcnew array<int>(4);
    array<String^>^ b = gcnew array<String^>(4);

    for (int i = 0; i < a->Length; i++)
    {
        a[i] = i;
    }

    for (int i = 0; i < b->Length; i++)
    {
        b[i] = a[i].ToString();
    }

    for (int i = 0; i < b->Length; i++)
    {
        Console::WriteLine(b[i]);
    }

    Console::WriteLine();
    Array::Reverse(b);
    for (int i = 0; i < b->Length; i++)
    {
        Console::WriteLine(b[i]);
    }

    // Multi dimension uniform
    array<int,2>^ c = gcnew array<int,2>(4,3);
    array<String^,2>^ d = gcnew array<String^,2>(4,3);

    for (int x = 0; x < c->GetLength(0); x++)
    {
        for (int y = 0; y < c->GetLength(1); y++)
        {
            c[x,y] = (x*10)+y;
        }
    }

    Console::WriteLine();
    for (int x = 0; x < d->GetLength(0); x++)
    {
        for (int y = 0; y < d->GetLength(1); y++)
        {
            Console::Write("{0,-5:00}", c[x,y]);
        }
        Console::WriteLine();
    }

    // Multi dimension jagged
    array< array<int>^ >^ e = gcnew array<array<int>^>(4);

    for (int x = 0; x < e->Length; x++)
    {
        e[x] = gcnew array<int>(4+(x*2));  // each row 2 bigger
        for(int y = 0; y < e[x]->Length; y++)
        {
            e[x][y] = (x*10)+y;
        }
    }
 
    Console::WriteLine();

    for (int x = 0; x < e->Length; x++)
    {
        for (int y = 0; y < e[x]->Length; y++)
        {
            Console::Write("{0,-5:00}", e[x][y]);
        }
        Console::WriteLine();
    }
} 
