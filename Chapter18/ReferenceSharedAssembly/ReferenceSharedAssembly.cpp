using namespace System;
using namespace SharedAssembly;

void main()
{
    SharedClass ^sa = gcnew SharedClass();
    Console::WriteLine(sa->Version);
}
