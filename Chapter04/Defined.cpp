using namespace System;

#define DISAPPEARS
#define ONE 1
#define TWO 2
#define POW2(x) (x)*(x)

void main()
{
    Console::Write("The follow symbol disappears->" DISAPPEARS);
    Console::WriteLine("<-");

    Int32 x = TWO;
    Int32 y = POW2(x + ONE);

    Console::WriteLine(y);
}