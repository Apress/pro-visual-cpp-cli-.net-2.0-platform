using namespace System;
using namespace System::Threading;

ref class MyThread
{
public:

    [ThreadStatic]
    static int ^iVal;

public:
    static MyThread()
    {
        iVal = gcnew int;
    }

    void ThreadFunc();
    void SubThreadFunc();
};

void MyThread::ThreadFunc()
{
    iVal = gcnew int;
    iVal = 7;

    SubThreadFunc();
}

void MyThread::SubThreadFunc()
{
    int max = *iVal + 5;

    while (*iVal < max)
    {
        Thread ^thr = Thread::CurrentThread;
        Console::WriteLine("{0} {1}", thr->Name, iVal->ToString());
        Thread::Sleep(1);
        (*iVal)++;
    }
}


void main()
{
    Console::WriteLine("Before starting thread");

    MyThread ^myThr1 = gcnew MyThread();

    Thread ^thr1 = gcnew Thread(gcnew ThreadStart(myThr1, &MyThread::ThreadFunc));
    Thread ^thr2 = gcnew Thread(gcnew ThreadStart(myThr1, &MyThread::ThreadFunc));

    Thread::CurrentThread->Name = "Main";
    thr1->Name = "Thread1";
    thr2->Name = "Thread2";

    thr1->Start();
    thr2->Start();

    myThr1->iVal = 5;
    myThr1->SubThreadFunc();
}