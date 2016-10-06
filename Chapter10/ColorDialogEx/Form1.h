#pragma once


namespace ColorDialogEx {

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
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(292, 273);
            this->Name = L"Form1";
            this->Text = L"Common Color Dialog - Click Form";
            this->Click += 
                gcnew System::EventHandler(this, &Form1::Form1_Click);
            this->ResumeLayout(false);

        }
#pragma endregion

    private: 
        System::Void Form1_Click(System::Object^ sender, System::EventArgs^ e) 
        {
            ColorDialog^ colordialog = gcnew ColorDialog();
        
            if (colordialog->ShowDialog() == 
                System::Windows::Forms::DialogResult::OK)
            {
                BackColor = colordialog->Color;
            }
        }
    };
}

