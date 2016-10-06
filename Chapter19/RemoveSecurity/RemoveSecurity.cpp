using namespace System;
using namespace System::Security;
using namespace System::Security::Permissions;
using namespace System::Security::Policy;

void main()
{
    CodeGroup^ machine;

    // Iterate through policy hierarchy to get Machine Code group
    System::Collections::IEnumerator^ ph = SecurityManager::PolicyHierarchy();
    while( ph->MoveNext() ) 
    {
        PolicyLevel^ machinePolicyLevel = (PolicyLevel^)ph->Current;
        if (machinePolicyLevel->Label == "Machine") 
        {
            machine = machinePolicyLevel->RootCodeGroup;
            break;
        }
    }

    // Iterate backwards removing all instance of “ReadOnly Secure Group” 
    for (int i = machine->Children->Count - 1; i >= 0; i--)
    {
        if(((CodeGroup^)machine->Children[i])->Name == "ReadOnly Secure Group")
        {
            machine->RemoveChild(((CodeGroup^)machine->Children[i]));
        }
    }

    // Save changes
    SecurityManager::SavePolicy();

    Console::WriteLine("Removed C:\\ File ReadOnly Secure Group");
}
