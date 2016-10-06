#pragma once

namespace OnPaintWhere 
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
            this->Text = L"Hello GDI+";
            this->Paint += 
                gcnew System::Windows::Forms::PaintEventHandler(this, 
                                                           &Form1::Form1_Paint);
            this->ResumeLayout(false);
        }
#pragma endregion

    protected:
        virtual void OnPaint(System::Windows::Forms::PaintEventArgs ^e) override
        {
//          Form::OnPaint(e);

            e->Graphics->DrawString("Hello GDI+", 
               gcnew Drawing::Font("Arial", 16), Brushes::Black, 75.0, 110.0);

            Form::OnPaint(e);
        }

    private: 
        System::Void Form1_Paint(System::Object^ sender,
                                 System::Windows::Forms::PaintEventArgs^ e)
        {
            e->Graphics->DrawString("Hello GDI+", 
                gcnew Drawing::Font("Arial", 16), Brushes::Purple, 75.0, 110.0);
        }
    };
}

