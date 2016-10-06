// StaticMethodPInvoke.cpp : main project file.

#include "stdafx.h"

using namespace System;
using namespace System::Runtime::InteropServices;

ref class SimpleClass
{
public:
    [DllImport("NativeCode")]
    static long square(long value);

    [DllImport("User32", CharSet=CharSet::Auto)]
    static int MessageBox(int hWnd, String^ text, String^ caption,
                          unsigned int type);
};

int main(array<System::String ^> ^args)
{
    long Squareof4 = SimpleClass::square(4);

    Console::WriteLine(L"The square of 4 is {0}", Squareof4);

    SimpleClass::MessageBox(0, L"Hello World!", L"A Message Box", 0);

    return 0;
}
