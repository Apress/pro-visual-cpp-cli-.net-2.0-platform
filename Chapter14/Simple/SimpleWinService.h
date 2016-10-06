#pragma once

using namespace System;
using namespace System::Collections;
using namespace System::ServiceProcess;
using namespace System::ComponentModel;


namespace Simple 
{
    public ref class SimpleWinService : public System::ServiceProcess::ServiceBase
    {
    private:
        double interval;

    public:
        SimpleWinService()
        {
            InitializeComponent();
            interval = 15000; // 15 seconds - default
        }
    protected:
        ~SimpleWinService()
        {
            if (components)
            {
                delete components;
            }
        }

#ifdef COMMANDLINE_DEBUG
    public:
#endif
        virtual void OnStart(array<String^>^ args) override
        {
            eventLog1->WriteEntry("SimpleWinService Started");

            if (args == nullptr || args->Length == 0)
                eventLog1->WriteEntry("Empty args");
            else
            {
                for each (String ^s in args)
                {
                    eventLog1->WriteEntry(s);
                }
            }

            this->timer = gcnew System::Timers::Timer(interval);
            this->timer->Elapsed += 
                gcnew System::Timers::ElapsedEventHandler(this, 
                                             &SimpleWinService::timer_Tick);
            this->timer->Start();
        }

        virtual void OnStop() override
        {
            this->timer->Stop();
            eventLog1->WriteEntry("SimpleWinService Stopped");
        }

        virtual void OnPause() override
        {
            this->timer->Stop();
            eventLog1->WriteEntry("SimpleWinService Paused");
        }

        virtual void OnContinue() override
        {
            eventLog1->WriteEntry("SimpleWinService Continued");
            this->timer->Start();
        }

        virtual void OnCustomCommand(int cmd) override
        {
            if (cmd == 150)
                this->timer->Interval = 15000;
            else
                this->timer->Interval = 20000;
        }

    private: 
        System::Diagnostics::EventLog^  eventLog1;
        System::Timers::Timer^  timer;

        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->eventLog1 = (gcnew System::Diagnostics::EventLog());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->eventLog1))->BeginInit();
            // 
            // eventLog1
            // 
            this->eventLog1->Log = L"Application";
            this->eventLog1->Source = L"SimpleWinService";
            // 
            // SimpleWinService
            // 
            this->CanPauseAndContinue = true;
            this->ServiceName = L"SimpleWinService";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->eventLog1))->EndInit();
        }

#pragma endregion

     private: 
        void timer_Tick(System::Object^ sender, 
                        System::Timers::ElapsedEventArgs^ e)
        {
            this->timer->Stop();
            eventLog1->WriteEntry("SimpleWinService Elapsed Event Occurred");
            this->timer->Start();
        }
   };
}
