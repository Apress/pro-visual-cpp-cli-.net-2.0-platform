using namespace System;

// Integer Fundamental Types in Action
void main()
{
    char    v = 'F';                // Intialize using charater literal
    short   w(123);                 // Intializing using Functional Notation
    int     x = 456789;             // Decimal literal assigned
    long    y = 987654321l;         // long integer literal assigned
    Int64   z = 0xFEDCBA9876543210; // Hex literal assigned

    Console::WriteLine( v );               // Write out a char
    Console::WriteLine( w );               // Write out a short
    Console::WriteLine( x );               // Write out a int
    Console::WriteLine( y );               // Write out a long
    Console::WriteLine( z );               // Write out a Int64
    Console::WriteLine( z.ToString("x") ); // Write out a Int64 in Hex
}
