using namespace System;

ref class MyException : public ApplicationException
{
public:
    MyException( String ^err ); 
};

MyException::MyException(System::String ^err) : ApplicationException(err) 
{
}

void main()
{
    for (int i = 0; i < 3; i++)
    {
        Console::WriteLine("Start Loop");
        try
        {
            if (i == 0)
            {
                Console::WriteLine("\tCounter equal to 0");
            }
            else if (i == 1)
            {
                throw gcnew MyException("\t**Exception** Counter equal to 1");
            }
            else
            {
                Console::WriteLine("\tCounter greater than 1");
            }
        }
        catch (MyException ^e)
        {
            Console::WriteLine(e->Message);
        }
        Console::WriteLine("End Loop");
    }
}