#pragma once


namespace SingleBuffering 
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
            X = -250;  // Preset to be just left of window
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
        System::Windows::Forms::Timer^  timer1;
        System::ComponentModel::IContainer^  components;

        float X;        // Actual x coordinate of Happy face


#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            this->timer1 = 
                (gcnew System::Windows::Forms::Timer(this->components));
            this->SuspendLayout();
            // 
            // timer1
            // 
            this->timer1->Enabled = true;
            this->timer1->Interval = 10;
            this->timer1->Tick += 
                gcnew System::EventHandler(this, &Form1::timer1_Tick);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(500, 300);
            this->Name = L"Form1";
            this->Text = L"Form1";
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
            Graphics^ g = e->Graphics;

            // Move image at end of line start from beginning
            if (X < ClientRectangle.Width)
                X += 1.0;
            else
                X = -250.0;

            g->TranslateTransform(X, 25.0);

            // redraw images from scratch
            Pen^ b4pen = gcnew Pen(Color::Black, 4);

            Drawing::Rectangle Head  = Drawing::Rectangle(0, 0, 250, 250);
            g->FillEllipse(Brushes::Yellow, Head);
            g->DrawEllipse(b4pen, Head);

            Drawing::Rectangle Mouth = Drawing::Rectangle(75, 150, 100, 50);
            g->FillPie(Brushes::White, Mouth,0,180);
            g->DrawPie(b4pen, Mouth, 0, 180);

            Drawing::Rectangle LEye  = Drawing::Rectangle(75, 75, 25, 25);
            g->FillEllipse(Brushes::White, LEye);
            g->DrawEllipse(b4pen, LEye);

            Drawing::Rectangle REye  = Drawing::Rectangle(150, 75, 25, 25);
            g->FillEllipse(Brushes::White, REye);
            g->DrawEllipse(b4pen, REye);

            delete b4pen;
        }

        System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
        {
            // Move the image
            Invalidate();
       }
   };
}

