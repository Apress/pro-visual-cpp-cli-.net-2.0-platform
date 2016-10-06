// LateBindCOM.cpp : main project file.

#include "stdafx.h"

using namespace System;
using namespace System::Reflection;

int main(array<System::String ^> ^args)
{
    Type ^typeTestCom = Type::GetTypeFromProgID(L"CTestCOM.CTestCOM");

    if (typeTestCom == nullptr)
    {
        Console::WriteLine("Getting CTestCOM.CTestCOM failed");
        return -1;
    }

    try
    {
        Object ^TestComLBnd = Activator::CreateInstance(typeTestCom);

        array<Object^>^ param = gcnew array<Object^> { 4 };

        Object ^ret = typeTestCom->InvokeMember(
            L"Square", 
            Reflection::BindingFlags::InvokeMethod, 
            nullptr, 
            TestComLBnd, 
            param);

        Console::WriteLine("Square of 4 is {0}", ret);
    }
    catch (Exception ^ex)
    {
        Console::WriteLine("Error when invoking Square method: {0}", 
                           ex->Message); 
    }
    return 0;
}
