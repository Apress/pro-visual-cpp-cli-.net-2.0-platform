#pragma once

namespace PrintHappyFace 
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
        System::Drawing::Printing::PrintDocument^  printDocument;
        System::Windows::Forms::PrintDialog^  printDialog;
        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->printDocument = 
                (gcnew System::Drawing::Printing::PrintDocument());
            this->printDialog = (gcnew System::Windows::Forms::PrintDialog());
            this->SuspendLayout();
            // 
            // printDocument
            // 
            this->printDocument->PrintPage += 
                gcnew System::Drawing::Printing::PrintPageEventHandler(this, 
                                             &Form1::printDocument_PrintPage);
            // 
            // printDialog
            // 
            this->printDialog->Document = this->printDocument;
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(300, 300);
            this->Name = L"Form1";
            this->Text = L"Click to Print";
            this->Paint += 
                gcnew System::Windows::Forms::PaintEventHandler(this, 
                                                         &Form1::Form1_Paint);
            this->Click += 
                gcnew System::EventHandler(this, &Form1::Form1_Click);
            this->ResumeLayout(false);
        }
#pragma endregion

    private: 
        System::Void Form1_Click(System::Object^ sender, System::EventArgs^ e)
        {
             // Display Print dialog when mouse pressed
            if (printDialog->ShowDialog() == Windows::Forms::DialogResult::OK)
            {
                printDocument->Print();
            }
        }

        System::Void printDocument_PrintPage(System::Object^ sender, 
                             System::Drawing::Printing::PrintPageEventArgs^ e)
        {
            CreateHappyFace(e->Graphics); //Same call as Form1_Paint
            e->HasMorePages = false;
        }

        System::Void Form1_Paint(System::Object^ sender, 
                                 System::Windows::Forms::PaintEventArgs^ e)
        {
            CreateHappyFace(e->Graphics);//Same call as printDocument_PrintPage
        }

        // Generic Happy Face Creator
        void CreateHappyFace(Graphics ^g)
        {
            Pen^ b4pen = gcnew Pen(Color::Black, 4);

            Rectangle rect = Drawing::Rectangle(25, 25, 250, 250);
            g->FillEllipse(Brushes::Yellow, rect);
            g->DrawEllipse(b4pen, rect);

            g->FillPie(Brushes::White, 100, 175, 100, 50, 0, 180);
            g->DrawPie(b4pen, 100, 175, 100, 50, 0, 180);

            rect = Drawing::Rectangle(100, 100, 25, 25);
            g->FillEllipse(Brushes::White, rect);
            g->DrawEllipse(b4pen, rect);

            rect = Drawing::Rectangle(175, 100, 25, 25);
            g->FillEllipse(Brushes::White, rect);
            g->DrawEllipse(b4pen, rect);

            delete b4pen;
        }
    };
}

