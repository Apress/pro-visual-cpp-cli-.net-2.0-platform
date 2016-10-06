using namespace System;

// Floating-point Fundamental Types in Action
void main()
{
    float w = 123.456f;   // standard decimal notation
    float x = 7890e3f;    // exponent notation
    double y = 34525425432525764765.76476476547654; // too big will truncate
    double z = 123456789012345e-300; // exponent will be reset

    Console::WriteLine( w ); // Write out Single
    Console::WriteLine( x ); // Write out Single with more zeros
    Console::WriteLine( y ); // Write out Double truncated
    Console::WriteLine( z ); // Write out Double shift back decimal
}
