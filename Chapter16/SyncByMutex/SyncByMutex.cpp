using namespace System;
using namespace System::Threading;

ref class MyThread
{
    static Mutex ^m = gcnew Mutex(false, "SyncByMutex");
public:
    static void ThreadFunc();
};

void MyThread::ThreadFunc()
{
    Random^ Rand = gcnew Random;

    Thread ^thr = Thread::CurrentThread;

    for (int i = 0; i < 4; i++)
    {
        m->WaitOne();
        
        Console::WriteLine("{0} Enter - {1}", thr->Name, i);
        Thread::Sleep(Rand->Next(20, 100)); // Simulate Work
        Console::WriteLine("{0} Exit  - {1}", thr->Name, i);
        m->ReleaseMutex();
        
        Thread::Sleep(Rand->Next(20, 100));
    }
}

int main(int argc, char *argv[])
{
    MyThread ^myThr = gcnew MyThread();

    Thread ^thr1 = gcnew Thread(gcnew ThreadStart(&MyThread::ThreadFunc));
    Thread ^thr2 = gcnew Thread(gcnew ThreadStart(&MyThread::ThreadFunc));

    thr1->Name = String::Format("Process {0} - Thread 1", gcnew String(argv[1]));
    thr2->Name = String::Format("Process {0} - Thread 2", gcnew String(argv[1]));

    thr1->Start();
    Thread::Sleep(50);
    thr2->Start();
}
