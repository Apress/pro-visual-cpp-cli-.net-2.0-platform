using namespace System;

ref class MethodEx
{
public:
    void printPublic(int num)
    {
        for (int i = 0; i < num; i++)
        {
            Console::WriteLine( "Public" );
        }
        printProtected(num/2);
    }
protected:
    void printProtected(int num)
    {
        for (int i = 0; i < num; i++)
        {
            Console::WriteLine( "Protected" );
        }
        printPrivate(num/2);
    }
private:
    void printPrivate(int num)
    {
        for (int i = 0; i < num; i++)
        {
            Console::WriteLine( "Private" );
        }
    }
};

int main()
{
    MethodEx ex;

    ex.printPublic(4);
    // ex.printProtected(4);  // Error can not access
    // ex.printPrivate(4);    // Error can not access
}
