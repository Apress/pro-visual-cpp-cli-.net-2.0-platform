using namespace System;

/// <Summary>Base Class</Summary>
ref class LevelOneException : public ApplicationException
{
public:
    LevelOneException( String ^err );
};

LevelOneException::LevelOneException(String ^err) : ApplicationException(err) 
{
}

/// <Summary>Inherited Class</Summary>
ref class LevelTwoException : public LevelOneException
{
public:
    LevelTwoException( String ^err );
};

LevelTwoException::LevelTwoException(String ^err) : LevelOneException(err)
{
}

/// <Summary>Catching multiple exceptions</Summary>
void main()
{
    for (int i = 0; i < 4; i++)
    {
        Console::WriteLine("Start Loop");
        try
        {
            if (i == 1)
                throw gcnew ApplicationException("\tBase Exception Thrown");
            else if (i == 2)
                throw gcnew LevelOneException("\tLevel 1 Exception Thrown");
            else if (i == 3)
                throw gcnew LevelTwoException("\tLevel 2 Exception Thrown");

            Console::WriteLine("\tNo Exception");
        }
        catch (LevelTwoException ^e2)
        {
            Console::WriteLine(e2->Message);
            Console::WriteLine("\tLevel 2 Exception Caught");
        }
        catch (LevelOneException ^e1)
        {
            Console::WriteLine(e1->Message);
            Console::WriteLine("\tLevel 1 Exception Caught");
        }
        catch (ApplicationException ^e)
        {
            Console::WriteLine(e->Message);
            Console::WriteLine("\tBase Exception Caught");
        }
        Console::WriteLine("End Loop");
    }
}