#pragma once

namespace TooManyButtons 
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
        System::Windows::Forms::Button^  TooMany;

        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->TooMany = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // TooMany
            // 
            this->TooMany->Location = System::Drawing::Point(12, 12);
            this->TooMany->Name = L"TooMany";
            this->TooMany->Size = System::Drawing::Size(75, 23);
            this->TooMany->TabIndex = 1;
            this->TooMany->Text = L"Click Me!";
            this->TooMany->Click += 
                gcnew System::EventHandler(this, &Form1::TooMany_Click);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->AutoScroll = true;
            this->ClientSize = System::Drawing::Size(292, 273);
            this->Controls->Add(this->TooMany);
            this->Name = L"Form1";
            this->Text = L"Too Many Buttons";
            this->ResumeLayout(false);
        }

#pragma endregion

    private: 
        System::Void TooMany_Click(System::Object^ sender, 
                                   System::EventArgs^ e)
        {
            // Grab the location of the button that was clicked
            Point p = ((Button^)sender)->Location; 

            // Create a dynamic button
            Button ^Many = gcnew Button(); 
            Many->Location = Drawing::Point(p.X + 36, p.Y + 26); 
            Many->Text = L"Click Me!"; 
            Many->Click += gcnew System::EventHandler(this, 
                                                      &Form1::TooMany_Click); 
            // Add dynamic button to Form
            Controls->Add(Many); 
        }
    };
}
