using namespace System;

ref class RefClass 
{
public:
    int X;

    RefClass(int x)
    {
        X = x;
    }
};

// Reference and Indirection in Action
void main()
{
    RefClass rc(10);
    RefClass ^o;
    
    o = %rc;	               // place a reference of rc in the handle o
    Console::WriteLine(o->X); // print out object. This should contain 10.

    rc.X = 20;                // place 50 at the address y points to
    Console::WriteLine(o->X); // print out object. This should contain 20.

    int %i = rc.X;            // assign rc.X to a reference

    i = 30;                   // change value of reference
    Console::WriteLine(o->X); // print out object. This should contain 30.

    Console::WriteLine();

    int ^y = gcnew int(100);  // create a handle to an int
    Console::WriteLine(y);    // print out int.

    *y = 110;                 // Assign new value to dereferenced int
    Console::WriteLine(*y);   // print out dereferenced int.
}
