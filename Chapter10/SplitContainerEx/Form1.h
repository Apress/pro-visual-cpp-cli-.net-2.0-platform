#pragma once

namespace SplitContainerEx
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
        System::Windows::Forms::SplitContainer^  splitContainer1;
        System::Windows::Forms::TextBox^  textBox1;
        System::Windows::Forms::SplitContainer^  splitContainer2;
        System::Windows::Forms::TextBox^  textBox2;
        System::Windows::Forms::TextBox^  textBox3;

        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->splitContainer1 = 
                (gcnew System::Windows::Forms::SplitContainer());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->splitContainer2 = 
                (gcnew System::Windows::Forms::SplitContainer());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->textBox3 = (gcnew System::Windows::Forms::TextBox());
            this->splitContainer1->Panel1->SuspendLayout();
            this->splitContainer1->Panel2->SuspendLayout();
            this->splitContainer1->SuspendLayout();
            this->splitContainer2->Panel1->SuspendLayout();
            this->splitContainer2->Panel2->SuspendLayout();
            this->splitContainer2->SuspendLayout();
            this->SuspendLayout();
            // 
            // splitContainer1
            // 
            this->splitContainer1->BackColor = System::Drawing::Color::Green;
            this->splitContainer1->Dock = 
                System::Windows::Forms::DockStyle::Fill;
            this->splitContainer1->Location = System::Drawing::Point(0, 0);
            this->splitContainer1->Name = L"splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this->splitContainer1->Panel1->Controls->Add(this->textBox1);
            // 
            // splitContainer1.Panel2
            // 
           this->splitContainer1->Panel2->Controls->Add(this->splitContainer2);
            this->splitContainer1->Size = System::Drawing::Size(292, 273);
            this->splitContainer1->SplitterDistance = 116;
            this->splitContainer1->TabIndex = 1;
            this->splitContainer1->Text = L"splitContainer1";
            // 
            // textBox1
            // 
            this->textBox1->AutoSize = false;
            this->textBox1->BorderStyle = 
                System::Windows::Forms::BorderStyle::None;
            this->textBox1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->textBox1->Location = System::Drawing::Point(0, 0);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(116, 273);
            this->textBox1->TabIndex = 0;
            this->textBox1->Text = L"Left Textbox";
            this->textBox1->TextAlign = 
                System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // splitContainer2
            // 
            this->splitContainer2->BackColor = System::Drawing::Color::Red;
            this->splitContainer2->Location = System::Drawing::Point(18, 82);
            this->splitContainer2->Name = L"splitContainer2";
            this->splitContainer2->Orientation = 
                System::Windows::Forms::Orientation::Horizontal;
            // 
            // splitContainer2.Panel1
            // 
            this->splitContainer2->Panel1->Controls->Add(this->textBox2);
            // 
            // splitContainer2.Panel2
            // 
            this->splitContainer2->Panel2->Controls->Add(this->textBox3);
            this->splitContainer2->Size = System::Drawing::Size(132, 102);
            this->splitContainer2->SplitterDistance = 42;
            this->splitContainer2->TabIndex = 0;
            this->splitContainer2->Text = L"splitContainer2";
            // 
            // textBox2
            // 
            this->textBox2->AutoSize = false;
            this->textBox2->BorderStyle = 
                System::Windows::Forms::BorderStyle::None;
            this->textBox2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->textBox2->Location = System::Drawing::Point(0, 0);
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(132, 42);
            this->textBox2->TabIndex = 0;
            this->textBox2->Text = L"Top Right Textbox";
            this->textBox2->TextAlign = 
                System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // textBox3
            // 
            this->textBox3->AutoSize = false;
            this->textBox3->BorderStyle = 
                System::Windows::Forms::BorderStyle::None;
            this->textBox3->Dock = System::Windows::Forms::DockStyle::Fill;
            this->textBox3->Location = System::Drawing::Point(0, 0);
            this->textBox3->Name = L"textBox3";
            this->textBox3->Size = System::Drawing::Size(132, 56);
            this->textBox3->TabIndex = 0;
            this->textBox3->Text = L"Bottom Right Textbox";
            this->textBox3->TextAlign = 
                System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(292, 273);
            this->Controls->Add(this->splitContainer1);
            this->Name = L"Form1";
            this->Text = L"Form1";
            this->splitContainer1->Panel1->ResumeLayout(false);
            this->splitContainer1->Panel2->ResumeLayout(false);
            this->splitContainer1->ResumeLayout(false);
            this->splitContainer2->Panel1->ResumeLayout(false);
            this->splitContainer2->Panel2->ResumeLayout(false);
            this->splitContainer2->ResumeLayout(false);
            this->ResumeLayout(false);
        }
#pragma endregion
    };
}


