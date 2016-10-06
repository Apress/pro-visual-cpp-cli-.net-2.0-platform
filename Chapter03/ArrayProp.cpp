using namespace System;

ref class ArrayProp
{
public:
    ArrayProp(int size)
    {
        numArray = gcnew array<int>(size);
    }

    property array<int>^ NumArray
    {
        array<int>^ get() 
        {
            return numArray;
        }

        void set ( array<int>^ value )
        {
            numArray = value;
        }
    }
private:
    array<int>^ numArray;
};

void main() 
{
    ArrayProp aprop(5);

    for ( int i = 0 ; i < aprop.NumArray->Length ; ++i )
        aprop.NumArray[i] = i;

    for each (int i in aprop.NumArray)
        Console::WriteLine(i);
}
