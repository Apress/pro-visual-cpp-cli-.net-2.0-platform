#pragma once


namespace Reflecting 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
    using namespace System::Reflection;

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
		System::Windows::Forms::Label^  label3;
		System::Windows::Forms::Label^  label4;
		System::Windows::Forms::Label^  label5;
		System::Windows::Forms::ListBox^  lbMethods;
		System::Windows::Forms::ListBox^  lbProperties;
		System::Windows::Forms::ListBox^  lbVariables;
		System::Windows::Forms::GroupBox^  groupBox1;
		System::Windows::Forms::ComboBox^  cbDataTypes;
		System::Windows::Forms::ComboBox^  cbAssemblies;
		System::Windows::Forms::Label^  label2;
		System::Windows::Forms::Label^  label1;

		array<Type^>^ types;
		static array<String^>^ assemblies = 
		{
			"System",
			"System.Drawing",
			"System.Xml",
			"System.Windows.Forms",
			"System.Data",
			"mscorlib"
		};

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->lbMethods = (gcnew System::Windows::Forms::ListBox());
			this->lbProperties = (gcnew System::Windows::Forms::ListBox());
			this->lbVariables = (gcnew System::Windows::Forms::ListBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->cbDataTypes = (gcnew System::Windows::Forms::ComboBox());
			this->cbAssemblies = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(15, 94);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Methods:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(320, 94);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(57, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Properties:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(585, 94);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(53, 13);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Variables:";
			// 
			// lbMethods
			// 
			this->lbMethods->FormattingEnabled = true;
			this->lbMethods->Location = System::Drawing::Point(15, 114);
			this->lbMethods->Name = L"lbMethods";
			this->lbMethods->Size = System::Drawing::Size(293, 251);
			this->lbMethods->TabIndex = 14;
			// 
			// lbProperties
			// 
			this->lbProperties->FormattingEnabled = true;
			this->lbProperties->Location = System::Drawing::Point(320, 114);
			this->lbProperties->Name = L"lbProperties";
			this->lbProperties->Size = System::Drawing::Size(250, 251);
			this->lbProperties->TabIndex = 15;
			// 
			// lbVariables
			// 
			this->lbVariables->FormattingEnabled = true;
			this->lbVariables->Location = System::Drawing::Point(585, 114);
			this->lbVariables->Name = L"lbVariables";
			this->lbVariables->Size = System::Drawing::Size(202, 251);
			this->lbVariables->TabIndex = 16;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->cbDataTypes);
			this->groupBox1->Controls->Add(this->cbAssemblies);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(14, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(443, 72);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			// 
			// cbDataTypes
			// 
			this->cbDataTypes->FormattingEnabled = true;
			this->cbDataTypes->Location = System::Drawing::Point(120, 41);
			this->cbDataTypes->Name = L"cbDataTypes";
			this->cbDataTypes->Size = System::Drawing::Size(287, 21);
			this->cbDataTypes->TabIndex = 3;
			this->cbDataTypes->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cbDataTypes_SelectedIndexChanged);
			// 
			// cbAssemblies
			// 
			this->cbAssemblies->FormattingEnabled = true;
			this->cbAssemblies->Location = System::Drawing::Point(120, 16);
			this->cbAssemblies->Name = L"cbAssemblies";
			this->cbAssemblies->Size = System::Drawing::Size(287, 21);
			this->cbAssemblies->TabIndex = 2;
			this->cbAssemblies->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cbAssemblies_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(24, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Select data type:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(24, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Select assembly:";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(801, 377);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->lbMethods);
			this->Controls->Add(this->lbProperties);
			this->Controls->Add(this->lbVariables);
			this->Controls->Add(this->groupBox1);
			this->Name = L"Form1";
			this->Text = L"Assembly Viewer";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
		}

#pragma endregion

    private: 
        System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
        {
            for each (String ^assembly  in assemblies)
            {
                cbAssemblies->Items->Add(assembly);   
            }
            cbAssemblies->SelectedIndex = 0;
        }

    private: 
        System::Void cbAssemblies_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
        {
            Assembly^ assembly = Assembly::LoadWithPartialName(
                                 assemblies[cbAssemblies->SelectedIndex]);

            types = assembly->GetTypes();

            cbDataTypes->Items->Clear();

            for (int i = 0; i < types->Length; i++)
            {
                cbDataTypes->Items->Add(types[i]->ToString());   
            }
            cbDataTypes->SelectedIndex = 0;
        }

    private: 
        System::Void cbDataTypes_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
        {
            Type ^type = types[cbDataTypes->SelectedIndex];

            array <MemberInfo^>^ methods = type->GetMethods();
            lbMethods->Items->Clear();
            for (int i = 0; i < methods->Length; i++)
            {
                lbMethods->Items->Add(methods[i]->ToString());
            }

            array <PropertyInfo^>^ properties = type->GetProperties();
            lbProperties->Items->Clear();
            for (int i = 0; i < properties->Length; i++)
            {
                lbProperties->Items->Add(properties[i]->ToString());
            }

            array <MemberInfo^>^ variables = type->GetFields();
            lbVariables->Items->Clear();
            for (int i = 0; i < variables->Length; i++)
            {
                lbVariables->Items->Add(variables[i]->ToString());
            }
        }
    };
}

