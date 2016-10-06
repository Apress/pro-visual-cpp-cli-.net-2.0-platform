using namespace System;
using namespace System::Threading;

ref class MyThread
{
public:
    static void StaticThread();
    void NonStaticThread(Object ^name);
};

void MyThread::StaticThread()
{
    for (int i = 0; i < 50000001; i++)
    {
        if (i % 10000000 == 0)
            Console::WriteLine("Static Thread {0}", i.ToString());
    }
}

void MyThread::NonStaticThread(Object ^name)
{
    for (int i = 0; i < 50000001; i++)
    {
        if (i % 10000000 == 0)
            Console::WriteLine("Member {0} Thread {1}", 
            name, // Parameter passed
            i.ToString());
    }
}

void main()
{
    Console::WriteLine("Main Program Starts");

    // Creating a thread start delegate for a static method
    ThreadStart ^thrStart = gcnew ThreadStart(&MyThread::StaticThread);
    // Use the ThreadStart to create a Thread pointer Object
    Thread ^thr1 = gcnew Thread(thrStart);

    MyThread ^myThr = gcnew MyThread();
    // Creating a Thread reference object in one line from a member method
    Thread ^thr2 = gcnew Thread(
        gcnew ParameterizedThreadStart(myThr, &MyThread::NonStaticThread));

//  Uncomment for background vs foreground exploration
//  thr1->IsBackground = true;
//  thr2->IsBackground = true;

    // Actually starting the pointer and reference threads
    thr1->Start();
    thr2->Start("Parameterized");

    Console::WriteLine("Main Program Ends");
}