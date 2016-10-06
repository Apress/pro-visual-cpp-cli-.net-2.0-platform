#pragma once

namespace TextEntry 
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

            DoB = DateTime::MinValue;

            // setting validating type to DateTime
            mtbDoB->ValidatingType = DateTime::typeid;
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
        System::Windows::Forms::Button^  bnSubmit;
        System::Windows::Forms::Label^  label3;
        System::Windows::Forms::TextBox^  tbPassword;
        System::Windows::Forms::TextBox^  tbOutput;
        System::Windows::Forms::Label^  label2;
        System::Windows::Forms::MaskedTextBox^  mtbDoB;
        System::Windows::Forms::Label^  label1;
        System::Windows::Forms::TextBox^  tbName;

        DateTime^ DoB;

        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->bnSubmit = (gcnew System::Windows::Forms::Button());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->tbPassword = (gcnew System::Windows::Forms::TextBox());
            this->tbOutput = (gcnew System::Windows::Forms::TextBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->mtbDoB = (gcnew System::Windows::Forms::MaskedTextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->tbName = (gcnew System::Windows::Forms::TextBox());
            this->SuspendLayout();
            // 
            // bnSubmit
            // 
            this->bnSubmit->Location = System::Drawing::Point(260, 36);
            this->bnSubmit->Margin = System::Windows::Forms::Padding(1,3,3,3);
            this->bnSubmit->Name = L"bnSubmit";
            this->bnSubmit->Size = System::Drawing::Size(56, 20);
            this->bnSubmit->TabIndex = 10;
            this->bnSubmit->Text = L" Submit";
            this->bnSubmit->Click += 
                gcnew System::EventHandler(this, &Form1::bnSubmit_Click);
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(14, 232);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(56, 13);
            this->label3->TabIndex = 14;
            this->label3->Text = L"Password:";
            // 
            // tbPassword
            // 
            this->tbPassword->CausesValidation = false;
            this->tbPassword->Location = System::Drawing::Point(78, 226);
            this->tbPassword->MaxLength = 16;
            this->tbPassword->Name = L"tbPassword";
            this->tbPassword->PasswordChar = '?';
            this->tbPassword->Size = System::Drawing::Size(238, 20);
            this->tbPassword->TabIndex = 13;
            this->tbPassword->UseSystemPasswordChar = true;
            this->tbPassword->WordWrap = false;
            this->tbPassword->TextChanged += 
               gcnew System::EventHandler(this,&Form1::tbPassword_TextChanged);
            // 
            // tbOutput
            // 
            this->tbOutput->Location = System::Drawing::Point(14, 63);
            this->tbOutput->Multiline = true;
            this->tbOutput->Name = L"tbOutput";
            this->tbOutput->ReadOnly = true;
            this->tbOutput->ScrollBars = 
                System::Windows::Forms::ScrollBars::Vertical;
            this->tbOutput->Size = System::Drawing::Size(302, 156);
            this->tbOutput->TabIndex = 12;
            this->tbOutput->TabStop = false;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(168, 15);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(69, 13);
            this->label2->TabIndex = 11;
            this->label2->Text = L"Date of Birth:";
            // 
            // mtbDoB
            // 
            this->mtbDoB->AllowPromptAsInput = false;
            this->mtbDoB->BeepOnError = true;
            this->mtbDoB->Location = System::Drawing::Point(168, 36);
            this->mtbDoB->Margin = System::Windows::Forms::Padding(3,3,1,3);
            this->mtbDoB->Mask = L"00/00/0000";
            this->mtbDoB->Name = L"mtbDoB";
            this->mtbDoB->Size = System::Drawing::Size(89, 20);
            this->mtbDoB->TabIndex = 8;
            this->mtbDoB->TypeValidationCompleted += 
                gcnew System::Windows::Forms::TypeValidationEventHandler(this,
                                      &Form1::mtbDoB_TypeValidationCompleted);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(14, 15);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(38, 13);
            this->label1->TabIndex = 9;
            this->label1->Text = L"Name:";
            // 
            // tbName
            // 
            this->tbName->Location = System::Drawing::Point(14, 36);
            this->tbName->Name = L"tbName";
            this->tbName->Size = System::Drawing::Size(147, 20);
            this->tbName->TabIndex = 7;
            this->tbName->Validating += 
                gcnew System::ComponentModel::CancelEventHandler(this, 
                                                   &Form1::tbName_Validating);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(331, 261);
            this->Controls->Add(this->bnSubmit);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->tbPassword);
            this->Controls->Add(this->tbOutput);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->mtbDoB);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->tbName);
            this->Name = L"Form1";
            this->Text = L"Simple entry data entry";
            this->ResumeLayout(false);
            this->PerformLayout();
        }

#pragma endregion

    private: 
        System::Void bnSubmit_Click(System::Object^ sender, 
                                    System::EventArgs^ e)
        {
            if (tbName->Text->Length <= 0)          // Blank name bad!
                tbName->Focus();
            else if (*DoB == DateTime::MinValue)    // Bad date bad!
                mtbDoB->Focus();
            else                                    // Good!
            {
                // Concatinate name and date of birth and add to output
                tbOutput->Text = String::Format("{0} - {1}\r\n{2}", 
                    tbName->Text, mtbDoB->Text, tbOutput->Text);
                tbName->Clear(); 
                mtbDoB->Clear();
                DoB = DateTime::MinValue;
           }
        }

        System::Void tbPassword_TextChanged(System::Object^ sender, 
                                            System::EventArgs^ e)
        {
             // if the Password TextBox Text equals "Editable" then make 
            // the multiline TextBox editable and have a tab stop
            if (tbPassword->Text->Equals("Editable")) 
            {
                tbOutput->TabStop = true;
                tbOutput->ReadOnly = false; 
            }
            else
            {
                tbOutput->TabStop = false;
                tbOutput->ReadOnly = true; 
            }
        }

        System::Void mtbDoB_TypeValidationCompleted(System::Object^ sender, 
                            System::Windows::Forms::TypeValidationEventArgs^ e)
        {
            // Check to see if the date was valid and less then or equals 
            // todays date. When false make the MaskedTextBox yellow
            // and make DoB MinValue. otherwise set it to normal and make
            // DoB the value within MaskedTextBox
            if (e->IsValidInput && 
                (*(DateTime^)e->ReturnValue) <= DateTime::Now)
            {
                DoB = (DateTime^)e->ReturnValue;
                mtbDoB->BackColor = SystemColors::Window;
            }
            else
            {
                mtbDoB->BackColor = Color::Yellow;
                DoB = DateTime::MinValue;
            }
        }

        System::Void tbName_Validating(System::Object^ sender, 
                                    System::ComponentModel::CancelEventArgs^ e)
        {
            // Check to make sure there is a name. When false make the
            // TextBox yellow. Otherwise set it to normal as all is okay
            if (tbName->Text->Length <= 0)
                tbName->BackColor = Color::Yellow;
            else
                tbName->BackColor = SystemColors::Window;
        }
    };
}
