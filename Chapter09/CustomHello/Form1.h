#pragma once

namespace CustomHello 
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
        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->SuspendLayout();
            // 
            // Form1
            // 
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::Black;
            this->ClientSize = System::Drawing::Size(692, 274);
            this->Cursor = System::Windows::Forms::Cursors::UpArrow;
            this->FormBorderStyle = 
                System::Windows::Forms::FormBorderStyle::SizableToolWindow;
            this->Name = L"Form1";
            this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Show;
            this->Text = L"Custom Form";
            this->TopMost = true;
            this->ResumeLayout(false);
        }

#pragma endregion
    };
}

