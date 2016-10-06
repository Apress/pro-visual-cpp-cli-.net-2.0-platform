// RoleBasedSecurity.cpp : main project file.

#include "stdafx.h"

using namespace System;
using namespace System::Security;
using namespace System::Security::Principal;
using namespace System::Security::Permissions;
using namespace System::Threading;

[PrincipalPermissionAttribute(SecurityAction::Demand, Role = "NotAHacker")]
void DeclarativeSecurity()
{
    Console::WriteLine("I'm in the Declarative Security Function");
}

void DemandSecurity()
{
    (gcnew PrincipalPermission(nullptr, "NotAHacker"))->Demand();

    Console::WriteLine("I'm in the Demand Security Function\n");
}

void main()
{
    try
    {
        DeclarativeSecurity();
 
    }
    catch (SecurityException^)
    {
        Console::WriteLine("SECURITY ERROR in Declarative Security Function");
    }

    try
    {
        DemandSecurity();
    }
    catch (SecurityException^)
    {
        Console::WriteLine("SECURITY ERROR in Demand Security Function\n");
    }

    Console::WriteLine("Set CurrentPrincipal to John with role of NotAHacker");
    array<String^>^ rolesArray = {"NotAHacker"};
    Thread::CurrentPrincipal = gcnew GenericPrincipal( 
                                         gcnew GenericIdentity( "John" ), 
                                         rolesArray );
    try
    {
        DeclarativeSecurity();
    }
    catch (SecurityException^)
    {
        Console::WriteLine("SECURITY ERROR in Declarative Security Function");
    }

    try
    {
        DemandSecurity();
    }
    catch (SecurityException^)
    {
        Console::WriteLine("SECURITY ERROR in Demand Security Function");
    }
}
