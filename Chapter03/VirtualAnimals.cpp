using namespace System;

ref class Animal
{
public:
    virtual void Speak ()
    {
        Console::WriteLine("Animal is Mysteriously Silent");
    }
};

ref class Dog : public Animal
{
public:
    // Standard explicit virtual override
    virtual void Speak() override
    {
        Console::WriteLine("Dog says Woof");
    }
};

ref class Puppy : public Dog
{
public:
    // Yip name overrides dog's virtual speak
    virtual void Yip() = Dog::Speak   // should be just: = Speak
    {
        Console::WriteLine("Puppy says Yip Yip");
    }
};

ref class Cat : public Animal
{
public:
    // Start a new speak virtual sequence so animal's virtual speak fails
    virtual void Speak() new
    {
        Console::WriteLine("Cat says Meow");
    }
};

ref class Tiger : public Cat
{
public:
    // Though inherited from cat, Tiger name overrides Animal's speak
    // thus, can speak though animal virtual sequence
	// also this method overrides Cat’s virtual Speak method as well
	virtual void Growl() = Animal::Speak, Cat::Speak
    {
        Console::WriteLine("Tiger says Grrrr");
    }
};

void main()
{
    // Array of Animal handles
    array<Animal^>^ animals = gcnew array<Animal^> 
    { 
        gcnew Animal(), 
        gcnew Dog(), 
        gcnew Puppy(),
        gcnew Cat(), 
        gcnew Tiger() 
   };

    for each ( Animal ^a in animals)
    {
        a->Speak();
    }

    Console::WriteLine();

    Animal^ cat1 = gcnew Cat();
    Cat^  cat2   = gcnew Cat();
    Cat^  tiger  = gcnew Tiger();

    // new cancels virtual sequence of Animal
    cat1->Speak();

    // new speak sequence established for cat
    cat2->Speak();
    tiger->Speak();
}
