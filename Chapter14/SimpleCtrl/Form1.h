#pragma once


namespace SimpleCtrl 
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::ServiceProcess;

    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();
        }

    protected:
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
        }

    private: 
        System::ServiceProcess::ServiceController^  serviceController1;
        System::Windows::Forms::Button^  bnIntv20;
        System::Windows::Forms::Button^  bnIntv15;
        System::Windows::Forms::Button^  bnStop;
        System::Windows::Forms::Button^  bnStart;

        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->serviceController1 = (gcnew System::ServiceProcess::ServiceController());
            this->bnIntv20 = (gcnew System::Windows::Forms::Button());
            this->bnIntv15 = (gcnew System::Windows::Forms::Button());
            this->bnStop = (gcnew System::Windows::Forms::Button());
            this->bnStart = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // serviceController1
            // 
            this->serviceController1->MachineName = L"amidala";
            this->serviceController1->ServiceName = L"SimpleWinService";
            // 
            // bnIntv20
            // 
            this->bnIntv20->Location = System::Drawing::Point(150, 44);
            this->bnIntv20->Name = L"bnIntv20";
            this->bnIntv20->Size = System::Drawing::Size(75, 23);
            this->bnIntv20->TabIndex = 6;
            this->bnIntv20->Text = L"Interval 20";
            this->bnIntv20->Click += gcnew System::EventHandler(this, &Form1::bnIntv20_Click);
            // 
            // bnIntv15
            // 
            this->bnIntv15->Location = System::Drawing::Point(150, 15);
            this->bnIntv15->Name = L"bnIntv15";
            this->bnIntv15->Size = System::Drawing::Size(75, 23);
            this->bnIntv15->TabIndex = 5;
            this->bnIntv15->Text = L"Interval 15";
            this->bnIntv15->Click += gcnew System::EventHandler(this, &Form1::bnIntv15_Click);
            // 
            // bnStop
            // 
            this->bnStop->Location = System::Drawing::Point(32, 44);
            this->bnStop->Name = L"bnStop";
            this->bnStop->Size = System::Drawing::Size(75, 23);
            this->bnStop->TabIndex = 7;
            this->bnStop->Text = L"Stop";
            this->bnStop->Click += gcnew System::EventHandler(this, &Form1::bnStop_Click);
            // 
            // bnStart
            // 
            this->bnStart->Location = System::Drawing::Point(32, 15);
            this->bnStart->Name = L"bnStart";
            this->bnStart->Size = System::Drawing::Size(75, 23);
            this->bnStart->TabIndex = 4;
            this->bnStart->Text = L"Start";
            this->bnStart->Click += gcnew System::EventHandler(this, &Form1::bnStart_Click);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(256, 83);
            this->Controls->Add(this->bnIntv20);
            this->Controls->Add(this->bnIntv15);
            this->Controls->Add(this->bnStop);
            this->Controls->Add(this->bnStart);
            this->Name = L"Form1";
            this->Text = L"SimpleWinService Controller";
            this->ResumeLayout(false);

        }
#pragma endregion

     private: 
        System::Void bnStart_Click(System::Object^  sender, System::EventArgs^ e) 
        {
            serviceController1->Refresh();

            if (serviceController1->Status == ServiceControllerStatus::Stopped)
            {
                serviceController1->Start();
                MessageBox::Show("SimpleWinService Started");
            }
            else
            {
                MessageBox::Show("SimpleWinService Running");
            }
        }

        System::Void bnStop_Click(System::Object^  sender, System::EventArgs^  e) 
        {
            serviceController1->Refresh();

            if (serviceController1->Status == ServiceControllerStatus::Running)
            {
                serviceController1->Stop();
                MessageBox::Show("SimpleWinService Stopped");
            }
            else
            {
                MessageBox::Show("SimpleWinService Not Running");
            }
        }

        System::Void bnIntv15_Click(System::Object^ sender, System::EventArgs^ e) 
        {
            serviceController1->Refresh();

            if (serviceController1->Status == ServiceControllerStatus::Running)
            {
                serviceController1->ExecuteCommand(150);
                MessageBox::Show("SimpleWinService Interval in 15 seconds");
            }
            else
            {
                MessageBox::Show("SimpleWinService Not Running");
            }
        }

        System::Void bnIntv20_Click(System::Object^  sender, System::EventArgs^  e) 
        {
            serviceController1->Refresh();

            if (serviceController1->Status == ServiceControllerStatus::Running)
            {
                serviceController1->ExecuteCommand(200);
                MessageBox::Show("SimpleWinService Interval in 20 seconds");
            }
            else
            {
                MessageBox::Show("SimpleWinService Not Running");
            }
        }
    };
}

