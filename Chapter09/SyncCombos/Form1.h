#pragma once

namespace SyncCombos 
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
            PopulateLists();
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
        System::Windows::Forms::ComboBox^  ddlist;
        System::Windows::Forms::ComboBox^  simple;
        System::Windows::Forms::ComboBox^  ddown;

        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->ddlist = (gcnew System::Windows::Forms::ComboBox());
            this->simple = (gcnew System::Windows::Forms::ComboBox());
            this->ddown = (gcnew System::Windows::Forms::ComboBox());
            this->SuspendLayout();
            // 
            // ddlist
            // 
            this->ddlist->DropDownStyle = 
                System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->ddlist->FormattingEnabled = true;
            this->ddlist->Location = System::Drawing::Point(300, 14);
            this->ddlist->Name = L"ddlist";
            this->ddlist->Size = System::Drawing::Size(121, 21);
            this->ddlist->TabIndex = 5;
            this->ddlist->SelectedIndexChanged += 
                gcnew System::EventHandler(this, &Form1::ddlist_Change);
            // 
            // simple
            // 
            this->simple->DropDownStyle = 
                System::Windows::Forms::ComboBoxStyle::Simple;
            this->simple->FormattingEnabled = true;
            this->simple->Location = System::Drawing::Point(154, 11);
            this->simple->Name = L"simple";
            this->simple->Size = System::Drawing::Size(122, 117);
            this->simple->TabIndex = 4;
            this->simple->SelectedIndexChanged += 
                gcnew System::EventHandler(this, &Form1::simple_Change);
            this->simple->TextChanged += 
                gcnew System::EventHandler(this, &Form1::simple_Change);
            // 
            // ddown
            // 
            this->ddown->FormattingEnabled = true;
            this->ddown->Location = System::Drawing::Point(12, 14);
            this->ddown->MaxDropDownItems = 3;
            this->ddown->MaxLength = 10;
            this->ddown->Name = L"ddown";
            this->ddown->Size = System::Drawing::Size(121, 21);
            this->ddown->TabIndex = 3;
            this->ddown->SelectedIndexChanged += 
                gcnew System::EventHandler(this, &Form1::ddown_Change);
            this->ddown->TextChanged += 
                gcnew System::EventHandler(this, &Form1::ddown_Change);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(433, 138);
            this->Controls->Add(this->ddlist);
            this->Controls->Add(this->simple);
            this->Controls->Add(this->ddown);
            this->Name = L"Form1";
            this->Text = L"Synchronized Combo boxing";
            this->ResumeLayout(false);
        }

#pragma endregion

    private:
        void PopulateLists()
        {
            // Item to be placed in all ComboBoxes
            array<Object^>^ ddItems = gcnew array<Object^> { 
                L"oranges", L"cherries", L"apples",
                L"lemons",  L"bananas",  L"grapes" 
            };
            ddown->Items->AddRange(ddItems);        
            simple->Items->AddRange(ddItems);        
            ddlist->Items->AddRange(ddItems);
        }

        System::Void ddown_Change(System::Object^ sender, System::EventArgs^ e)
        {
            // Update simple and dropdownlist with dropdown text
            simple->Text = ddown->Text; 
            ddlist->SelectedItem = ddown->Text; 
        }

        System::Void simple_Change(System::Object^ sender,System::EventArgs^ e)
        {
            // Update dropdown and dropdownlist with simple text
            ddown->Text = simple->Text; 
            ddlist->SelectedItem = simple->Text; 
        }

        System::Void ddlist_Change(System::Object^ sender,System::EventArgs^ e)
        {
            // Update simple and dropdown with dropdownlist SelectedText
            ddown->SelectedItem = ddlist->SelectedItem; 
            simple->SelectedItem = ddlist->SelectedItem; 
        }
    };
}

