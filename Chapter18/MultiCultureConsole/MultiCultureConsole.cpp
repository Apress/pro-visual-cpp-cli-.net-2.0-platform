using namespace System;
using namespace System::Reflection;
using namespace System::Resources;
using namespace System::Threading;
using namespace System::Globalization;

void main()
{
    Assembly ^assembly = Assembly::GetExecutingAssembly();
    ResourceManager ^rmgr = 
        gcnew ResourceManager("MulticultureConsole.Colors", assembly);

    Console::WriteLine(rmgr->GetObject("Color1"));
    Console::WriteLine(rmgr->GetObject("Color2"));
    Console::WriteLine(rmgr->GetObject("Color3"));
    Console::WriteLine(rmgr->GetObject("Color4"));

    Thread::CurrentThread->CurrentUICulture = gcnew CultureInfo("fr-fr");

    Console::WriteLine(rmgr->GetObject("Color1"));
    Console::WriteLine(rmgr->GetObject("Color2"));
    Console::WriteLine(rmgr->GetObject("Color3"));
    Console::WriteLine(rmgr->GetObject("Color4"));
}