using namespace System;
using namespace System::Threading;

ref class MyThread
{
public:
    static void ThreadFunc(Object ^Name);
};

void MyThread::ThreadFunc(Object ^Name)
{
    Thread ^thr = Thread::CurrentThread;
    try
    {
        for (int i = 0; i < 100; i++)
        {
            Console::WriteLine("{0} {1}", Name, i.ToString());
            Thread::Sleep(1);
        }
        return;
    }
    catch (ThreadAbortException^)
    {
        Console::WriteLine("{0} Aborted", Name);
        // Reset the abort so that the meoth will continue processing
        // thr->ResetAbort();
    }
}


void main()
{
    Console::WriteLine("Main Program Starts");

    Thread ^thr1 = gcnew Thread(gcnew ParameterizedThreadStart(&MyThread::ThreadFunc));
    Thread ^thr2 = gcnew Thread(gcnew ParameterizedThreadStart(&MyThread::ThreadFunc));

    thr1->Start("Thread1");
    thr2->Start("Thread2");

    Thread::Sleep(20);
    thr1->Abort();
    Thread::Sleep(40);
    thr2->Abort();

    try
    {
        thr1->Start();
    }
    catch (ThreadStateException ^tse)
    {
        Console::WriteLine(tse->ToString());
    }

    Console::WriteLine("Main Program Ends");
}