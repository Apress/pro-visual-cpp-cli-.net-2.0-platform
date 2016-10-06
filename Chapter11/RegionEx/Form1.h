#pragma once

namespace RegionEx {

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

            Drawing::Point point1 = Drawing::Point(25,25);
            Drawing::Point point2 = Drawing::Point(100,100);
            Drawing::Size size    = Drawing::Size(200, 150);
            Rectangle rect1       = Drawing::Rectangle(point1, size); 
            Rectangle rect2       = Drawing::Rectangle(point2, size);

            region = gcnew Drawing::Region(rect1);
            region->Xor(rect2);
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
        Drawing::Region ^region;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->SuspendLayout();
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(322, 273);
            this->Name = L"Form1";
            this->Text = L"Filling A Region";
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
            e->Graphics->FillRegion(Brushes::Blue, region);
        }
    };
}

