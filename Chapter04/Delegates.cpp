using namespace System;

/// <summary>A Delegate that talks a lot</summary>
delegate void SayDelegate(String ^name);

/// <summary>A friendly function</summary>
void SayHello(String ^name)
{
    Console::Write("Hello there ");
    Console::WriteLine(name);
}

/// <summary>A talkative class</summary>
ref class Talkative
{
public:
    static void SayHi(String ^name);
    void SayStuff(String ^name);
    void SayBye(String ^name);
};

void Talkative::SayHi(System::String ^name)
{
    Console::Write("Hi there ");
    Console::WriteLine(name);
}

void Talkative::SayStuff(System::String ^name)
{
    Console::Write("Nice weather we are having. Right, ");
    Console::Write(name);
    Console::WriteLine("?");
}

void Talkative::SayBye(System::String ^name)
{
    Console::Write("Good-bye ");
    Console::WriteLine(name);
}

/// <summary>Delegates in action</summary>
void main()
{
    SayDelegate^ say;

    // Global Function
    say = gcnew SayDelegate(&SayHello);

    // add Static member function
    say += gcnew SayDelegate(&Talkative::SayHi);

    Talkative ^computer = gcnew Talkative();

    // add instance member functions
    say = say + gcnew SayDelegate(computer, &Talkative::SayStuff);
    say += gcnew SayDelegate(computer, &Talkative::SayBye);

    // invoke delegate
    say->Invoke("Stephen");

    Console::WriteLine("-------------------------------");

    // remove a couple of methods
    say = say - gcnew SayDelegate(&Talkative::SayHi);
    say -= gcnew SayDelegate(computer, &Talkative::SayBye);

    // invoke delegate again with two fewer methods
    say("Stephen");
}