using namespace System;
using namespace System::Security;
using namespace System::Security::Permissions;
using namespace System::Security::Policy;

void main()
{
    // Create a new permission set
    PermissionSet^ permSet = gcnew PermissionSet(PermissionState::None);
      
    // Add permissions to the permission set.
    permSet->AddPermission(
        gcnew SecurityPermission(PermissionState::Unrestricted));
    permSet->AddPermission(gcnew UIPermission(PermissionState::Unrestricted));
    permSet->AddPermission(gcnew FileIOPermission(FileIOPermissionAccess::Read, 
                                                  "C:\\"));

    // Create Policy Statement
    PolicyStatement^ policy = gcnew PolicyStatement(permSet);

    // Create Membership condition
    IMembershipCondition^ membership = 
        gcnew UrlMembershipCondition("http://192.168.1.102/Chapter19/*");

    // Create Code group
    CodeGroup^ codeGroup = gcnew UnionCodeGroup(membership, policy);
    codeGroup->Description = "C:\\ ReadOnly permission for Application URL";
    codeGroup->Name = "ReadOnly Secure Group";

    // Find the machine policy level
    System::Collections::IEnumerator^ ph = SecurityManager::PolicyHierarchy();

    while( ph->MoveNext() ) 
    {
        PolicyLevel^ pl = (PolicyLevel^)ph->Current;
        if( pl->Label == "Machine" ) 
        {
            // Add code group to Machine policy
            pl->RootCodeGroup->AddChild(codeGroup);
            break;
        }
    }
    // Save changes
    SecurityManager::SavePolicy();

    Console::WriteLine("Added C:\\ ReadOnly Secure Group");
}
