#pragma once


namespace Invoking {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
    using namespace System::Reflection;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lbColor;
	protected: 
	private: System::Windows::Forms::ComboBox^  cbColor;

    private: array <PropertyInfo^>^ colors;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lbColor = (gcnew System::Windows::Forms::Label());
			this->cbColor = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// lbColor
			// 
			this->lbColor->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lbColor->Location = System::Drawing::Point(14, 42);
			this->lbColor->Name = L"lbColor";
			this->lbColor->Size = System::Drawing::Size(264, 62);
			this->lbColor->TabIndex = 3;
			this->lbColor->Text = L"None";
			this->lbColor->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// cbColor
			// 
			this->cbColor->FormattingEnabled = true;
			this->cbColor->Location = System::Drawing::Point(14, 14);
			this->cbColor->Name = L"cbColor";
			this->cbColor->Size = System::Drawing::Size(264, 21);
			this->cbColor->TabIndex = 2;
			this->cbColor->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cbColor_SelectedIndexChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 118);
			this->Controls->Add(this->lbColor);
			this->Controls->Add(this->cbColor);
			this->Name = L"Form1";
			this->Text = L"System Drawing Colors";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
    private: 
        System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
        {
            Type^ colorType = Color::typeid;
            colors = colorType->GetProperties();

            for (int i = 0; i < colors->Length; i++)
            {
                if (colors[i]->ToString()->IndexOf("System.Drawing.Color") >= 0)
                    cbColor->Items->Add(colors[i]->ToString());
            }
            cbColor->SelectedIndex = 0;
        }

        System::Void cbColor_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
        {
            static bool alternateWrite = true;
            PropertyInfo ^ColorProp = colors[cbColor->SelectedIndex];

            MethodInfo ^PropMethod = ColorProp->GetGetMethod();

            lbColor->BackColor = (Color)PropMethod->Invoke(nullptr,nullptr);

            Assembly ^assembly = Assembly::Load("Invoking");

            Type ^type;
            if (alternateWrite)
                type = assembly->GetType("Invoking.Writer1");
            else
                type = assembly->GetType("Invoking.Writer2");

            alternateWrite = !alternateWrite;

            MethodInfo ^ColorMethod = type->GetMethod("aColor");

            Object ^writerInst = Activator::CreateInstance(type);

            array <Object^>^ args = gcnew array <Object^>(1);
            args[0] = PropMethod->Invoke(nullptr,nullptr);

            lbColor->Text = (String^)ColorMethod->Invoke(writerInst, args);
        }
    };

    ref class Writer1
    {
    public:
        String ^aColor(Color ^col)
        {
            return String::Format("[Writer 1] {0}", col->ToString());
        }
    };

    ref class Writer2
    {
    public:
        String ^aColor(Color ^col)
        {
            return String::Format("[Writer 2] {0}", col->ToString());
        }
    };
}

