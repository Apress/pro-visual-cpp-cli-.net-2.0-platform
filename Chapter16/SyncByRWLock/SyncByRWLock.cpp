using namespace System;
using namespace System::Threading;

ref class MyThread
{
    static ReaderWriterLock ^RWLock = gcnew ReaderWriterLock();
    static int iVal = 4;

public:
    static void ReaderThread();
    static void WriterThread();
};

void MyThread::ReaderThread()
{
    String ^thrName = Thread::CurrentThread->Name;
    while (true)
    {
        try
        {
            RWLock->AcquireReaderLock(2);

            Console::WriteLine("Reading in {0}. iVal is {1}", 
                thrName, iVal);

            RWLock->ReleaseReaderLock();
            Thread::Sleep(4);
        }
        catch (ApplicationException^)
        {
            Console::WriteLine("Reading in {0}. Timed out", thrName);
        }
    }
}

void MyThread::WriterThread()
{
    while (iVal > 0)
    {
        RWLock->AcquireWriterLock(-1);

        Interlocked::Decrement(iVal);
        Console::WriteLine("Writing iVal to {0}", iVal);
        Thread::Sleep(20);
            
        RWLock->ReleaseWriterLock();
    }
}


void main()
{
    Thread ^thr1 = gcnew Thread(gcnew ThreadStart(&MyThread::ReaderThread));
    Thread ^thr2 = gcnew Thread(gcnew ThreadStart(&MyThread::ReaderThread));
    Thread ^thr3 = gcnew Thread(gcnew ThreadStart(&MyThread::WriterThread));

    thr1->Name = "Thread1";
    thr2->Name = "Thread2";

    thr1->IsBackground = true;
    thr2->IsBackground = true;

    thr1->Start();
    thr2->Start();
    thr3->Start();

    thr3->Join();
    Thread::Sleep(2);
}