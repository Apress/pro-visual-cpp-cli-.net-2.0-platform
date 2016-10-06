#pragma once

namespace ListTransfers 
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
        System::Windows::Forms::ListBox^  LBDest;
        System::Windows::Forms::Button^  bnR2L;
        System::Windows::Forms::Button^  bnL2R;
        System::Windows::Forms::ListBox^  LBOrg;
        System::Windows::Forms::Label^  label2;
        System::Windows::Forms::Label^  label1;

        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->LBDest = (gcnew System::Windows::Forms::ListBox());
            this->bnR2L = (gcnew System::Windows::Forms::Button());
            this->bnL2R = (gcnew System::Windows::Forms::Button());
            this->LBOrg = (gcnew System::Windows::Forms::ListBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // LBDest
            // 
            this->LBDest->FormattingEnabled = true;
            this->LBDest->Location = System::Drawing::Point(213, 46);
            this->LBDest->Name = L"LBDest";
            this->LBDest->SelectionMode = 
                System::Windows::Forms::SelectionMode::MultiSimple;
            this->LBDest->Size = System::Drawing::Size(134, 134);
            this->LBDest->TabIndex = 10;
            this->LBDest->DoubleClick += 
                gcnew System::EventHandler(this, &Form1::LBDest_DoubleClick);
            // 
            // bnR2L
            // 
            this->bnR2L->Location = System::Drawing::Point(167, 108);
            this->bnR2L->Name = L"bnR2L";
            this->bnR2L->Size = System::Drawing::Size(33, 20);
            this->bnR2L->TabIndex = 9;
            this->bnR2L->Text = L"<==";
            this->bnR2L->Click += 
                gcnew System::EventHandler(this, &Form1::bnR2L_Click);
            // 
            // bnL2R
            // 
            this->bnL2R->Location = System::Drawing::Point(167, 80);
            this->bnL2R->Name = L"bnL2R";
            this->bnL2R->Size = System::Drawing::Size(33, 20);
            this->bnL2R->TabIndex = 8;
            this->bnL2R->Text = L"==>";
            this->bnL2R->Click += 
                gcnew System::EventHandler(this, &Form1::bnL2R_Click);
            // 
            // LBOrg
            // 
            this->LBOrg->FormattingEnabled = true;
            this->LBOrg->Items->AddRange(gcnew cli::array< System::Object^>(10)
                {L"System", L"System::Collections", L"System::Data", 
                 L"System::Drawing", L"System::IO", L"System::Net", 
                 L"System::Threading", L"System::Web", 
                 L"System::Windows::Forms", L"System::Xml"});
            this->LBOrg->Location = System::Drawing::Point(20, 46);
            this->LBOrg->Name = L"LBOrg";
            this->LBOrg->SelectionMode = 
                System::Windows::Forms::SelectionMode::MultiExtended;
            this->LBOrg->Size = System::Drawing::Size(133, 134);
            this->LBOrg->Sorted = true;
            this->LBOrg->TabIndex = 6;
            this->LBOrg->DoubleClick += 
                gcnew System::EventHandler(this, &Form1::LBOrg_DoubleClick);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(213, 17);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(104, 13);
            this->label2->TabIndex = 7;
            this->label2->Text = L"Unsorted Multisimple";
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(20, 17);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(107, 13);
            this->label1->TabIndex = 5;
            this->label1->Text = L"Sorted Multiextended";
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(367, 196);
            this->Controls->Add(this->LBDest);
            this->Controls->Add(this->bnR2L);
            this->Controls->Add(this->bnL2R);
            this->Controls->Add(this->LBOrg);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Name = L"Form1";
            this->Text = L"List Box Transfers";
            this->ResumeLayout(false);
            this->PerformLayout();
        }

#pragma endregion
    
    private: 
        System::Void LBOrg_DoubleClick(System::Object^ sender, 
                                       System::EventArgs^ e)
        {
            // Add Selected item to other ListBox 
            // Then remove item from original
            if (LBOrg->SelectedItem != nullptr)
            {
                LBDest->Items->Add(LBOrg->SelectedItem); 
                LBOrg->Items->Remove(LBOrg->SelectedItem); 
            }
        }

        System::Void LBDest_DoubleClick(System::Object^ sender, 
                                        System::EventArgs^ e)
        {
            // Add Selected item to other ListBox 
            // Then remove item from original
            if (LBDest->SelectedItem != nullptr)
            {
                LBOrg->Items->Add(LBDest->SelectedItem); 
                LBDest->Items->Remove(LBDest->SelectedItem); 
            }
        }

        System::Void bnL2R_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // Add all Selected items to other ListBox 
            // Then remove the all items from original
            array<Object^>^ tmp = 
                gcnew array<Object^>(LBOrg->SelectedItems->Count); 
            LBOrg->SelectedItems->CopyTo(tmp, 0); 
            LBDest->Items->AddRange(tmp); 
            for (int i = 0; i < tmp->Length; i++) 
                LBOrg->Items->Remove(tmp[i]); 
        }

        System::Void bnR2L_Click(System::Object^ sender, System::EventArgs^ e)
        {
             // Add all Selected items to other ListBox 
            // Then remove all the items from original
            array<Object^>^ tmp = 
                gcnew array<Object^>(LBDest->SelectedItems->Count);
            LBDest->SelectedItems->CopyTo(tmp, 0); 
            LBOrg->Items->AddRange(tmp); 
            for (int i = 0; i < tmp->Length; i++) 
                LBDest->Items->Remove(tmp[i]); 
       }
    };
}