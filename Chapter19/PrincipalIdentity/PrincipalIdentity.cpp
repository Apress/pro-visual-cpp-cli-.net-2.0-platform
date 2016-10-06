// PrincipalIdentity.cpp : main project file.

#include "stdafx.h"

using namespace System;
using namespace System::Security;
using namespace System::Security::Principal;
using namespace System::Threading;

void main()
{
    // set policy from UnauthenticatedPrincipal to WindowsPrincipal
    AppDomain::CurrentDomain->SetPrincipalPolicy(
                                            PrincipalPolicy::WindowsPrincipal);

    // ----------------------------------------------------------------------
    // Get Windows Principal and Identity
    // ----------------------------------------------------------------------

    Console::WriteLine("Windows Principal & Identity");
    Console::WriteLine("----------------------------");
 
    WindowsPrincipal ^wPrinc = (WindowsPrincipal^)Thread::CurrentPrincipal;

    Console::WriteLine("Is an Administrator?: {0}", 
                       wPrinc->IsInRole(WindowsBuiltInRole::Administrator));
    Console::WriteLine("Is a Hacker?: {0}", wPrinc->IsInRole("Hacker"));

    WindowsIdentity ^wIdent = (WindowsIdentity^)wPrinc->Identity;

    Console::WriteLine("\nWindows Login Name: {0}", wIdent->Name);
    Console::WriteLine("Authentication Type: {0}", wIdent->AuthenticationType);
    Console::WriteLine("Is Authenticated: {0}", wIdent->IsAuthenticated);
    Console::WriteLine("Is System Account: {0}", wIdent->IsSystem);

    // ----------------------------------------------------------------------
    // Create (Hacker) Principal and Identity
    // ----------------------------------------------------------------------

    Console::WriteLine("\n\nGeneric Principal & Identity");
    Console::WriteLine("----------------------------");
 
    array<String^>^ rolesArray = {"Hacker"};

    // Set the principal to a new generic principal.
    Thread::CurrentPrincipal = 
        gcnew GenericPrincipal(gcnew GenericIdentity("John Doe"), rolesArray);
 
    GenericPrincipal ^gPrinc = (GenericPrincipal^)Thread::CurrentPrincipal;

    Console::WriteLine("Is an Administrator?: {0}", 
                       gPrinc->IsInRole("BUILTIN\\Administrator"));
    Console::WriteLine("Is a Hacker?: {0}", gPrinc->IsInRole("Hacker"));

    GenericIdentity ^gIdent = (GenericIdentity^)gPrinc->Identity;

    Console::WriteLine("\nUser Name: {0}", gIdent->Name);
    Console::WriteLine("Is Authenticated: {0}\n", gIdent->IsAuthenticated);
}
