#pragma once

namespace DownwardStringRect 
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
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(300, 145);
            this->Name = L"Form1";
            this->Text = L"Downward String in a Rectangle";
            this->Paint += 
                gcnew System::Windows::Forms::PaintEventHandler(this, 
                                                         &Form1::Form1_Paint);
            this->ResumeLayout(false);
        }
#pragma endregion

    private: 
        System::Void Form1_Paint(System::Object^ sender, 
                                 System::Windows::Forms::PaintEventArgs^ e)
        {
            // create and configure the StringFormat object
            StringFormat ^stringformat = gcnew StringFormat();
            stringformat->FormatFlags  = StringFormatFlags::DirectionVertical;
            stringformat->Alignment    = StringAlignment::Center;

            // Draw the string
            e->Graphics->DrawString(
                "Let's draw a string to a rectangle and go a little "
                    "overboard on the size of the string that we place "
                    "inside of it",
                gcnew Drawing::Font(gcnew FontFamily("Arial"), 13),
                Brushes::Black, Drawing::RectangleF(20.0, 40.0, 250.0, 80.0),
                stringformat);
        }
    };
}

