using namespace System;

ref class OpClass 
{
public:
    OpClass() : i(0) {}
    OpClass(int x) : i(x) {}

    // x != y
    static bool operator !=(const OpClass ^lhs, const OpClass ^rhs)
    {
        return lhs->i != rhs->i;
    }

    // x * y
    static OpClass^ operator *(const OpClass ^lhs, const OpClass ^rhs)
    {
        OpClass^ ret = gcnew OpClass();
        ret->i = lhs->i * rhs->i;

        return ret;
    }

    // x *= y
    static void operator *=(OpClass ^lhs, const OpClass ^rhs)
    {
        lhs->i *= rhs->i;
    }

    // -x
    static OpClass^ operator -(const OpClass ^lhs)
    {
        OpClass^ ret = gcnew OpClass();
        ret->i = -(lhs->i);

        return ret;
    }

    // ++x and x++
    static OpClass^ operator ++(const OpClass ^lhs)
    {
        OpClass^ ret = gcnew OpClass();
        ret->i = (lhs->i) + 1;
                     
        return ret;  
    }

    virtual String ^ ToString() override
    {
        return i.ToString();
    }

private:
    int i;
};

void main()
{
    OpClass ^op1 = gcnew OpClass(3);
    OpClass ^op2 = gcnew OpClass(5);
    OpClass ^op3 = gcnew OpClass(15);

   if ( op1 * op2 != op3)
       Console::WriteLine("Don't Equal");
   else
       Console::WriteLine("Equal");

    op1 *= op2;
    Console::WriteLine(op1);

    Console::WriteLine(++op1);  // prints 15 then increments to 16
    Console::WriteLine(op1++);  // increOpClassents to 17 then prints

    Console::WriteLine(-op1);   // Negation of OpClass1
    Console::WriteLine(op1);    // prior Negation op left OpClass1 unchanged
}
