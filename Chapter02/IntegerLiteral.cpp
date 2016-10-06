using namespace System;

// Integer Literals in Action
void main()
{
    Console::WriteLine (  010 );  // An Octal 10 is a base-10 8
    Console::WriteLine ( -010 ); // Negative Octal 10 is a base-10 -8

    Console::WriteLine (  0x10 ); // A Hex 10 is a base-10 16
    Console::WriteLine ( -0x10 ); // Negative Hex 10 is a base-10 -16

    // This is kind of neat. Number literals are objects too!
    Console::WriteLine ( (1234567890).ToString() );
    Console::WriteLine ( (0xABCDEF).ToString("X") );
} 
