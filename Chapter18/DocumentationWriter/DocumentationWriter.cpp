// DocumentationWriter.cpp : main project file.

#include "stdafx.h"

using namespace System;
using namespace Reflection;
using namespace Documentation;

void DisplayDescription(Attribute ^attr)
{
    if (attr !=  nullptr)
    {
        DescriptionAttribute ^cd = (DescriptionAttribute^)attr;
        Console::WriteLine("  Author: {0}  --  Compiled: {1}", 
            cd->Author, cd->CompileDate);
        Console::WriteLine("  Description: {0}", cd->Description);
        Console::WriteLine("    ---- Change History ----");
    }
    else
        Console::WriteLine("    No Documentation");
}

void DisplayHistory(array<Object^>^ attr)
{
    if (attr->Length > 0)
    {
        for each (HistoryAttribute^ cd in attr)
        {
            Console::WriteLine("    Author: {0}  --  Modified: {1}", 
                cd->Author, cd->ModifyDate);
            Console::WriteLine("    Description: {0}", cd->Description);
        }
    }
    else
        Console::WriteLine("    No changes");
}

void DisplayAttributes(MemberInfo ^info)
{
    DisplayDescription(Attribute::GetCustomAttribute(info, DescriptionAttribute::typeid));
    DisplayHistory(info->GetCustomAttributes(HistoryAttribute::typeid, true));
}

void PrintClassInfo(Type ^type)
{
    Console::WriteLine("Class: {0}", type->ToString());
    DisplayAttributes(type);
 
    array<ConstructorInfo^>^ constructors = type->GetConstructors();
    for (int i = 0; i < constructors->Length; i++)
    {
        Console::WriteLine("Constructor: {0}", constructors[i]->ToString());
        DisplayAttributes(constructors[i]);
    }

    array <MethodInfo^>^ methods = type->GetMethods((BindingFlags)
      (BindingFlags::Public|BindingFlags::Instance|BindingFlags::DeclaredOnly));
    for (int i = 0; i < methods->Length; i++)
    {
        Console::WriteLine("Method: {0}", methods[i]->ToString());
        DisplayAttributes(methods[i]);
    }

    array<PropertyInfo^>^ properties = type->GetProperties((BindingFlags)
      (BindingFlags::Public|BindingFlags::Instance|BindingFlags::DeclaredOnly));
    for (int i = 0; i < properties->Length; i++)
    {
        Console::WriteLine("Property: {0}", properties[i]->ToString());
        DisplayAttributes(properties[i]);
    }
}

int main(array<System::String ^> ^args)
{
    try
    {
        Assembly ^assembly = Assembly::LoadFrom(args[0]);

        array<Type^>^ types = assembly->GetTypes();

        for (int i = 0; i < types->Length; i++)
        {
            PrintClassInfo(types[i]);
            Console::WriteLine();
        }
    }
    catch(System::IO::FileNotFoundException^)
    {
        Console::WriteLine("Can't find assembly: {0}\n", args[0]);
    }
}
