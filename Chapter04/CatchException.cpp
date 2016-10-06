using namespace System;

ref class X {};
ref class Y {};

void main()
{
    X ^x = gcnew X;

    try
    {
         Y ^y = (Y^)x;   
         Console::WriteLine("No Exception");  // Should not execute
    }
    catch (InvalidCastException ^e)
    {
        Console::WriteLine("Invalid Cast Exception");
        Console::WriteLine(e->StackTrace);
    }
}