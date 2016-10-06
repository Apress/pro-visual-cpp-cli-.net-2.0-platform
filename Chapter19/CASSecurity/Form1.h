#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::IO;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

using namespace System::Security;
using namespace System::Security::Permissions;


namespace CASSecurity 
{

    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();

            try
            {
                (gcnew FileIOPermission(FileIOPermissionAccess::Read, "C:\\"))->Demand();
            }
            catch(Exception^)
            {
                bnReadFile->Enabled = false;
            }

            try
            {
                (gcnew FileIOPermission(FileIOPermissionAccess::Write, "C:\\"))->Demand();
            }
            catch(Exception^)
            {
                bnWriteFile->Enabled = false;
            }
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
        System::Windows::Forms::Label^  lbOutput;
        System::Windows::Forms::Button^  bnWriteFile;
        System::Windows::Forms::Button^  bnReadFile;
        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->lbOutput = (gcnew System::Windows::Forms::Label());
            this->bnWriteFile = (gcnew System::Windows::Forms::Button());
            this->bnReadFile = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // lbOutput
            // 
            this->lbOutput->AutoSize = true;
            this->lbOutput->Location = System::Drawing::Point(68, 71);
            this->lbOutput->Name = L"lbOutput";
            this->lbOutput->Size = System::Drawing::Size(0, 13);
            this->lbOutput->TabIndex = 5;
            // 
            // bnWriteFile
            // 
            this->bnWriteFile->Location = System::Drawing::Point(170, 30);
            this->bnWriteFile->Name = L"bnWriteFile";
            this->bnWriteFile->Size = System::Drawing::Size(75, 23);
            this->bnWriteFile->TabIndex = 4;
            this->bnWriteFile->Text = L"Write File";
            this->bnWriteFile->UseVisualStyleBackColor = true;
            this->bnWriteFile->Click += 
                gcnew System::EventHandler(this, &Form1::bnWriteFile_Click);
            // 
            // bnReadFile
            // 
            this->bnReadFile->Location = System::Drawing::Point(48, 30);
            this->bnReadFile->Name = L"bnReadFile";
            this->bnReadFile->Size = System::Drawing::Size(75, 23);
            this->bnReadFile->TabIndex = 3;
            this->bnReadFile->Text = L"Read File";
            this->bnReadFile->UseVisualStyleBackColor = true;
            this->bnReadFile->Click += 
                gcnew System::EventHandler(this, &Form1::bnReadFile_Click);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(292, 110);
            this->Controls->Add(this->lbOutput);
            this->Controls->Add(this->bnWriteFile);
            this->Controls->Add(this->bnReadFile);
            this->Name = L"Form1";
            this->Text = L"CAS Security Test";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: 
        System::Void bnReadFile_Click(System::Object^ sender, 
                                      System::EventArgs^ e) 
        {
            StreamReader ^sr = File::OpenText("C:\\TestFile.txt");
            String ^s = sr->ReadLine();
            sr->Close();
            lbOutput->Text = s;        
       }

    private: 
        System::Void bnWriteFile_Click(System::Object^ sender, 
                                       System::EventArgs^ e) 
        {
            StreamWriter ^sw = File::CreateText("C:\\TestFile.txt");
            sw->WriteLine("This is a test. This is only a test.");
            sw->Close();
            lbOutput->Text = "Wrote text to file.";        
        }
    };
}

