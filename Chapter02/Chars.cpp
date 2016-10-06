using namespace System;

// Character Fundamental Type in Action
void main()
{
    Char  a = L'A';       // character literal 'A'
    Char  b = L'\x0041';  // hex notation for hex 41 which happens to be 'A'

    Console::WriteLine ( a );
    Console::WriteLine ( b ); //Even though I put hex 41 in b, the ASCII 'A'
                              //is printed due to b being a Char
}
