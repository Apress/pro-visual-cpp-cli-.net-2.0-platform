using namespace System;
using namespace System::Diagnostics;
using namespace System::Threading;


void main()
{
    Process^ proc1 = gcnew Process();
    proc1->StartInfo->FileName = "../debug/SyncByMutex.exe";
    proc1->StartInfo->Arguments = "1";
    proc1->StartInfo->UseShellExecute = false;
    proc1->StartInfo->RedirectStandardInput = true;
    proc1->Start();

    Process^ proc2 = gcnew Process();
    proc2->StartInfo->FileName = "../debug/SyncByMutex.exe";
    proc2->StartInfo->Arguments = "2";
    proc2->StartInfo->UseShellExecute = false;
    proc2->StartInfo->RedirectStandardInput = true;
    proc2->Start();

    Thread::Sleep(5000);  // Added just to clean up console display
}