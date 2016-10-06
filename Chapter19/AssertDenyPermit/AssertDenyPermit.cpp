// AssertDenyPermit.cpp : main project file.

#include "stdafx.h"

using namespace System;
using namespace System::IO;
using namespace System::Security;
using namespace System::Security::Permissions;

void AssertRead()
{
    CodeAccessPermission ^permission =
        gcnew FileIOPermission(FileIOPermissionAccess::Read, "C:\\");

    permission->Assert();
    StreamReader ^sr = File::OpenText("C:\\TestFile.txt");
    String ^s = sr->ReadLine();
    sr->Close();
    permission->RevertAssert();
    Console::WriteLine("Successful Read");
}

void NoAssertRead()
{
    StreamReader ^sr = File::OpenText("C:\\TestFile.txt");
    String ^s = sr->ReadLine();
    sr->Close();
    Console::WriteLine("Successful Read");
}

void main()
{
    // Deny Reading C:
    CodeAccessPermission ^permissionRead =
        gcnew FileIOPermission(FileIOPermissionAccess::Read, "C:\\");

    permissionRead->Deny();
    try
    {
        AssertRead();
        NoAssertRead();
    }
    catch(SecurityException^)
    {
        Console::WriteLine("Failed To Read");
    }
    permissionRead->RevertDeny();

    // Only allow Writing to C:
    CodeAccessPermission ^permissionWrite =
        gcnew FileIOPermission(FileIOPermissionAccess::Write, "C:\\");

    permissionWrite->PermitOnly();
    try
    {
        AssertRead();
        NoAssertRead();
    }
    catch(SecurityException^)
    {
        Console::WriteLine("Failed To Read\n");
    }
    permissionWrite->RevertPermitOnly();
}
