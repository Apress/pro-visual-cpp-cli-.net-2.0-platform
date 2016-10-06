#pragma once

namespace RichText 
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
            BuildLabels();
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
        System::Windows::Forms::RichTextBox^  rtBox;

        array<System::Windows::Forms::Label^>^ labels; 

        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->rtBox = (gcnew System::Windows::Forms::RichTextBox());
            this->SuspendLayout();
            // 
            // rtBox
            // 
            this->rtBox->Anchor = 
                static_cast<System::Windows::Forms::AnchorStyles>
                ((((System::Windows::Forms::AnchorStyles::Top 
                | System::Windows::Forms::AnchorStyles::Bottom) 
                | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->rtBox->Location = System::Drawing::Point(0, 32);
            this->rtBox->Name = L"rtBox";
            this->rtBox->RightMargin = 900;
            this->rtBox->ScrollBars = 
                System::Windows::Forms::RichTextBoxScrollBars::ForcedVertical;
            this->rtBox->ShowSelectionMargin = true;
            this->rtBox->Size = System::Drawing::Size(950, 488);
            this->rtBox->TabIndex = 1;
            this->rtBox->Text = L"";
            this->rtBox->KeyDown += 
                gcnew System::Windows::Forms::KeyEventHandler(this, 
                                                       &Form1::rtBox_KeyDown);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(950, 520);
            this->Controls->Add(this->rtBox);
            this->Name = L"Form1";
            this->Text = L"(Very Simple Rich Text Editor)";
            this->ResumeLayout(false);
        }

#pragma endregion

        void BuildLabels()
        {
            array<String^>^ rtLabel = gcnew array<String^> {
                L"F1-Bold",   L"F2-Italics", L"F3-Underline",
                L"F4-Normal", L"F5-Red",     L"F6-Blue",
                L"F7-Green",  L"F8-Black",   L"F9-Load",    
                L"F10-Save"
            };
            labels = gcnew array<System::Windows::Forms::Label^>(10);

            // Build the labels
            for (int i = 0; i < labels->Length; i++)
            {
                labels[i] = gcnew Label();
                labels[i]->BackColor = SystemColors::ControlDark; 
                labels[i]->BorderStyle = BorderStyle::FixedSingle; 
                labels[i]->Location = Drawing::Point(5+(95*i), 8); 
                labels[i]->Size = Drawing::Size(85, 16); 
                labels[i]->Text = rtLabel[i]; 
                labels[i]->TextAlign = ContentAlignment::MiddleCenter; 
            }
            // Place labels on the Form
            Controls->AddRange(labels);
        }

        System::Void rtBox_KeyDown(System::Object^ sender, 
                                   System::Windows::Forms::KeyEventArgs^ e)
        {
            try
            {
                if (rtBox->SelectionLength > 0) 
                {
                    // Change selected text style
                    FontStyle fs;
                    switch (e->KeyCode) 
                    {
                        case Keys::F1: 
                            fs = FontStyle::Bold;                    
                            break; 
                        case Keys::F2: 
                            fs = FontStyle::Italic;                   
                            break; 
                        case Keys::F3: 
                            fs = FontStyle::Underline;
                            break; 
                        case Keys::F4: 
                            fs = FontStyle::Regular;
                            break; 
                    // Change selected text color
                        case Keys::F5: 
                            rtBox->SelectionColor = Color::Red; 
                            break; 
                        case Keys::F6: 
                            rtBox->SelectionColor = Color::Blue; 
                            break; 
                        case Keys::F7: 
                            rtBox->SelectionColor = Color::Green; 
                            break; 
                        case Keys::F8: 
                            rtBox->SelectionColor = Color::Black; 
                            break; 
                    }
                    // Do the actual change of the selected text style
                    if (e->KeyCode >= Keys::F1 && e->KeyCode <= Keys::F4)
                    {
                        rtBox->SelectionFont = gcnew Drawing::Font( 
                            rtBox->SelectionFont->FontFamily, 
                            rtBox->SelectionFont->Size, 
                            fs 
                        );
                    }
                }
                // Load hard coded Chapter01.rtf file
                else if (e->KeyCode == Keys::F9)
                {
                    rtBox->LoadFile("Chapter01.rtf");
                }
                // Save hard coded Chapter01.rtf file
                else if (e->KeyCode == Keys::F10)
                {
                    rtBox->SaveFile("Chapter01.rtf", 
                                    RichTextBoxStreamType::RichText);
                }
            }
            // Capture any blowups
            catch (Exception ^e)
            {
                MessageBox::Show(String::Format("Error: {0}", e->Message));
            }
        }
    };
}

