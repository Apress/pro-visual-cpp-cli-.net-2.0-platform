#pragma once

namespace FontsGalore 
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Drawing::Text;

    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();

            fonts = gcnew array<Drawing::Font^>(10);
            fontstr = gcnew array<String^>(10);

            // Used to generate random fonts
            array<float>^ sizes = gcnew array<float> { 
                10.0, 12.5, 16.0 
            };
            
            array<FontStyle>^ fontstyles = gcnew array<FontStyle> { 
                FontStyle::Regular, FontStyle::Bold, 
                FontStyle::Italic,
            (FontStyle)(FontStyle::Underline|FontStyle::Bold|FontStyle::Italic)
            };

            array<GraphicsUnit>^ units = gcnew array<GraphicsUnit> { 
                GraphicsUnit::Point, GraphicsUnit::Pixel 
            }; 

            // Get all fonts on computer
            InstalledFontCollection ^availFonts = 
                gcnew InstalledFontCollection();
            
            array<FontFamily^>^ fontfamilies = availFonts->Families;

            Random ^rand = gcnew Random();
            int ff, s, fs, u;
            
            for (int i = 0; i < fonts->Length; i++)
            {
                s  = rand->Next(0,3);
                fs = rand->Next(0,3);
                u  = rand->Next(0,2);

                // Not all fonts support every style
                do {
                    ff = rand->Next(0,fontfamilies->Length);
                }
                while (!fontfamilies[ff]->IsStyleAvailable(
                    (FontStyle)fontstyles[fs]));
                
                // Display string of font
                fontstr[i] = String::Format("{0} {1} {2}", 
                    fontfamilies[ff]->Name,
                    sizes[s],
                    String::Concat(fontstyles[fs], " ", 
                                   units[u]));

                // Create the font
                fonts[i] = gcnew Drawing::Font(fontfamilies[ff], sizes[s], 
                                            (FontStyle)fontstyles[fs],
                                            (GraphicsUnit)units[u]);
            }
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
        array<Drawing::Font^>^ fonts;
        array<String^>^ fontstr;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->SuspendLayout();
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(292, 273);
            this->Name = L"Form1";
            this->Text = L"Many Fonts";
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
            float lineloc = 0;
            for (int i = 0; i < fonts->Length; i++)
            {
                // Display font
                e->Graphics->DrawString(fontstr[i], fonts[i], Brushes::Black, 
                    10, lineloc);

                // Calculate the top of the next line
                lineloc += fonts[i]->Height;
            }
        }
    };
}