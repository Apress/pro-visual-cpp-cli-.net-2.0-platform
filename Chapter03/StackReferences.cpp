using namespace System;

ref class Square
{
public:
    int Area()
    {
        return Dims * Dims;
    }

    int Dims;
};

void main()
{
    Square ^sqr1 = gcnew Square();     // Handle
    sqr1->Dims = 2;
    Console::WriteLine( sqr1->Area() );

    Square sqr2;                       // local stack instance
    sqr2.Dims = 3;
    Console::WriteLine( sqr2.Area() );
}
