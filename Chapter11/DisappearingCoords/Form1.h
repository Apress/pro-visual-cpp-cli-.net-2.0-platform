#pragma once

namespace DisappearingCoords 
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
            this->ClientSize = System::Drawing::Size(292, 273);
            this->Name = L"Form1";
            this->Text = L"Click and see coords";
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
            Graphics ^g = this->CreateGraphics();
            g->DrawString(String::Format("({0},{1})", e->X, e->Y), 
                gcnew Drawing::Font("Courier New", 8),
                Brushes::Black, (Single)e->X, (Single)e->Y);

            delete g;      // we delete of the Graphics object because we 
                           // created it with the CreateGraphics() method.
        }
    };
}

