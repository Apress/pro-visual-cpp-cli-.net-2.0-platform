#pragma once

namespace DoubleBuffering 
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
            this->SetStyle(ControlStyles::Opaque, true);

            dbBitmap = nullptr;
            dbGraphics = nullptr;
            X = -250;  // Preset to be just left of window

            Form1_Resize(nullptr, EventArgs::Empty);
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

        Bitmap^   dbBitmap;
        Graphics^ dbGraphics;
        int X;        // Actual x coordinate of Happy face

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
            this->Text = L"Sliding Happy Face";
            this->Paint += 
                gcnew System::Windows::Forms::PaintEventHandler(this, 
                                                         &Form1::Form1_Paint);
            this->Resize += 
                gcnew System::EventHandler(this, &Form1::Form1_Resize);
            this->ResumeLayout(false);

        }
#pragma endregion

    private: 
        System::Void Form1_Paint(System::Object^ sender, 
                                 System::Windows::Forms::PaintEventArgs^ e)
        {
             // Move image at end of line start from beginning
            if (X < ClientRectangle.Width)
            {
                X ++;
                dbGraphics->TranslateTransform(1.0, 0.0);
            }
            else
            {
                X = -250;
                dbGraphics->TranslateTransform(
                    (float)-(ClientRectangle.Width+250), 0.0);
            }

            // Clear background
            dbGraphics->Clear(Color::White);

            // redraw image from scratch
            Pen^ b4pen = gcnew Pen(Color::Black, 4);

            Drawing::Rectangle Head  = Drawing::Rectangle(0, 0, 250, 250);
            dbGraphics->FillEllipse(Brushes::Yellow, Head);
            dbGraphics->DrawEllipse(b4pen, Head);

            Drawing::Rectangle Mouth = Drawing::Rectangle(75, 150, 100, 50);
            dbGraphics->FillPie(Brushes::White, Mouth,0,180);
            dbGraphics->DrawPie(b4pen, Mouth, 0, 180);

            Drawing::Rectangle LEye  = Drawing::Rectangle(75, 75, 25, 25);
            dbGraphics->FillEllipse(Brushes::White, LEye);
            dbGraphics->DrawEllipse(b4pen, LEye);

            Drawing::Rectangle REye  = Drawing::Rectangle(150, 75, 25, 25);
            dbGraphics->FillEllipse(Brushes::White, REye);
            dbGraphics->DrawEllipse(b4pen, REye);

            // Make the buffer visible
            e->Graphics->DrawImageUnscaled(dbBitmap, 0, 0);

            delete b4pen;
        }

        System::Void Form1_Resize(System::Object^ sender, System::EventArgs^ e)
        {
             // Get rid of old stuff
            if (dbGraphics != nullptr)
            {
                delete dbGraphics;
            }

            if (dbBitmap != nullptr)
            {
                delete dbBitmap;
            }

            if (ClientRectangle.Width > 0 && ClientRectangle.Height > 0)
            {
                // Create a bitmap
                dbBitmap = gcnew Bitmap(ClientRectangle.Width,
                                        ClientRectangle.Height);

                // Grab its Graphics
                dbGraphics = Graphics::FromImage(dbBitmap);

                // Set up initial translation after resize (also at start)
                dbGraphics->TranslateTransform((float)X, 25.0);
            }
       }

        System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
        {
            // Move the image
            Invalidate();
       }
   };
}

