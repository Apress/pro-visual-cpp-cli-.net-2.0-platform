#pragma once

namespace DrawingLines 
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Drawing::Drawing2D;

    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();

            pen = gcnew array<Pen^>(5);

            // a one unit width black pen
            pen[0] = Pens::Black;

            // a one unit with purple pen broken with dashes
            pen[1] = gcnew Pen(Color::Purple);
            pen[1]->DashStyle = DashStyle::Dash;

            // a 4 unit width chocolate pen
            pen[2] = gcnew Pen(Color::Chocolate, 4);
            
            // A 8 width royalblue pen made of three lines narrow wide narrow
            pen[3] = gcnew Pen(Color::RoyalBlue, 10);
            array<float>^ cArray = gcnew array<float> { 
                0.0f, 0.1f, 0.3f, 0.7f, 0.9f, 1.0f 
            }; 
            pen[3]->CompoundArray = cArray;

            // a 5 width tomato pen with dimond start and round end anchors
            pen[4] = gcnew Pen(Color::Tomato, 5);
            pen[4]->StartCap = LineCap::DiamondAnchor;
            pen[4]->EndCap = LineCap::RoundAnchor;
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
        array<Pen^>^ pen;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->SuspendLayout();
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(292, 273);
            this->Name = L"Form1";
            this->Text = L"Drawing Some lines";
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
            Random ^rand = gcnew Random();

            for (int i = 0; i < 10; i++)
            {
                e->Graphics->DrawLine(pen[i%5], rand->Next(0,299), 
                    rand->Next(0,299), rand->Next(0,299), rand->Next(0,299));
            }
        }
    };
}

