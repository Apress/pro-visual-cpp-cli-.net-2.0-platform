#pragma once


namespace ErrorProviderEx 
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
        System::Windows::Forms::TextBox^  tbPword;
        System::Windows::Forms::Label^  lbPword;
        System::Windows::Forms::Button^  bnLogin;
        System::Windows::Forms::TextBox^  tbName;
        System::Windows::Forms::Label^  lbName;
        System::Windows::Forms::ErrorProvider^  eProvider;
        System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            this->tbPword = (gcnew System::Windows::Forms::TextBox());
            this->lbPword = (gcnew System::Windows::Forms::Label());
            this->bnLogin = (gcnew System::Windows::Forms::Button());
            this->tbName = (gcnew System::Windows::Forms::TextBox());
            this->lbName = (gcnew System::Windows::Forms::Label());
            this->eProvider = 
               (gcnew System::Windows::Forms::ErrorProvider(this->components));
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>
                (this->eProvider))->BeginInit();
            this->SuspendLayout();
            // 
            // tbPword
            // 
            this->tbPword->Location = System::Drawing::Point(103, 83);
            this->tbPword->Name = L"tbPword";
            this->tbPword->PasswordChar = '*';
            this->tbPword->Size = System::Drawing::Size(100, 20);
            this->tbPword->TabIndex = 9;
            this->tbPword->Validating += 
                gcnew System::ComponentModel::CancelEventHandler(this, 
                                                   &Form1::textbox_Validating);
            // 
            // lbPword
            // 
            this->lbPword->AutoSize = true;
            this->lbPword->Location = System::Drawing::Point(34, 83);
            this->lbPword->Name = L"lbPword";
            this->lbPword->Size = System::Drawing::Size(53, 13);
            this->lbPword->TabIndex = 8;
            this->lbPword->Text = L"&Password";
            // 
            // bnLogin
            // 
            this->bnLogin->Location = System::Drawing::Point(75, 131);
            this->bnLogin->Name = L"bnLogin";
            this->bnLogin->Size = System::Drawing::Size(75, 23);
            this->bnLogin->TabIndex = 7;
            this->bnLogin->Text = L"&Login";
            this->bnLogin->Click += 
                gcnew System::EventHandler(this, &Form1::login_Click);
            // 
            // tbName
            // 
            this->tbName->Location = System::Drawing::Point(103, 31);
            this->tbName->Name = L"tbName";
            this->tbName->Size = System::Drawing::Size(100, 20);
            this->tbName->TabIndex = 6;
            this->tbName->Validating += 
                gcnew System::ComponentModel::CancelEventHandler(this, 
                                                   &Form1::textbox_Validating);
            // 
            // lbName
            // 
            this->lbName->AutoSize = true;
            this->lbName->Location = System::Drawing::Point(34, 31);
            this->lbName->Name = L"lbName";
            this->lbName->Size = System::Drawing::Size(35, 13);
            this->lbName->TabIndex = 5;
            this->lbName->Text = L"&Name";
            // 
            // eProvider
            // 
            this->eProvider->ContainerControl = this;
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(237, 185);
            this->Controls->Add(this->tbPword);
            this->Controls->Add(this->lbPword);
            this->Controls->Add(this->bnLogin);
            this->Controls->Add(this->tbName);
            this->Controls->Add(this->lbName);
            this->Name = L"Form1";
            this->Text = L"System Login";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>
                (this->eProvider))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: 
        System::Void textbox_Validating(System::Object^ sender, 
                                    System::ComponentModel::CancelEventArgs^ e)
        {
            try
            {
                TextBox ^tb = (TextBox^)(sender);

                if (tb->Text->Equals(""))
                    eProvider->SetError(tb, "**Error** Missing Entry!");
                else
                    eProvider->SetError(tb, "");
            }
            catch (Exception^)
            {
                // Not TextBox
            }
        }

        System::Void login_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (tbName->Text->Equals(""))
                eProvider->SetError(tbName, "**Error** Missing Entry!");
            else
                eProvider->SetError(tbName, "");

            if (tbPword->Text->Equals(""))
            {
                // Place the icon left side of control
                eProvider->SetIconAlignment(tbPword, 
                                            ErrorIconAlignment::MiddleLeft);
                eProvider->SetError(tbPword, "**Error** Missing Entry!");
            }
            else
                eProvider->SetError(tbPword, "");
        }
    };
}

