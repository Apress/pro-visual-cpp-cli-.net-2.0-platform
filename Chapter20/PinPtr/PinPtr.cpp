#include <stdio.h>

using namespace System;

ref class RTest 
{
public:
    int i; 
    RTest() 
    { 
        i = 0; 
    }
};

value class VTest 
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

void incr (VTest *t)
{
    t->i += 20;
}



void main () 
{
    RTest ^rtest = gcnew RTest();   // rtest is a reference type

    pin_ptr<int> i = &(rtest->i);   // i is a pinned int pointer

    incr( i );                      // pointer to managed data passed as 
                                    // parameter of unmanaged function call
    
    Console::WriteLine ( rtest->i );


    VTest ^vtest = gcnew VTest;     // vtest is a boxed value type
    vtest->i = 0;

    pin_ptr<VTest> ptest = &*vtest; // ptest is a pinned value type.
                                    // the &* says give the address of the 
                                    // inderection of vtest

    incr( ptest );                  // pointer to value type passed as 
                                    // parameter of unmanaged function call

    Console::WriteLine ( vtest->i );


    array<Byte>^ arr = gcnew array<Byte> {'M', 'C', '+', '+'};
 
    pin_ptr<Byte> p = &arr[1];  // ENTIRE array is pinned
    unsigned char *cp = p;
    printf("%s\n", --cp);       // cp bytes will not move during call
                                // notice the negative pointer arithmetic
                                // into the array.
}
