// SimplePInvoke.cpp : main project file.

#include "stdafx.h"

using namespace System;
using namespace System::Text;
using namespace System::Runtime::InteropServices;

[DllImportAttribute("C:\\Chapter21\\Debug\\NativeCode.dll", 
                    CallingConvention=CallingConvention::StdCall)]
extern "C" long square(long value);

[DllImport("User32.dll", CharSet=CharSet::Auto, 
           CallingConvention=CallingConvention::StdCall)]
extern "C" int MessageBox(int hWnd, String^ text, String^ caption,
                          unsigned int type);

[DllImport("msvcr70", CharSet=CharSet::Ansi)]
extern "C" int strcpy([MarshalAs(UnmanagedType::LPStr)] StringBuilder^ dest,
                      [MarshalAs(UnmanagedType::LPStr)] String^ source);

int main(array<System::String ^> ^args)
{
    long Squareof4 = square(4);

    Console::WriteLine(L"The square of 4 is {0}", Squareof4);

    MessageBox(0, L"Hello World!", L"A Message Box", 0);

    StringBuilder^ dest = gcnew StringBuilder();
    String^ source = "Hello";
    strcpy(dest, source);
    Console::WriteLine(dest);

    return 0;
}

