using namespace System;

ref class Numbers 
{
public:
    Numbers()
    {
        defaultArray = gcnew array<String^> 
        { 
            "zero", "one", "two", "three", "four", "five" 
        };
    }

    property String^ default [int]
    {
        String^ get(int index)
        {
            if (index < 0)
                index = 0;
            else if (index > defaultArray->Length)
                index = defaultArray->Length - 1;

            return defaultArray[index];
        }
    }
private:
     array<String^>^ defaultArray;
};

void main() 
{
    Numbers numbers;

    Console::WriteLine(numbers[-1]);
    Console::WriteLine(numbers[3]);
    Console::WriteLine(numbers[10]);
}