using namespace System;

class       ClassMember  {};
ref class   RefClassMember {};
value class ValueClassMember {};

class Class
{
public:
//  RefClassMember    rc;     // can't embed instance ref class        
//  RefClassMember   ^hrc;    // can't embed handle to ref class
    ValueClassMember  vc;      
//  ValueClassMember ^hvc;    // can't embed managed value class
    ValueClassMember *pvc;
    ClassMember       c;
    ClassMember      *pc;

    int x;
    void write() { Console::WriteLine("Class x: {0}", x); }
};

ref class RefClass
{
public:
    RefClassMember    rc;
    RefClassMember   ^hrc;
    ValueClassMember  vc;
    ValueClassMember ^hvc;
    ValueClassMember *pvc;
//  ClassMember       c;      // can't embed instance of class
    ClassMember      *pc;

    int x;
    void write() { Console::WriteLine("RefClass x: {0}", x); }
};

value class ValueClass
{
public:
//  RefClassMember    rc;     // can't embed instance ref class        
    RefClassMember   ^hrc;
    ValueClassMember  vc;
    ValueClassMember ^hvc;
    ValueClassMember *pvc;
//  ClassMember       c;      // can't embed instance of class
    ClassMember      *pc;

    int x;
    void write() { Console::WriteLine("ValueClass x: {0}", x); }
};

class ClassChildClassParent : public Class {};                         // OK
//class ClassChildRefClassParent : public RefClass {};                 // Error
//class ClassChildValueClassParent : public ValueClass {};             // Error

//ref class RefClassChildClassParent : public Class {};                // Error
ref class RefClassChildRefClassParent : public RefClass {};            // OK
//ref class RefClassChildValueClassParent : public ValueClass {};      // Error

//value class ValueClassChildClassParent : public Class {};            // Error
//value class ValueClassChildRefClassParent : public RefClass {};      // Error
//value class ValueClassChildValueClassParent : public ValueClass {};  // Error

void main()
{
    // Stack
    Class      _class;
    RefClass   refclass;                             // Not really on the stack
    ValueClass valueclass;

    // Handle
//  Class      ^hclass       = gcnew Class();        // Not allowed
    RefClass   ^hrefclass    = gcnew RefClass();
    ValueClass ^hvalueclass  = gcnew ValueClass();

    // Pointer
    Class      *pclass       = new Class();
//  RefClass   *prefclass    = new RefClass();       // Not allowed
    ValueClass *pvalueclass  = &valueclass;

    // Reference
    Class      &rfclass      = *new Class();
//  RefClass   &rfrefclass   = *gcnew RefClass();   // Not allowed
    ValueClass &rfvalueclass = valueclass;

    _class.x       = 1;
    refclass.x     = 2;
    valueclass.x   = 3;
    hrefclass->x   = 4;
    hvalueclass->x = 5;
    pclass->x      = 6;
    pvalueclass->x = 7;
    rfclass.x      = 8;
    rfvalueclass.x = 9;

    _class.write();         // prints 1
    refclass.write();       // prints 2
    valueclass.write();     // prints 9
    hrefclass->write();     // prints 4
    hvalueclass->write();   // prints 5
    pclass->write();        // prints 6
    pvalueclass->write();   // prints 9
    rfclass.write();        // prints 8
    rfvalueclass.write();   // prints 9
}
