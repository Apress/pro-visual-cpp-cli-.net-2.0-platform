using namespace System;

// Parent Class
ref class ParentClass
{
public:
    // Default constructor that initializes ParentVal to a default value
    ParentClass() : PVal(10) {}

    // A constructor that initializes ParentVal to a passed value
    ParentClass(int inVal) : PVal(inVal) {}

    // Copy Constructor
    ParentClass(const ParentClass %p) : PVal(p.PVal) {}

    int PVal;
};

// ---------------------------------------------------------------

// Child class that inherits form ParentClass
ref class ChildClass : public ParentClass
{
public:
    // Default constructor that initializes ChildVal to a default value
    ChildClass () : CVal(20) {};    // default constructor

    // A constructor that initialized the parent class with a passed value
    // and initializes ChildVal to a another passed value
    ChildClass (int inVal1, int inVal2) : ParentClass(inVal1), CVal(inVal2) {}

    ChildClass(const ChildClass %vals) : ParentClass(vals.PVal), CVal(vals.CVal) {}

    int CVal;
};

void main()
{
    ParentClass p1(4);    // Constructor
    ParentClass p2 = p1;  // Copy Constructor

    p1.PVal = 2;          // Change original, new unchanged

    Console::WriteLine("p1.PVal=[{0}] p2.PVal=[{1}]", p1.PVal, p2.PVal);

    ChildClass ^c1 = gcnew ChildClass(5,6); // Constructor
    ChildClass  c2 = *c1;                   // Copy Constructor

    c1->CVal = 12;        // Change original, new unchanged

    Console::WriteLine("c1=[{0}/{1}] c2=[{2}/{3}]", 
        c1->PVal, c1->CVal, c2.PVal, c2.CVal);
}
