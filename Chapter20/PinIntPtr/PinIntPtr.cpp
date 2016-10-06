using namespace System;

value class Test 
{
public:
    int i; 
};

#pragma unmanaged

void incr (int *i)
{
    (*i) += 10;
}

#pragma managed

void main () 
{
    Test ^test = gcnew Test();
    interior_ptr<int> ip = &test->i;
    (*ip) = 5;

//  incr( ip );            // invalid 

    pin_ptr<int> i = ip;   // i is a pinned int pointer

    incr( i );             // pinned pointer to interior pointer passed to a
                           // native function call expecting a native pointer
                                
    Console::WriteLine ( test->i );
}
