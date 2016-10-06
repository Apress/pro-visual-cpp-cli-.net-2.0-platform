#pragma once


namespace StatusStripEx {

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
        System::Windows::Forms::ToolStripContainer^  tsContainer;
        System::Windows::Forms::StatusStrip^  statusStrip1;
        System::Windows::Forms::ToolStripStatusLabel^  statusButtons;
        System::Windows::Forms::ToolStripStatusLabel^  statusXCoord;
        System::Windows::Forms::ToolStripStatusLabel^  statusYCoord;

        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->tsContainer = 
                (gcnew System::Windows::Forms::ToolStripContainer());
            this->statusStrip1 = 
                (gcnew System::Windows::Forms::StatusStrip());
            this->statusButtons = 
                (gcnew System::Windows::Forms::ToolStripStatusLabel());
            this->statusXCoord = 
                (gcnew System::Windows::Forms::ToolStripStatusLabel());
            this->statusYCoord = 
                (gcnew System::Windows::Forms::ToolStripStatusLabel());
            this->tsContainer->BottomToolStripPanel->SuspendLayout();
            this->tsContainer->SuspendLayout();
            this->statusStrip1->SuspendLayout();
            this->SuspendLayout();
            // 
            // tsContainer
            // 
            // 
            // tsContainer.BottomToolStripPanel
            // 
            this->tsContainer->BottomToolStripPanel->Controls->Add(
                this->statusStrip1);
            // 
            // tsContainer.ContentPanel
            // 
            this->tsContainer->ContentPanel->Size = 
                System::Drawing::Size(292, 251);
            this->tsContainer->ContentPanel->MouseDown += 
                gcnew System::Windows::Forms::MouseEventHandler(this, 
                &Form1::tsContainer_ContentPanel_MouseDown);
            this->tsContainer->ContentPanel->MouseMove += 
                gcnew System::Windows::Forms::MouseEventHandler(this, 
                &Form1::tsContainer1_ContentPanel_MouseMove);
            this->tsContainer->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tsContainer->Location = System::Drawing::Point(0, 0);
            this->tsContainer->Name = L"tsContainer";
            this->tsContainer->Size = System::Drawing::Size(292, 273);
            this->tsContainer->TabIndex = 0;
            this->tsContainer->Text = L"toolStripContainer1";
            // 
            // statusStrip1
            // 
            this->statusStrip1->Dock = System::Windows::Forms::DockStyle::None;
            this->statusStrip1->Items->AddRange(
                gcnew cli::array< System::Windows::Forms::ToolStripItem^>(3) 
                {this->statusButtons, this->statusXCoord, this->statusYCoord});
            this->statusStrip1->Location = System::Drawing::Point(0, 0);
            this->statusStrip1->Name = L"statusStrip1";
            this->statusStrip1->Size = System::Drawing::Size(292, 22);
            this->statusStrip1->TabIndex = 0;
            // 
            // statusButtons
            // 
            this->statusButtons->Name = L"statusButtons";
            this->statusButtons->Size = System::Drawing::Size(177, 17);
            this->statusButtons->Spring = true;
            this->statusButtons->TextAlign = 
                System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // statusXCoord
            // 
            this->statusXCoord->AutoSize = false;
            this->statusXCoord->BorderSides = 
            static_cast<System::Windows::Forms::ToolStripStatusLabelBorderSides>
            ((((System::Windows::Forms::ToolStripStatusLabelBorderSides::Left 
            | System::Windows::Forms::ToolStripStatusLabelBorderSides::Top) 
            | System::Windows::Forms::ToolStripStatusLabelBorderSides::Right) 
            | System::Windows::Forms::ToolStripStatusLabelBorderSides::Bottom));
            this->statusXCoord->BorderStyle = 
                System::Windows::Forms::Border3DStyle::Sunken;
            this->statusXCoord->Name = L"statusXCoord";
            this->statusXCoord->Size = System::Drawing::Size(50, 17);
            // 
            // statusYCoord
            // 
            this->statusYCoord->AutoSize = false;
            this->statusYCoord->BorderSides = 
            static_cast<System::Windows::Forms::ToolStripStatusLabelBorderSides>
            ((((System::Windows::Forms::ToolStripStatusLabelBorderSides::Left 
            | System::Windows::Forms::ToolStripStatusLabelBorderSides::Top) 
            | System::Windows::Forms::ToolStripStatusLabelBorderSides::Right) 
            | System::Windows::Forms::ToolStripStatusLabelBorderSides::Bottom));
            this->statusYCoord->BorderStyle = 
                System::Windows::Forms::Border3DStyle::Sunken;
            this->statusYCoord->Name = L"statusYCoord";
            this->statusYCoord->Size = System::Drawing::Size(50, 17);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(292, 273);
            this->Controls->Add(this->tsContainer);
            this->Name = L"Form1";
            this->Text = L"Status Strip Mouse Tracking";
            this->tsContainer->BottomToolStripPanel->ResumeLayout(false);
            this->tsContainer->BottomToolStripPanel->PerformLayout();
            this->tsContainer->ResumeLayout(false);
            this->tsContainer->PerformLayout();
            this->statusStrip1->ResumeLayout(false);
            this->statusStrip1->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion

private: 
        System::Void tsContainer_ContentPanel_MouseDown(System::Object^ sender, 
                                     System::Windows::Forms::MouseEventArgs^ e)
        {
           // clicked mouse button in first status bar panel
            if (e->Button == System::Windows::Forms::MouseButtons::Right) 
                statusButtons->Text = "Right"; 
            else if (e->Button == System::Windows::Forms::MouseButtons::Left) 
                statusButtons->Text = "Left"; 
            else 
                statusButtons->Text = "Middle"; 
         }

        System::Void tsContainer1_ContentPanel_MouseMove(System::Object^ sender, 
                                     System::Windows::Forms::MouseEventArgs^  e) 
        {
             // x,y coords in second and third status bar panels
            statusXCoord->Text = String::Format("X={0}", e->X); 
            statusYCoord->Text = String::Format("Y={0}", e->Y); 
        }
    };
}

