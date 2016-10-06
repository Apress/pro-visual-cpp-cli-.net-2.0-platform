using namespace System;

void main()
{
    try
    {
        try
        {
            throw gcnew ApplicationException("\t***Boom***");
            Console::WriteLine("Imbedded Try End");
        }
        catch (ApplicationException ^ie)
        {
            Console::WriteLine("Caught Exception ");
            Console::WriteLine(ie->Message);
            throw;
        }
        Console::WriteLine("Outer Try End");
    }
    catch (ApplicationException ^oe)
    {
        Console::WriteLine("Recaught Exception ");
        Console::WriteLine(oe->Message);
    }
}