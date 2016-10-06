using namespace System;

#pragma unmanaged

int UMadd(int a, int b)
{
    return a + b;
}

#pragma managed

int Madd(int a, int b)
{
    return a + b;
}

void main()
{
    Console::WriteLine("Unmanaged Add 2 + 2: {0}", UMadd(2, 2));
    Console::WriteLine("Managed   Add 3 + 3: {0}",  Madd(3, 3));
}
