#pragma once

namespace MightyLabel 
{
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
            labelSwitch = true;
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
        System::Windows::Forms::Label^  MightyLabel;
        bool labelSwitch;

        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->MightyLabel = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // MightyLabel
            // 
            this->MightyLabel->BorderStyle = 
                System::Windows::Forms::BorderStyle::FixedSingle;
            this->MightyLabel->Cursor = System::Windows::Forms::Cursors::Hand;
            this->MightyLabel->Location = System::Drawing::Point(63, 91);
            this->MightyLabel->Name = L"MightyLabel";
            this->MightyLabel->Size = System::Drawing::Size(150, 35);
            this->MightyLabel->TabIndex = 1;
            this->MightyLabel->Text = 
                L"This is the mighty label! It will change when you click it";
            this->MightyLabel->TextAlign = 
                System::Drawing::ContentAlignment::MiddleCenter;
            this->MightyLabel->Click += 
                gcnew System::EventHandler(this, &Form1::MightyLabel_Click);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(292, 273);
            this->Controls->Add(this->MightyLabel);
            this->Name = L"Form1";
            this->Text = L"The Mighty Label";
            this->ResumeLayout(false);
        }

#pragma endregion

    private: 
        System::Void MightyLabel_Click(System::Object^ sender, 
                                       System::EventArgs^ e)
        {
            if (labelSwitch) 
                MightyLabel->Text = L"Ouchie!!!  That hurt."; 
            else 
                MightyLabel->Text = L"Ooo!!!  That tickled."; 
            labelSwitch = !labelSwitch; 
        }
    };
}