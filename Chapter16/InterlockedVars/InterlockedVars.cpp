using namespace System;
using namespace System::Threading;

ref class MyThread
{
    static int iVal;

public:

    static MyThread()
    {
        iVal = 5;
    }

    void ThreadFunc();
};

void MyThread::ThreadFunc()
{
    while (Interlocked::Increment(iVal) < 15)
    {
        Thread ^thr = Thread::CurrentThread;
        Console::WriteLine("{0} {1}", thr->Name, iVal);
        Thread::Sleep(1);
    }
}


void main()
{
    MyThread ^myThr1 = gcnew MyThread();

    Thread ^thr1 = gcnew Thread(gcnew ThreadStart(myThr1, &MyThread::ThreadFunc));
    Thread ^thr2 = gcnew Thread(gcnew ThreadStart(myThr1, &MyThread::ThreadFunc));

    thr1->Name = "Thread1";
    thr2->Name = "Thread2";

    thr1->Start();
    thr2->Start();
}