#pragma once

namespace GroupingRadios 
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
            BuildRadios();
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
        System::Windows::Forms::GroupBox^  groupBox2;
        System::Windows::Forms::GroupBox^  groupBox1;

        array<System::Windows::Forms::RadioButton^>^ radio1; 
        array<System::Windows::Forms::RadioButton^>^ radio2; 
        array<System::Windows::Forms::RadioButton^>^ radio3; 

        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->SuspendLayout();
            // 
            // groupBox2
            // 
            this->groupBox2->Location = System::Drawing::Point(125, 153);
            this->groupBox2->Name = L"groupBox2";
            this->groupBox2->Size = System::Drawing::Size(152, 134);
            this->groupBox2->TabIndex = 3;
            this->groupBox2->TabStop = false;
            this->groupBox2->Text = L"Use";
            // 
            // groupBox1
            // 
            this->groupBox1->Location = System::Drawing::Point(125, 12);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = System::Drawing::Size(152, 135);
            this->groupBox1->TabIndex = 2;
            this->groupBox1->TabStop = false;
            this->groupBox1->Text = L"You";
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(352, 330);
            this->Controls->Add(this->groupBox2);
            this->Controls->Add(this->groupBox1);
            this->Name = L"Form1";
            this->Text = L"Using Group Boxes";
            this->ResumeLayout(false);
        }

#pragma endregion

        void BuildRadios()
        {
            this->SuspendLayout();
            
            // Text for RadioButton places on Form directly
            array<String^>^ rbText1 = gcnew array<String^> {
                L"Can", L"You", L"Click", L"More", L"Than", L"One"
            };

            // Build a RadioButton for each rbText1
            radio1 = gcnew array<RadioButton^>(6); 
            for (int i = 0; i < radio1->Length; i++)
            {
                radio1[i] = gcnew RadioButton();
                radio1[i]->Location = Drawing::Point(20, 20+(40*i)); 
                radio1[i]->Text = rbText1[i]; 
            }
            // Add RadioButtons to Form
            Controls->AddRange(radio1);

            // Text for RadioButton places in first GroupBox
            array<String^>^ rbText2 = gcnew array<String^> {
                L"Can", L"If", L"You"
            };
            
            // Build a RadioButton for each rbText2
            radio2 = gcnew array<RadioButton^>(3); 
            for (int i = 0; i < radio2->Length; i++)
            {
                radio2[i] = gcnew RadioButton();
                radio2[i]->Location = Drawing::Point(40, 30+(35*i)); 
                radio2[i]->Text = rbText2[i]; 
            }
            // Add RadioButtons to GroupBox
            groupBox1->Controls->AddRange(radio2);
            
            // Text for RadioButton places in second GroupBox
            array<String^>^ rbText3 = gcnew array<String^> {
                L"Different", L"Group", L"Boxes"
            };

            // Build a RadioButton for each rbText3
            radio3 = gcnew array<RadioButton^>(3); 
            for (int i = 0; i < radio3->Length; i++)
            {
                radio3[i] = gcnew RadioButton();
                radio3[i]->Location = Drawing::Point(40, 30+(35*i)); 
                radio3[i]->Text = rbText3[i]; 
            }
            // Add RadioButtons to GroupBox2
            groupBox2->Controls->AddRange(radio3);

            this->ResumeLayout(false);
        }
    };
}