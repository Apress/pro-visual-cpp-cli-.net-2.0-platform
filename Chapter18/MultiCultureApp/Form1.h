#pragma once


namespace MultiCultureApp 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Globalization;
	using namespace System::Threading;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			Thread::CurrentThread->CurrentCulture = gcnew CultureInfo("fr-fr");
			Thread::CurrentThread->CurrentUICulture = Thread::CurrentThread->CurrentCulture;
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
		System::Windows::Forms::Label^  lbHello;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

void InitializeComponent(void)
{
	System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
	this->lbHello = (gcnew System::Windows::Forms::Label());
	this->SuspendLayout();
	// 
	// lbHello
	// 
	this->lbHello->AccessibleDescription = nullptr;
	this->lbHello->AccessibleName = nullptr;
	resources->ApplyResources(this->lbHello, L"lbHello");
	this->lbHello->Name = L"lbHello";
	// 
	// Form1
	// 
	this->AccessibleDescription = nullptr;
	this->AccessibleName = nullptr;
	resources->ApplyResources(this, L"$this");
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->BackgroundImage = nullptr;
	this->Controls->Add(this->lbHello);
	this->Font = nullptr;
	this->Icon = nullptr;
	this->Name = L"Form1";
	this->ResumeLayout(false);

}
#pragma endregion
	};
}

