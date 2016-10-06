using namespace System;

// Passing parameters to main() new method
int main(array<System::String ^> ^args)
{
    Console::WriteLine(args->Length);
	
    for each (String^ s in args)
    {
        Console::WriteLine(s);
    }
    return 0;
}

