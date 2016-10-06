using namespace System;
using namespace System::Threading;

ref class MyThread
{
public:
    static void ThreadFunc(Object ^Name);
};

void MyThread::ThreadFunc(Object ^Name)
{
    for (int i = 0; i < 5; i++)
    {
        Console::WriteLine("{0} {1}", Name, i.ToString());
        Thread::Sleep(1);
    }
}

void main()
{
    Console::WriteLine("Before starting thread");

    Thread ^thr1 = gcnew Thread(gcnew ParameterizedThreadStart(&MyThread::ThreadFunc));
    Thread ^thr2 = gcnew Thread(gcnew ParameterizedThreadStart(&MyThread::ThreadFunc));

    thr1->Start("Thread1");
    thr1->Join();

    thr2->Start("Thread2");

    Console::WriteLine("End of Main");
}