#include "stdio.h"
#include "vcclr.h"

using namespace System;

ref class MClass
{
public:
    int x;
    ~MClass() { Console::WriteLine("MClass disposed"); }
protected:
    !MClass() { Console::WriteLine("MClass finalized"); }
};

#pragma unmanaged  // works with or without this line

class UMClass
{
public:
    gcroot<MClass^> mclass;

    ~UMClass() { printf("UMClass deleted\n"); }
};

#pragma managed

void main()
{
    UMClass *umc = new UMClass();
    umc->mclass = gcnew MClass();

    umc->mclass->x = 4;
    Console::WriteLine("Managed Print {0}", umc->mclass->x);
    printf("Unmanaged Print %d\n", umc->mclass->x);

    delete umc;
}
