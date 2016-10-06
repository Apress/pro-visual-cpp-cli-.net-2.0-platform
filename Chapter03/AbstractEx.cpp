using namespace System;

 ref class AbstractExClass abstract
{
protected:
    int AbstractVar;
    AbstractExClass(int val): AbstractVar(val) {}
public:
    virtual void Method1() = 0;  // unimplemented method
    virtual void Method2() = 0;  // unimplemented method
    void Method3()
    {
        Console::WriteLine(AbstractVar.ToString());
    }
};

ref class MidAbstractExClass abstract : public AbstractExClass
{
public:
    virtual void Method1() override sealed
    {
        Console::WriteLine((AbstractVar * 3).ToString());
    }
protected:
    MidAbstractExClass(int val) : AbstractExClass(val) {}
};

ref class DerivedExClass : public MidAbstractExClass
{
public:
    DerivedExClass(int val) : MidAbstractExClass(val) {}
    virtual void Method2() override
    {
        Console::WriteLine((AbstractVar * 2).ToString());
    }
};

void testMethod(AbstractExClass ^aec)
{
    aec->Method1();
    aec->Method2();
    aec->Method3();
}

void main()
{
    AbstractExClass ^Ab1 = gcnew DerivedExClass(5);
    Ab1->Method1();
    Ab1->Method2();
    Ab1->Method3();

    AbstractExClass ^Ab2 = gcnew DerivedExClass(6);
    testMethod(Ab2);

    DerivedExClass ^dc = gcnew DerivedExClass(7);
    testMethod(dc);
}
