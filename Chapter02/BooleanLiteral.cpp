using namespace System;

// Boolean Literals in Action
void main()
{
    bool isTrue = true;
    bool isFalse = false;

    Console::WriteLine ( isTrue );
    Console::WriteLine ( isFalse );

    // This is kind of neat. Boolean literals are objects too!
    Console::WriteLine ( true.ToString () );
    Console::WriteLine ( false.ToString () );
}
