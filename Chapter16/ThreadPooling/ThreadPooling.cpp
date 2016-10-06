using namespace System;
using namespace System::Threading;

ref class MyThread
{
public:
    void ThreadFunc(Object^ stateInfo);
};

void MyThread::ThreadFunc(Object^ stateInfo)
{
    for (int i = 0; i < 10; i++)
    {
        Console::WriteLine("{0} {1}", stateInfo, i.ToString());
        Thread::Sleep(100);
    }
}


void main()
{
    Console::WriteLine("Main Program Starts");

    MyThread ^myThr1 = gcnew MyThread();

    ThreadPool::QueueUserWorkItem(gcnew WaitCallback(myThr1, &MyThread::ThreadFunc), "Thread1");
    ThreadPool::QueueUserWorkItem(gcnew WaitCallback(myThr1, &MyThread::ThreadFunc), "Thread2");

    Thread::Sleep(2000);
    Console::WriteLine("Main Program Ends");
}