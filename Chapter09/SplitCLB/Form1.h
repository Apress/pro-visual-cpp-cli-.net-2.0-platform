#pragma once

namespace SplitCLB 
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

            array<Object^>^ Items = gcnew array<Object^> { 
                "Appleman", "Challa",    "Chand",    "Cornell",
                "Fraser",   "Gunnerson", "Harris",   "Rammer", 
                "Symmonds", "Thomsen",   "Troelsen", "Vaughn" 
            };
            clBox->Items->AddRange(Items);
            lBox->Items->AddRange(Items);

            // Create a Check box for each entry in Items array.
            cBox = gcnew array<CheckBox^>(Items->Length); 
            
            int j = cBox->Length/2;
            for (int i = 0; i < j; i++)
            {
                // Build Left Column
                cBox[i] = gcnew CheckBox();
                cBox[i]->Location = Drawing::Point(50, 160+(30*i)); 
                cBox[i]->TabIndex = i+2; 
                cBox[i]->Text = Items[i]->ToString(); 
                cBox[i]->CheckStateChanged += 
                    gcnew EventHandler(this, &Form1::cBox_CheckStateChanged); 
                
                // Build Right Column
                cBox[i+j] = gcnew CheckBox();
                cBox[i+j]->Location = Drawing::Point(180, 160+(30*i)); 
                cBox[i+j]->TabIndex = i+j+2; 
                cBox[i+j]->Text = Items[i+j]->ToString(); 
                cBox[i+j]->CheckStateChanged += 
                    gcnew EventHandler(this, &Form1::cBox_CheckStateChanged); 
            }
            // Add all CheckBoxes to Form
            Controls->AddRange(cBox);
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
        System::Windows::Forms::ListBox^  lBox;
        System::Windows::Forms::CheckedListBox^  clBox;

        array<CheckBox^>^ cBox; 

        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->lBox = (gcnew System::Windows::Forms::ListBox());
            this->clBox = (gcnew System::Windows::Forms::CheckedListBox());
            this->SuspendLayout();
            // 
            // lBox
            // 
            this->lBox->FormattingEnabled = true;
            this->lBox->Location = System::Drawing::Point(356, 32);
            this->lBox->Name = L"lBox";
            this->lBox->Size = System::Drawing::Size(120, 264);
            this->lBox->TabIndex = 3;
            this->lBox->SelectedIndexChanged += 
                gcnew System::EventHandler(this, 
                                           &Form1::lBox_SelectedIndexChanged);
            // 
            // clBox
            // 
            this->clBox->FormattingEnabled = true;
            this->clBox->Location = System::Drawing::Point(12, 32);
            this->clBox->MultiColumn = true;
            this->clBox->Name = L"clBox";
            this->clBox->Size = System::Drawing::Size(323, 79);
            this->clBox->TabIndex = 2;
            this->clBox->ThreeDCheckBoxes = true;
            this->clBox->SelectedIndexChanged += 
                gcnew System::EventHandler(this, 
                                           &Form1::clBox_SelectedIndexChanged);
            this->clBox->ItemCheck += 
                gcnew System::Windows::Forms::ItemCheckEventHandler(this, 
                                                     &Form1::clBox_ItemCheck);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(494, 392);
            this->Controls->Add(this->lBox);
            this->Controls->Add(this->clBox);
            this->Name = L"Form1";
            this->Text = L"Splitting The Check List Box";
            this->ResumeLayout(false);
        }

#pragma endregion

    private: 
        System::Void clBox_ItemCheck(System::Object^ sender, 
                                 System::Windows::Forms::ItemCheckEventArgs^ e)
        {
         // update state of CheckBox with same index as checked CheckedListBox
            cBox[e->Index]->CheckState = e->NewValue; 
        }

        System::Void clBox_SelectedIndexChanged(System::Object^ sender, 
                                                System::EventArgs^ e)
        {
         // update ListBox with same selected item in the CheckedListBox
            lBox->SelectedItem = clBox->SelectedItem->ToString(); 
        }

        System::Void lBox_SelectedIndexChanged(System::Object^ sender, 
                                               System::EventArgs^ e)
        {
         // update CheckedListBox with same selected item in the ListBox
            clBox->SelectedItem = lBox->SelectedItem; 
        }

        void cBox_CheckStateChanged(Object^ sender, EventArgs^ e) 
        {
         // update state of CheckedListBox with same index as checked CheckBox
            CheckBox^ cb = (CheckBox^)sender;
            clBox->SetItemCheckState(Array::IndexOf(cBox, cb), cb->CheckState);
        }
    };
}

