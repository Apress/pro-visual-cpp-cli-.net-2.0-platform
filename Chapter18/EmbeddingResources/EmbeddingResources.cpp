using namespace System;
using namespace System::Collections;
using namespace System::Reflection;
using namespace System::Resources;

void main()
{
    Console::WriteLine("*** ResourceReader ***");
    ResourceReader ^rreader = gcnew ResourceReader("Fruit.resources");
    IDictionaryEnumerator ^denum = rreader->GetEnumerator();
    while (denum->MoveNext())
    {
        Console::WriteLine("{0} = {1}", denum->Key, denum->Value);
    }
    rreader->Close();

    ResourceManager ^rmgr;
    
    Console::WriteLine("\n*** ResourceManager From File ***");
    rmgr = ResourceManager::CreateFileBasedResourceManager("Fruit", "", nullptr);
    Console::WriteLine(rmgr->GetString("Fruit1"));
    Console::WriteLine(rmgr->GetString("Fruit2"));
    Console::WriteLine(rmgr->GetString("Fruit3"));
    Console::WriteLine(rmgr->GetString("Fruit4"));

    Console::WriteLine("\n*** ResourceManager From Assembly ***");
    Assembly ^assembly = Assembly::GetExecutingAssembly();
    rmgr = gcnew ResourceManager("Fruit", assembly);
    Console::WriteLine(rmgr->GetObject("Fruit1"));
    Console::WriteLine(rmgr->GetObject("Fruit2"));
    Console::WriteLine(rmgr->GetObject("Fruit3"));
    Console::WriteLine(rmgr->GetObject("Fruit4"));
}
