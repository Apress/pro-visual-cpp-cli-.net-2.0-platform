using namespace System;

// Passing parameters to main()
int main ( int argc, char *argv[] )
{
    Console::WriteLine ( argc.ToString() );
    for (int i = 0; i < argc; i++)
    {
        Console::WriteLine ( gcnew String(argv[i]) );
    }
    return 0;
}
