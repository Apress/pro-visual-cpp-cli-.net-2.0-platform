using namespace System;
using namespace System::Collections;

void Print( BitArray ^barray, String ^desc)
{
    Console::WriteLine(desc);

    int i = 0;
    for each( bool^ val in barray )
    {
        Console::Write("{0} ", val);

        if (++i > 7)
        {
            Console::WriteLine();
            i = 0;
        }
    }
    Console::WriteLine();
}

void main()
{
    BitArray ^barray1 = gcnew BitArray( 8, true );
    Print(barray1, "BitArray( 8, true );");

    barray1[1] = false;
    barray1[4] = false;
    barray1->Not();
    Print(barray1, "Modified bit 1&4 then Not");

    BitArray ^barray2 = gcnew BitArray( 8, true );
    barray2->And(barray1);
    Print(barray2, "And with BitArray( 8, true )");

    barray2->SetAll(true);
    barray2->Or(barray1);
    Print(barray2, "Or with BitArray( 8, true )");

    barray2->SetAll(true);
    barray2->Xor(barray1);
    Print(barray2, "Xor with BitArray( 8, true )");

    array<unsigned char>^ chars = gcnew array<unsigned char> { 0x55, 0xAA };
    BitArray ^barray3 = gcnew BitArray( chars );
    Print(barray3, "BitArray(0x55, 0xAA);");

    Console::WriteLine("Item[0]={0}", barray3[0]);
    Console::WriteLine("Item[8]={0}", barray3[8]);

    Console::WriteLine();
}