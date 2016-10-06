using namespace System;

interface class Interface1
{
    void Method1();
    void Method2();
};

interface class Interface2
{
    void Method3();
    property String^ X;
};

ref class Base
{
public:
    void MethodBase()
    {
        Console::WriteLine("MethodBase()");
    }
};

ref class DerivedClass : public Base, public Interface1, public Interface2
{
public:
    virtual property String^ X
    {
        String^ get()
        {
            return x;
        }
    
        void  set(String^ value)
        {
            x = value;
        }
    }

    virtual void Method1()
    {
        Console::WriteLine("Method1()");
    }

    virtual void Method2()
    {
        Console::WriteLine("Method2()");
    }

    virtual void Method3()
    {
        Console::WriteLine("Method3()");
    }

    virtual void Print()
    {
        MethodBase();
        Method1();
        Method2();
        Method3();
    }

private:
    String^ x;
};

void main()
{
    DerivedClass dc;

    dc.X = "Start'n Up";
    Console::WriteLine(dc.X);

    dc.Print();
}
