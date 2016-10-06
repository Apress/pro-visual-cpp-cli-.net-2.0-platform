#pragma once


namespace MaintAuthorsDGV 
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
        System::Windows::Forms::DataGridView^  dataGridView1;
        System::Windows::Forms::BindingSource^  authorsDSBindingSource;
        MaintAuthorsDGV::AuthorsDS^  AuthorsDS;
        MaintAuthorsDGV::AuthorsDSTableAdapters::AuthorsTableAdapter^  AuthorsTableAdapter;
        System::Windows::Forms::Button^  bnCommit;
        System::Windows::Forms::Button^  bnRollback;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^  authorIDDataGridViewTextBoxColumn;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^  lastNameDataGridViewTextBoxColumn;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^  firstNameDataGridViewTextBoxColumn;






        System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
		{
            this->components = (gcnew System::ComponentModel::Container());
            System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->authorIDDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->lastNameDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->firstNameDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->authorsDSBindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
            this->AuthorsDS = (gcnew MaintAuthorsDGV::AuthorsDS());
            this->AuthorsTableAdapter = (gcnew MaintAuthorsDGV::AuthorsDSTableAdapters::AuthorsTableAdapter());
            this->bnCommit = (gcnew System::Windows::Forms::Button());
            this->bnRollback = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->authorsDSBindingSource))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->AuthorsDS))->BeginInit();
            this->SuspendLayout();
            // 
            // dataGridView1
            // 
            this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
                | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->dataGridView1->AutoGenerateColumns = false;
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->authorIDDataGridViewTextBoxColumn, 
                this->lastNameDataGridViewTextBoxColumn, this->firstNameDataGridViewTextBoxColumn});
            this->dataGridView1->DataSource = this->authorsDSBindingSource;
            this->dataGridView1->ImeMode = System::Windows::Forms::ImeMode::Disable;
            this->dataGridView1->Location = System::Drawing::Point(12, 13);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->Size = System::Drawing::Size(403, 219);
            this->dataGridView1->TabIndex = 0;
            // 
            // authorIDDataGridViewTextBoxColumn
            // 
            this->authorIDDataGridViewTextBoxColumn->DataPropertyName = L"AuthorID";
            dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
            this->authorIDDataGridViewTextBoxColumn->DefaultCellStyle = dataGridViewCellStyle1;
            this->authorIDDataGridViewTextBoxColumn->HeaderText = L"AuthorID";
            this->authorIDDataGridViewTextBoxColumn->Name = L"authorIDDataGridViewTextBoxColumn";
            this->authorIDDataGridViewTextBoxColumn->ReadOnly = true;
            this->authorIDDataGridViewTextBoxColumn->Width = 60;
            // 
            // lastNameDataGridViewTextBoxColumn
            // 
            this->lastNameDataGridViewTextBoxColumn->DataPropertyName = L"LastName";
            this->lastNameDataGridViewTextBoxColumn->HeaderText = L"LastName";
            this->lastNameDataGridViewTextBoxColumn->Name = L"lastNameDataGridViewTextBoxColumn";
            this->lastNameDataGridViewTextBoxColumn->Width = 150;
            // 
            // firstNameDataGridViewTextBoxColumn
            // 
            this->firstNameDataGridViewTextBoxColumn->DataPropertyName = L"FirstName";
            this->firstNameDataGridViewTextBoxColumn->HeaderText = L"FirstName";
            this->firstNameDataGridViewTextBoxColumn->Name = L"firstNameDataGridViewTextBoxColumn";
            this->firstNameDataGridViewTextBoxColumn->Width = 150;
            // 
            // authorsDSBindingSource
            // 
            this->authorsDSBindingSource->DataMember = L"Authors";
            this->authorsDSBindingSource->DataSource = this->AuthorsDS;
            // 
            // AuthorsDS
            // 
            this->AuthorsDS->DataSetName = L"AuthorsDS";
            // 
            // AuthorsTableAdapter
            // 
            this->AuthorsTableAdapter->ClearBeforeFill = true;
            // 
            // bnCommit
            // 
            this->bnCommit->Location = System::Drawing::Point(120, 238);
            this->bnCommit->Name = L"bnCommit";
            this->bnCommit->Size = System::Drawing::Size(75, 23);
            this->bnCommit->TabIndex = 1;
            this->bnCommit->Text = L"Commit";
            this->bnCommit->UseVisualStyleBackColor = true;
            this->bnCommit->Click += gcnew System::EventHandler(this, &Form1::bnCommit_Click);
            // 
            // bnRollback
            // 
            this->bnRollback->Location = System::Drawing::Point(225, 238);
            this->bnRollback->Name = L"bnRollback";
            this->bnRollback->Size = System::Drawing::Size(75, 23);
            this->bnRollback->TabIndex = 2;
            this->bnRollback->Text = L"Rollback";
            this->bnRollback->UseVisualStyleBackColor = true;
            this->bnRollback->Click += gcnew System::EventHandler(this, &Form1::bnRollback_Click);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(423, 273);
            this->Controls->Add(this->bnRollback);
            this->Controls->Add(this->bnCommit);
            this->Controls->Add(this->dataGridView1);
            this->Name = L"Form1";
            this->Text = L"Maintain Authors using a DataGridView";
            this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->authorsDSBindingSource))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->AuthorsDS))->EndInit();
            this->ResumeLayout(false);

        }

#pragma endregion

    private: 
        System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e)
        {
            this->AuthorsTableAdapter->Fill(this->AuthorsDS->Authors);
        }

        System::Void bnCommit_Click(System::Object^ sender, System::EventArgs^ e) 
        {
			this->AuthorsTableAdapter->Update(this->AuthorsDS->Authors);
			this->AuthorsDS->AcceptChanges();
        }

        System::Void bnRollback_Click(System::Object^ sender, System::EventArgs^ e) 
        {
			this->AuthorsDS->RejectChanges();
        }
    };
}

