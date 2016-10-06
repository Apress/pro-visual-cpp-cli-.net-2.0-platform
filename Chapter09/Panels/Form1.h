#pragma once

namespace Panels 
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
        System::Windows::Forms::Panel^  Rightpanel;
        System::Windows::Forms::Button^  button2;
        System::Windows::Forms::Button^  button1;
        System::Windows::Forms::Panel^  Leftpanel;
        System::Windows::Forms::Button^  bnHide;
        System::Windows::Forms::Button^  bnDisable;

        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->Rightpanel = (gcnew System::Windows::Forms::Panel());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->Leftpanel = (gcnew System::Windows::Forms::Panel());
            this->bnHide = (gcnew System::Windows::Forms::Button());
            this->bnDisable = (gcnew System::Windows::Forms::Button());
            this->Rightpanel->SuspendLayout();
            this->Leftpanel->SuspendLayout();
            this->SuspendLayout();
            // 
            // Rightpanel
            // 
            this->Rightpanel->AutoScroll = true;
            this->Rightpanel->BorderStyle = 
                System::Windows::Forms::BorderStyle::Fixed3D;
            this->Rightpanel->Controls->Add(this->button2);
            this->Rightpanel->Controls->Add(this->button1);
            this->Rightpanel->Location = System::Drawing::Point(161, 22);
            this->Rightpanel->Name = L"Rightpanel";
            this->Rightpanel->Size = System::Drawing::Size(121, 60);
            this->Rightpanel->TabIndex = 3;
            // 
            // button2
            // 
            this->button2->Location = System::Drawing::Point(20, 62);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(75, 23);
            this->button2->TabIndex = 1;
            this->button2->Text = L"button 2";
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(20, 7);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(75, 23);
            this->button1->TabIndex = 0;
            this->button1->Text = L"button 1";
            // 
            // Leftpanel
            // 
            this->Leftpanel->BorderStyle = 
                System::Windows::Forms::BorderStyle::FixedSingle;
            this->Leftpanel->Controls->Add(this->bnHide);
            this->Leftpanel->Controls->Add(this->bnDisable);
            this->Leftpanel->Location = System::Drawing::Point(28, 22);
            this->Leftpanel->Name = L"Leftpanel";
            this->Leftpanel->Size = System::Drawing::Size(120, 95);
            this->Leftpanel->TabIndex = 2;
            // 
            // bnHide
            // 
            this->bnHide->Location = System::Drawing::Point(17, 62);
            this->bnHide->Name = L"bnHide";
            this->bnHide->Size = System::Drawing::Size(75, 23);
            this->bnHide->TabIndex = 1;
            this->bnHide->Text = L"Hide";
            this->bnHide->Click += 
                gcnew System::EventHandler(this, &Form1::bnHide_Click);
            // 
            // bnDisable
            // 
            this->bnDisable->Location = System::Drawing::Point(17, 7);
            this->bnDisable->Name = L"bnDisable";
            this->bnDisable->Size = System::Drawing::Size(75, 23);
            this->bnDisable->TabIndex = 0;
            this->bnDisable->Text = L"Disable";
            this->bnDisable->Click += 
                gcnew System::EventHandler(this, &Form1::bnDisable_Click);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(310, 139);
            this->Controls->Add(this->Rightpanel);
            this->Controls->Add(this->Leftpanel);
            this->Name = L"Form1";
            this->Text = L"A hidden fourth button";
            this->Rightpanel->ResumeLayout(false);
            this->Leftpanel->ResumeLayout(false);
            this->ResumeLayout(false);
        }

#pragma endregion

    private: 
        System::Void bnDisable_Click(System::Object^ sender, 
                                     System::EventArgs^ e)
        {
            Rightpanel->Enabled = !Rightpanel->Enabled;
        }

    private: 
        System::Void bnHide_Click(System::Object^ sender, System::EventArgs^ e)
        {
            Rightpanel->Visible = !Rightpanel->Visible;
        }
    };
}

