using namespace System;
using namespace System::Threading;

ref class MyThread
{
public:
    static void ThreadFunc();
};

void MyThread::ThreadFunc()
{
    for (int i = 0; i < 101; i++)
    {
        Thread ^thr = Thread::CurrentThread;
        if (i % 10 == 0)
            Console::WriteLine("{0} {1}", thr->Name, i.ToString());
        Thread::Sleep(10);
    }
}


void main()
{
    Console::WriteLine("Main Program Starts");

    Thread ^thr1 = gcnew Thread(gcnew ThreadStart(&MyThread::ThreadFunc));
    Thread ^thr2 = gcnew Thread(gcnew ThreadStart(&MyThread::ThreadFunc));

    thr1->Name = "Thread1";
    thr2->Name = "Thread2";

    thr1->Start();
    thr2->Start();

    int iHour = 0;
    int iMin = 0;
    int iSec = 1;
    Thread::Sleep(TimeSpan(iHour, iMin, iSec));

    Console::WriteLine("Main Program Ends");
}