using namespace System;
using namespace System::Threading;

ref class MyThread
{
public:
    static void ThreadFunc1();
    static void ThreadFunc2();
};

void MyThread::ThreadFunc1()
{
    Console::WriteLine("Before long sleep");
    try
    {
        Thread::Sleep(Timeout::Infinite); 
    }
    catch(ThreadInterruptedException^){/*continue processing*/}
    Console::WriteLine("After long sleep");
}

void MyThread::ThreadFunc2()
{
    for (int i = 0; i < 5; i++)
    {
        Console::WriteLine("Thread {0}",i.ToString());
        Thread::Sleep(2);
    }
}


void main()
{
    Thread ^thr1 = gcnew Thread(gcnew ThreadStart(&MyThread::ThreadFunc1));
    Thread ^thr2 = gcnew Thread(gcnew ThreadStart(&MyThread::ThreadFunc2));

    Console::WriteLine("Sleep/interrupt thread");
    thr1->Start();
    
    Thread::Sleep(4);
    for (int i = 0; i < 4; i++)
    {
          Console::WriteLine("**Main2 {0}", i.ToString());
          Thread::Sleep(2);
    }
    thr1->Interrupt();
    thr1->Join();

    Console::WriteLine("\nSuspend/resume thread");
    thr2->Start();

    Thread::Sleep(8);
    thr2->Suspend();

    for (int i = 0; i < 4; i++)
    {
        Console::WriteLine("**Main1 {0}", i.ToString());
        Thread::Sleep(2);
    }
    thr2->Resume();
}