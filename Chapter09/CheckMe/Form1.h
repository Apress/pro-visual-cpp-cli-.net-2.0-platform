#pragma once

namespace CheckMe 
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
        System::Windows::Forms::CheckBox^  BottomCheck;
        System::Windows::Forms::CheckBox^  checkBox2;
        System::Windows::Forms::CheckBox^  checkBox1;
        System::Windows::Forms::CheckBox^  TopCheck;

        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->BottomCheck = (gcnew System::Windows::Forms::CheckBox());
            this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
            this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
            this->TopCheck = (gcnew System::Windows::Forms::CheckBox());
            this->SuspendLayout();
            // 
            // BottomCheck
            // 
            this->BottomCheck->AutoSize = true;
            this->BottomCheck->Enabled = false;
            this->BottomCheck->Location = System::Drawing::Point(52, 167);
            this->BottomCheck->Name = L"BottomCheck";
            this->BottomCheck->Size = System::Drawing::Size(127, 17);
            this->BottomCheck->TabIndex = 4;
            this->BottomCheck->TabStop = false;
            this->BottomCheck->Text = L"You Can\'t Check Me!";
            this->BottomCheck->Visible = false;
            this->BottomCheck->Enter += 
                gcnew System::EventHandler(this, &Form1::BottomCheck_Enter);
            this->BottomCheck->MouseEnter += 
                gcnew System::EventHandler(this, &Form1::BottomCheck_Enter);
            // 
            // checkBox2
            // 
            this->checkBox2->AutoSize = true;
            this->checkBox2->Location = System::Drawing::Point(52, 130);
            this->checkBox2->Name = L"checkBox2";
            this->checkBox2->Size = System::Drawing::Size(106, 17);
            this->checkBox2->TabIndex = 5;
            this->checkBox2->Text = L"Don\'t Forget ME!";
            // 
            // checkBox1
            // 
            this->checkBox1->AutoSize = true;
            this->checkBox1->Checked = true;
            this->checkBox1->CheckState = 
                System::Windows::Forms::CheckState::Indeterminate;
            this->checkBox1->Location = System::Drawing::Point(52, 90);
            this->checkBox1->Name = L"checkBox1";
            this->checkBox1->Size = System::Drawing::Size(133, 17);
            this->checkBox1->TabIndex = 2;
            this->checkBox1->Text = L"Check Me! Check Me!";
            this->checkBox1->ThreeState = true;
            // 
            // TopCheck
            // 
            this->TopCheck->AutoSize = true;
            this->TopCheck->Location = System::Drawing::Point(52, 49);
            this->TopCheck->Name = L"TopCheck";
            this->TopCheck->Size = System::Drawing::Size(127, 17);
            this->TopCheck->TabIndex = 3;
            this->TopCheck->TabStop = false;
            this->TopCheck->Text = L"You Can\'t Check Me!";
            this->TopCheck->Enter += 
                gcnew System::EventHandler(this, &Form1::TopCheck_Enter);
            this->TopCheck->MouseEnter += 
                gcnew System::EventHandler(this, &Form1::TopCheck_Enter);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(242, 273);
            this->Controls->Add(this->BottomCheck);
            this->Controls->Add(this->checkBox2);
            this->Controls->Add(this->checkBox1);
            this->Controls->Add(this->TopCheck);
            this->Name = L"Form1";
            this->Text = L"Can\'t Check Me";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private: 
        System::Void TopCheck_Enter(System::Object^ sender, 
                                    System::EventArgs^ e)
        {
            // Hide Top checkbox and display bottom
            TopCheck->Enabled = false; 
            TopCheck->Visible = false; 
            BottomCheck->Enabled = true; 
            BottomCheck->Visible = true; 
        }

    private: 
        System::Void BottomCheck_Enter(System::Object^  sender, 
                                       System::EventArgs^  e)
        {
            // Hide Bottom checkbox and display top
            BottomCheck->Enabled = false; 
            BottomCheck->Visible = false; 
            TopCheck->Enabled = true; 
            TopCheck->Visible = true; 
        }
    };
}

