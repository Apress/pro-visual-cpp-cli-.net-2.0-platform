#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace CustomDialog {

    public ref class MyDialog : public System::Windows::Forms::Form
    {
    public:
        MyDialog(void)
        {
            InitializeComponent();
        }

    protected:
        ~MyDialog()
        {
            if (components)
            {
                delete components;
            }
        }

    public:
        property String^ PassedValue  // PassedValue property
        {
            void set(String ^value)
            {
                tbPassedValue->Text = value;
            }
            String ^get()
            {
            return tbPassedValue->Text;
            }
        }

    private: 
        System::Windows::Forms::Button^  bnCancel;
        System::Windows::Forms::Button^  bnAbort;
        System::Windows::Forms::Button^  bnOK;
        System::Windows::Forms::TextBox^  tbPassedValue;
        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->bnCancel = (gcnew System::Windows::Forms::Button());
            this->bnAbort = (gcnew System::Windows::Forms::Button());
            this->bnOK = (gcnew System::Windows::Forms::Button());
            this->tbPassedValue = (gcnew System::Windows::Forms::TextBox());
            this->SuspendLayout();
            // 
            // bnCancel
            // 
            this->bnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
            this->bnCancel->Location = System::Drawing::Point(205, 60);
            this->bnCancel->Name = L"bnCancel";
            this->bnCancel->Size = System::Drawing::Size(75, 23);
            this->bnCancel->TabIndex = 7;
            this->bnCancel->Text = L"Cancel";
            // 
            // bnAbort
            // 
            this->bnAbort->DialogResult = System::Windows::Forms::DialogResult::Abort;
            this->bnAbort->Location = System::Drawing::Point(110, 60);
            this->bnAbort->Name = L"bnAbort";
            this->bnAbort->Size = System::Drawing::Size(75, 23);
            this->bnAbort->TabIndex = 6;
            this->bnAbort->Text = L"Abort";
            // 
            // bnOK
            // 
            this->bnOK->DialogResult = System::Windows::Forms::DialogResult::OK;
            this->bnOK->Location = System::Drawing::Point(13, 60);
            this->bnOK->Name = L"bnOK";
            this->bnOK->Size = System::Drawing::Size(75, 23);
            this->bnOK->TabIndex = 5;
            this->bnOK->Text = L"OK";
            // 
            // tbPassedValue
            // 
            this->tbPassedValue->Location = System::Drawing::Point(13, 20);
            this->tbPassedValue->Name = L"tbPassedValue";
            this->tbPassedValue->Size = System::Drawing::Size(267, 20);
            this->tbPassedValue->TabIndex = 4;
            // 
            // myDialog
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(292, 102);
            this->Controls->Add(this->bnCancel);
            this->Controls->Add(this->bnAbort);
            this->Controls->Add(this->bnOK);
            this->Controls->Add(this->tbPassedValue);
            this->Name = L"myDialog";
            this->Text = L"My Custom Dialog";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
    };
}
