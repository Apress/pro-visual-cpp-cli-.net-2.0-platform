using namespace System;

/// <summary> Base class </summary>
ref class Square
{
public:
    int Area()
    {
        return Dims * Dims;
    }

    int Dims;
};

/// <summary> Child class </summary>
ref class Cube : public Square
{
public:
    int Volume()
    {
        return Area() * Dims;
    }
};

/// <summary> Inheritance in action </summary>
void main()
{
    Cube ^cube = gcnew Cube(); 
    cube->Dims = 3;

    Console::WriteLine(cube->Dims); 
    Console::WriteLine(cube->Area());
    Console::WriteLine(cube->Volume());
}
