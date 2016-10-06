// DllOldWay.cpp : main project file.

#include "stdafx.h"
#include "windows.h"

extern "C" __declspec(dllimport) long square(long value);

using namespace System;

int main(array<System::String ^> ^args)
{
    long Squareof4 = square(4);

    Console::WriteLine(L"The square of 4 is {0}", Squareof4);

    MessageBox(0, L"Hello World!", L"A Message Box", 0);

    return 0;
}
