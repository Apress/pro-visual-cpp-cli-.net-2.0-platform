#pragma once


namespace CorrectingCoords 
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
            coords = gcnew ArrayList();  // Instantiate coords array
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
        ArrayList ^coords;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->SuspendLayout();
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(292, 273);
            this->Name = L"Form1";
            this->Text = L"Click and see coords";
            this->Paint += 
                gcnew System::Windows::Forms::PaintEventHandler(this, 
                                                          &Form1::Form1_Paint);
            this->MouseDown += 
                gcnew System::Windows::Forms::MouseEventHandler(this, 
                                                      &Form1::Form1_MouseDown);
            this->ResumeLayout(false);
        }
#pragma endregion

    private: 
        System::Void Form1_MouseDown(System::Object^ sender, 
                                     System::Windows::Forms::MouseEventArgs^ e)
        {
            coords->Add(Point(e->X, e->Y));
            Invalidate();
        }

    private: 
        System::Void Form1_Paint(System::Object^ sender, 
                                 System::Windows::Forms::PaintEventArgs^ e)
        {
            for each (Point^ p in coords)
            {
                 e->Graphics->DrawString(String::Format("({0},{1})",p->X,p->Y),
                    gcnew Drawing::Font("Courier New", 8),
                    Brushes::Black, (Single)p->X, (Single)p->Y);
            }
        }
    };
}

