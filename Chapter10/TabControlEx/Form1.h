#pragma once

namespace TabControlEx
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
        System::Windows::Forms::TabControl^  tabControl1;
        System::Windows::Forms::TabPage^  tabPage1;
        System::Windows::Forms::Label^  label2;
        System::Windows::Forms::TabPage^  tabPage2;
        System::Windows::Forms::Label^  label1;

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
		{
            this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
            this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->tabControl1->SuspendLayout();
            this->tabPage1->SuspendLayout();
            this->tabPage2->SuspendLayout();
            this->SuspendLayout();
            // 
            // tabControl1
            // 
            this->tabControl1->Alignment = 
                System::Windows::Forms::TabAlignment::Bottom;
            this->tabControl1->Controls->Add(this->tabPage1);
            this->tabControl1->Controls->Add(this->tabPage2);
            this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tabControl1->HotTrack = true;
            this->tabControl1->Location = System::Drawing::Point(0, 0);
            this->tabControl1->Multiline = true;
            this->tabControl1->Name = L"tabControl1";
            this->tabControl1->SelectedIndex = 0;
            this->tabControl1->ShowToolTips = true;
            this->tabControl1->Size = System::Drawing::Size(215, 129);
            this->tabControl1->TabIndex = 1;
            // 
            // tabPage1
            // 
            this->tabPage1->BackColor = System::Drawing::Color::PaleGreen;
            this->tabPage1->Controls->Add(this->label2);
            this->tabPage1->Location = System::Drawing::Point(4, 4);
            this->tabPage1->Name = L"tabPage1";
            this->tabPage1->Padding = System::Windows::Forms::Padding(3);
            this->tabPage1->Size = System::Drawing::Size(207, 103);
            this->tabPage1->TabIndex = 0;
            this->tabPage1->Text = L"Tab One";
            this->tabPage1->ToolTipText = L"This is tab one";
            this->tabPage1->UseVisualStyleBackColor = false;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(61, 44);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(78, 13);
            this->label2->TabIndex = 1;
            this->label2->Text = L"This is Tab One";
            // 
            // tabPage2
            // 
            this->tabPage2->BackColor = System::Drawing::Color::Plum;
            this->tabPage2->Controls->Add(this->label1);
            this->tabPage2->Location = System::Drawing::Point(4, 4);
            this->tabPage2->Name = L"tabPage2";
            this->tabPage2->Padding = System::Windows::Forms::Padding(3);
            this->tabPage2->Size = System::Drawing::Size(207, 103);
            this->tabPage2->TabIndex = 1;
            this->tabPage2->Text = L"Tab Two";
            this->tabPage2->ToolTipText = L"This is tab two";
            this->tabPage2->UseVisualStyleBackColor = false;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(61, 44);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(79, 13);
            this->label1->TabIndex = 0;
            this->label1->Text = L"This is Tab Two";
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(215, 129);
            this->Controls->Add(this->tabControl1);
            this->Name = L"Form1";
            this->Text = L"Tab Control Example";
            this->tabControl1->ResumeLayout(false);
            this->tabPage1->ResumeLayout(false);
            this->tabPage1->PerformLayout();
            this->tabPage2->ResumeLayout(false);
            this->tabPage2->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion
	};
}


