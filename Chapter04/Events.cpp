using namespace System;

delegate void SayHandler(String ^name);

ref class EventSource
{
public:
    event SayHandler^ OnSay;

    void Say(String ^name)
    {
        OnSay(name);
    }
};

ref class EventReceiver1
{
    EventSource ^source;
public:

    EventReceiver1(EventSource ^src)
    {
        if (src == nullptr)
            throw gcnew ArgumentNullException("Must pass an Event Source");

        source = src;

        source->OnSay += gcnew SayHandler(this, &EventReceiver1::SayHello);
        source->OnSay += gcnew SayHandler(this, &EventReceiver1::SayStuff);
    }

    void RemoveStuff()
    {
        source->OnSay -= gcnew SayHandler(this, &EventReceiver1::SayStuff);
    }

    void SayHello(String ^name)
    {
        Console::Write("Hello there ");
        Console::WriteLine(name);
    }

    void SayStuff(String ^name)
    {
        Console::Write("Nice weather we are having. Right, ");
        Console::Write(name);
        Console::WriteLine("?");
    }
};

ref class EventReceiver2
{
    EventSource ^source;
public:

    EventReceiver2(EventSource ^src)
    {
        if (src == nullptr)
            throw gcnew ArgumentNullException("Must pass an Event Source");

        source = src;

        source->OnSay += gcnew SayHandler(this, &EventReceiver2::SayBye);
    }

    void SayBye(String ^name)
    {
        Console::Write("Good-bye ");
        Console::WriteLine(name);
    }
};

void main()
{
    EventSource ^source = gcnew EventSource();

    EventReceiver1 ^receiver1 = gcnew EventReceiver1(source);
    EventReceiver2 ^receiver2 = gcnew EventReceiver2(source);

    source->Say("Mr Fraser");

    Console::WriteLine("-------------------------------");

    receiver1->RemoveStuff();

    source->Say("Stephen");
}