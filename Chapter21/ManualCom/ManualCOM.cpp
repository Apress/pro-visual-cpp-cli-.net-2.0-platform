// Compile from command line using
// cl /clr:safe ManualCOM 

#using <TestCom.dll>

using namespace System;
using namespace TestCOM;

int main(array<System::String ^> ^args)
{
    CTestCOMClass^ test = gcnew CTestCOMClass();

    long ret = test->Square(4);

    Console::WriteLine("The Square of 4 is {0}", ret);
    return 0;
}
