using namespace System;

ref class ScalarProp
{
public:
    // Constructor
    ScalarProp()
    {
        Cost        = 0.0;
        number      = 0;
        name        = "Blank Name";
        description = "Scalar Property";
    }

    // trivial property
    property double Cost;

    // Read & write with validated parameter
    property int Number
    {
        void set(int value)
        {
            if (value < 1)
                value = 1;
            else if (value > 10)
                value = 10;
            
            number = value;
        }

        int get()
        {
            return number;
        }
    }

    // Write only property
    property String^ Name
    {
        void set(String^ value)
        {
            name = value;
        }
    }

    // Ready only property
    property String ^Description
    {
        String^ get()
        {
            return String::Concat(name, " ", description);
        }
    }

private:
    String ^name;
    String ^description;
    int     number;
};


void main()
{
    ScalarProp sp;

    sp.Name = "The Ref Class";

    Console::WriteLine(sp.Description);

    sp.Cost = 123.45;
    Console::WriteLine(sp.Cost);

    sp.Number = 20;    // Will be changed to 10
    Console::WriteLine(sp.Number);

    sp.Number = -5;    // Will be changed to 1
    Console::WriteLine(sp.Number);

    sp.Number = 6;    // Will not change
    Console::WriteLine(sp.Number);
}