// SimpleCOM.cpp : main project file.

#include "stdafx.h"

using namespace System;
using namespace TestCOM;


int main(array<System::String ^> ^args)
{
    CTestCOMClass^ test = gcnew CTestCOMClass();

    try
    {
        long ret = test->Square(4);

        Console::WriteLine("The Square of 4 is {0}", ret);
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("Oops an exception occurred: {0}", ex->Message);
    }

	Console::WriteLine(System::Runtime::InteropServices::Marshal::ReleaseComObject(test));

    return 0;
}
