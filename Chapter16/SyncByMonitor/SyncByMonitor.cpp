using namespace System;
using namespace System::Threading;

ref class MyThread
{
    static Object^ MonitorObject = gcnew Object();

public:
    void TFuncOne();
    void TFuncTwo();
    void TFuncThree();
};

void MyThread::TFuncOne()
{
    Console::WriteLine("TFuncOne   enters monitor");
    Monitor::Enter(MonitorObject);
    for (int i = 0; i < 3; i++)
    {
        Console::WriteLine("TFuncOne   Waits  {0}", i);
        Monitor::Wait(MonitorObject);
        Console::WriteLine("TFuncOne   Pulses {0}", i);
        Monitor::Pulse(MonitorObject);
        Thread::Sleep(1);
    }
    Monitor::Exit(MonitorObject);
    Console::WriteLine("TFuncOne   exits monitor");
}

void MyThread::TFuncTwo()
{
    Console::WriteLine("TFuncTwo   enters monitor");
    Monitor::Enter(MonitorObject);
    for (int i = 0; i < 3; i++)
    {
        Console::WriteLine("TFuncTwo   Pulses {0}", i);
        Monitor::Pulse(MonitorObject);
        Thread::Sleep(1);
        Console::WriteLine("TFuncTwo   Waits  {0}", i);
        Monitor::Wait(MonitorObject);
    }
    Monitor::Exit(MonitorObject);
    Console::WriteLine("TFuncTwo   exits monitor");
}

void MyThread::TFuncThree()
{
    if (!Monitor::TryEnter(MonitorObject))
    {
        Console::WriteLine("TFuncThree was not able to lock");
        return;
    }
    Console::WriteLine("TFuncThree got a lock");

    Monitor::Exit(MonitorObject);
    Console::WriteLine("TFuncThree exits monitor");
}


void main()
{
    MyThread ^myThr1 = gcnew MyThread();

    (gcnew Thread(gcnew ThreadStart(myThr1, &MyThread::TFuncOne)))->Start();
    Thread::Sleep(2);

    (gcnew Thread(gcnew ThreadStart(myThr1, &MyThread::TFuncTwo)))->Start();
    Thread::Sleep(2);

    for (int i = 0; i < 2; i++)
    {
        (gcnew Thread(gcnew ThreadStart(myThr1, &MyThread::TFuncThree)))->Start();
        Thread::Sleep(50);
   }
}