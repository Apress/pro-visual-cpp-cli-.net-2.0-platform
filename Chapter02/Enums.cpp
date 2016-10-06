using namespace System;

enum class PrimeColors { Red, Blue, Yellow };

// Enum Type in Action
void main()
{
    PrimeColors color;

    color = PrimeColors::Blue;

    switch (color)
    {
        case PrimeColors::Red :
            Console::WriteLine("Red");
            break;
        case PrimeColors::Blue :
            Console::WriteLine("Blue");
            break;
        case PrimeColors::Yellow :
            Console::WriteLine("Yellow");
            break;
    }

    Console::WriteLine(color.ToString());
}
