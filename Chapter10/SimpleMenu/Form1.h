#pragma once


namespace SimpleMenu {

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
        System::Windows::Forms::ToolStripContainer^  toolStripContainer1;
        System::Windows::Forms::MenuStrip^  mainMenuStrip;
        System::Windows::Forms::ToolStripMenuItem^  miFile;
        System::Windows::Forms::ToolStripMenuItem^  miFileSub;
        System::Windows::Forms::ToolStripComboBox^  miFileSubThis;
        System::Windows::Forms::ToolStripMenuItem^  miFileExit;
        System::Windows::Forms::ToolStripMenuItem^  miFileSubCheck;
        System::Windows::Forms::ToolStripMenuItem^  miFileSubImage;
        System::Windows::Forms::ToolStripMenuItem^  miFileSubSayBoo;
        System::Windows::Forms::ToolStripMenuItem^  miHelp;
        System::Windows::Forms::ToolStripMenuItem^  miHelpAbout;
        System::Windows::Forms::ToolStripSeparator^  miFileSep1;

        System::ComponentModel::IContainer^  components;

    private:

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources =
       (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
            this->toolStripContainer1 = 
                (gcnew System::Windows::Forms::ToolStripContainer());
            this->mainMenuStrip = (gcnew System::Windows::Forms::MenuStrip());
            this->miFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->miFileSub = 
                (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->miFileSubThis = 
                (gcnew System::Windows::Forms::ToolStripComboBox());
            this->miFileSubCheck = 
                (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->miFileSubImage = 
                (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->miFileSubSayBoo = 
                (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->miFileSep1 = 
                (gcnew System::Windows::Forms::ToolStripSeparator());
            this->miFileExit = 
                (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->miHelp = 
                (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->miHelpAbout = 
                (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->toolStripContainer1->TopToolStripPanel->SuspendLayout();
            this->toolStripContainer1->SuspendLayout();
            this->mainMenuStrip->SuspendLayout();
            this->SuspendLayout();
            // 
            // toolStripContainer1
            // 
            // 
            // toolStripContainer1.ContentPanel
            // 
            this->toolStripContainer1->ContentPanel->Size = 
                System::Drawing::Size(292, 249);
            this->toolStripContainer1->Dock = 
                System::Windows::Forms::DockStyle::Fill;
            this->toolStripContainer1->Location = System::Drawing::Point(0, 0);
            this->toolStripContainer1->Name = L"toolStripContainer1";
            this->toolStripContainer1->Size = System::Drawing::Size(292, 273);
            this->toolStripContainer1->TabIndex = 0;
            this->toolStripContainer1->Text = L"toolStripContainer1";
            // 
            // toolStripContainer1.TopToolStripPanel
            // 
            this->toolStripContainer1->TopToolStripPanel->Controls->Add(
                this->mainMenuStrip);
            // 
            // mainMenuStrip
            // 
            this->mainMenuStrip->Dock =System::Windows::Forms::DockStyle::None;
            this->mainMenuStrip->Items->AddRange(
                gcnew cli::array< System::Windows::Forms::ToolStripItem^>(2) 
                {this->miFile, this->miHelp});
            this->mainMenuStrip->Location = System::Drawing::Point(0, 0);
            this->mainMenuStrip->Name = L"mainMenuStrip";
            this->mainMenuStrip->Size = System::Drawing::Size(292, 24);
            this->mainMenuStrip->TabIndex = 0;
            this->mainMenuStrip->Text = L"menuStrip1";
            // 
            // miFile
            // 
            this->miFile->DropDownItems->AddRange(
                gcnew cli::array< System::Windows::Forms::ToolStripItem^>(3) 
               {this->miFileSub, this->miFileSep1, this->miFileExit});
            this->miFile->Name = L"miFile";
            this->miFile->Size = System::Drawing::Size(35, 20);
            this->miFile->Text = L"&File";
            // 
            // miFileSub
            // 
            this->miFileSub->DropDownItems->AddRange(
                gcnew cli::array< System::Windows::Forms::ToolStripItem^>(4) 
                {this->miFileSubThis, this->miFileSubCheck, 
                 this->miFileSubImage, this->miFileSubSayBoo});
            this->miFileSub->Name = L"miFileSub";
            this->miFileSub->Size = System::Drawing::Size(152, 22);
            this->miFileSub->Text = L"&Sub";
            // 
            // miFileSubThis
            // 
            this->miFileSubThis->Items->AddRange(
                gcnew cli::array< System::Object^>(3) 
                {L"This", L"That", L"Other Thing"});
            this->miFileSubThis->Name = L"miFileSubThis";
            this->miFileSubThis->Size = System::Drawing::Size(121, 21);
            // 
            // miFileSubCheck
            // 
            this->miFileSubCheck->Checked = true;
            this->miFileSubCheck->CheckOnClick = true;
            this->miFileSubCheck->CheckState = 
                System::Windows::Forms::CheckState::Checked;
            this->miFileSubCheck->Name = L"miFileSubCheck";
            this->miFileSubCheck->Size = System::Drawing::Size(181, 22);
            this->miFileSubCheck->Text = L"Check Me";
            // 
            // miFileSubImage
            // 
            this->miFileSubImage->Image = 
                (cli::safe_cast<System::Drawing::Image^>
                (resources->GetObject(L"miFileSubImage.Image")));
            this->miFileSubImage->Name = L"miFileSubImage";
            this->miFileSubImage->Size = System::Drawing::Size(181, 22);
            this->miFileSubImage->Text = L"I have an image";
            // 
            // miFileSubSayBoo
            // 
            this->miFileSubSayBoo->Name = L"miFileSubSayBoo";
            this->miFileSubSayBoo->ShortcutKeys = 
                static_cast<System::Windows::Forms::Keys>
                ((System::Windows::Forms::Keys::Control | 
                  System::Windows::Forms::Keys::S));
            this->miFileSubSayBoo->Size = System::Drawing::Size(181, 22);
            this->miFileSubSayBoo->Text = L"Say Boo";
            this->miFileSubSayBoo->Click += 
                gcnew System::EventHandler(this,&Form1::miFileSubSayBoo_Click);
            // 
            // miFileSep1
            // 
            this->miFileSep1->Name = L"miFileSep1";
            this->miFileSep1->Size = System::Drawing::Size(149, 6);
            // 
            // miFileExit
            // 
            this->miFileExit->Name = L"miFileExit";
            this->miFileExit->Size = System::Drawing::Size(152, 22);
            this->miFileExit->Text = L"E&xit";
            this->miFileExit->Click += 
                gcnew System::EventHandler(this, &Form1::miFileExit_Click);
            // 
            // miHelp
            // 
            this->miHelp->DropDownItems->AddRange(
                gcnew cli::array< System::Windows::Forms::ToolStripItem^>(1) 
                {this->miHelpAbout});
            this->miHelp->Name = L"miHelp";
            this->miHelp->Size = System::Drawing::Size(40, 20);
            this->miHelp->Text = L"&Help";
            // 
            // miHelpAbout
            // 
            this->miHelpAbout->Name = L"miHelpAbout";
            this->miHelpAbout->Size = System::Drawing::Size(152, 22);
            this->miHelpAbout->Text = L"About";
            this->miHelpAbout->Click += 
                gcnew System::EventHandler(this, &Form1::miHelpAbout_Click);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(292, 273);
            this->Controls->Add(this->toolStripContainer1);
            this->MainMenuStrip = this->mainMenuStrip;
            this->Name = L"Form1";
            this->Text = L"Simple Menu";
            this->toolStripContainer1->TopToolStripPanel->ResumeLayout(false);
            this->toolStripContainer1->TopToolStripPanel->PerformLayout();
            this->toolStripContainer1->ResumeLayout(false);
            this->toolStripContainer1->PerformLayout();
            this->mainMenuStrip->ResumeLayout(false);
            this->mainMenuStrip->PerformLayout();
            this->ResumeLayout(false);
        }
#pragma endregion

    private: 
        System::Void miFileExit_Click(System::Object^ sender, 
                                      System::EventArgs^ e)
        {
             Application::Exit();
        }

        System::Void miHelpAbout_Click(System::Object^ sender, 
                                       System::EventArgs^ e)
        {
            MessageBox::Show("Simple Menu v.1.0.0.0");
        }

        System::Void miFileSubSayBoo_Click(System::Object^ sender, 
                                           System::EventArgs^ e)
        {
            MessageBox::Show("BOO");
        }
    };
}

