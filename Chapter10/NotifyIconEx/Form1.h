#pragma once


namespace NotifyIconEx {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

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
        System::Windows::Forms::Button^  bnTaskBar;
        System::Windows::Forms::Button^  bnNotify;
        System::Windows::Forms::NotifyIcon^  notifyIcon;
        System::Windows::Forms::ContextMenuStrip^  menuExit;
        System::Windows::Forms::ToolStripMenuItem^  miExit;
        System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            System::ComponentModel::ComponentResourceManager^ resources = 
       (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
            this->bnTaskBar = (gcnew System::Windows::Forms::Button());
            this->bnNotify = (gcnew System::Windows::Forms::Button());
            this->notifyIcon = 
                (gcnew System::Windows::Forms::NotifyIcon(this->components));
            this->menuExit = 
            (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
            this->miExit = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->menuExit->SuspendLayout();
            this->SuspendLayout();
            // 
            // bnTaskBar
            // 
            this->bnTaskBar->Location = System::Drawing::Point(28, 59);
            this->bnTaskBar->Name = L"bnTaskBar";
            this->bnTaskBar->Size = System::Drawing::Size(131, 23);
            this->bnTaskBar->TabIndex = 3;
            this->bnTaskBar->Text = L"Toggle TaskBar Icon";
            this->bnTaskBar->Click += 
                gcnew System::EventHandler(this, &Form1::bnTaskBar_Click);
            // 
            // bnNotify
            // 
            this->bnNotify->Location = System::Drawing::Point(28, 12);
            this->bnNotify->Name = L"bnNotify";
            this->bnNotify->Size = System::Drawing::Size(131, 23);
            this->bnNotify->TabIndex = 2;
            this->bnNotify->Text = L"Toggle Notify Icon";
            this->bnNotify->Click += 
                gcnew System::EventHandler(this, &Form1::bnNotify_Click);
            // 
            // notifyIcon
            // 
            this->notifyIcon->ContextMenuStrip = this->menuExit;
            this->notifyIcon->Icon = (cli::safe_cast<System::Drawing::Icon^>
                (resources->GetObject(L"notifyIcon.Icon")));
            this->notifyIcon->Text = L"Notify Icon Example";
            this->notifyIcon->Visible = true;
            // 
            // menuExit
            // 
            this->menuExit->Items->AddRange(
                gcnew cli::array< System::Windows::Forms::ToolStripItem^>(1) 
                {this->miExit});
            this->menuExit->Name = L"miExit";
            this->menuExit->RightToLeft = 
                System::Windows::Forms::RightToLeft::No;
            this->menuExit->Size = System::Drawing::Size(153, 48);
            // 
            // miExit
            // 
            this->miExit->Name = L"miExit";
            this->miExit->Size = System::Drawing::Size(152, 22);
            this->miExit->Text = L"E&xit";
            this->miExit->Click += 
                gcnew System::EventHandler(this, &Form1::miExit_Click);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(192, 106);
            this->Controls->Add(this->bnTaskBar);
            this->Controls->Add(this->bnNotify);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>
                (resources->GetObject(L"$this.Icon")));
            this->Name = L"Form1";
            this->Text = L"Notify Icon";
            this->menuExit->ResumeLayout(false);
            this->ResumeLayout(false);

        }
#pragma endregion

    private: 
        System::Void bnNotify_Click(System::Object^ sender, 
                                    System::EventArgs^ e)
        {
            notifyIcon->Visible = !notifyIcon->Visible;
        }

        System::Void bnTaskBar_Click(System::Object^ sender, 
                                     System::EventArgs^ e)
        {
            this->ShowInTaskbar = ! this->ShowInTaskbar;
        }

        System::Void miExit_Click(System::Object^ sender, 
                                  System::EventArgs^  e) 
        {
            Application::Exit();
        }
    };
}

