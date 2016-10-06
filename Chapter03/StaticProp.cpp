using namespace System;

ref class StaticProp
{
    static String^ name;

public:
    property static String^ Name
    {
        void set(String^ value)
        {
            name = value;
        }
        String^ get()
        {
            return name;
        }
    }
};

int main()
{
    StaticProp::Name = "Static Property";

    Console::WriteLine(StaticProp::Name);
}