#pragma once


namespace MaintAuthors 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Data::SqlClient;
	using namespace System::Drawing;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();

			SqlConnection ^connect = gcnew SqlConnection();

#ifdef SQLAuth
			//  SQL Server authentication
			connect->ConnectionString = 
				"User ID=sa; Password=;"
				"Data Source=(local); Initial Catalog=DCV_DB;";
#else
			//  Windows Integrated Security
			connect->ConnectionString = 
				"Persist Security Info=False; Integrated Security=SSPI;"
				"Data Source=(local); Initial Catalog=DCV_DB;";
#endif

            dAdapt = gcnew SqlDataAdapter();
            dAdapt->MissingSchemaAction = MissingSchemaAction::AddWithKey;
           
            dAdapt->SelectCommand = gcnew SqlCommand("SELECT AuthorID, LastName, FirstName FROM Authors", connect);
            
            dAdapt->InsertCommand = gcnew SqlCommand("INSERT INTO Authors (LastName, FirstName) " 
                                                   "VALUES (@LastName, @FirstName)", connect);
            dAdapt->InsertCommand->Parameters->Add("@LastName", SqlDbType::VarChar, 50, "LastName");
            dAdapt->InsertCommand->Parameters->Add("@FirstName", SqlDbType::VarChar, 50, "FirstName");
         
            
            dAdapt->UpdateCommand = gcnew SqlCommand("UPDATE Authors SET LastName = @LastName, FirstName = @FirstName " 
                                                   "WHERE AuthorID = @AuthorID", connect);
            dAdapt->UpdateCommand->Parameters->Add("@LastName", SqlDbType::VarChar, 50, "LastName");
            dAdapt->UpdateCommand->Parameters->Add("@FirstName", SqlDbType::VarChar, 50, "FirstName");
            dAdapt->UpdateCommand->Parameters->Add("@AuthorID", SqlDbType::Int, 4, "AuthorID");
            
            dAdapt->DeleteCommand = gcnew SqlCommand("DELETE FROM Authors WHERE AuthorID = @AuthorID", connect);
            dAdapt->DeleteCommand->Parameters->Add("@AuthorID", SqlDbType::Int, 4, "AuthorID");
        
            dSet = gcnew DataSet();
            dAdapt->Fill(dSet, "Authors");

            DataTable ^dt = dSet->Tables["Authors"];

            if (dt == nullptr)
                throw gcnew Exception("No Authors Table");

            IEnumerator ^Enum = dt->Rows->GetEnumerator();
            while(Enum->MoveNext())
            {
                DataRow ^row = (DataRow^)(Enum->Current);
                lbAuthors->Items->Add(ListBoxItem(row));
            }
            CurrentAuthorID = -1;
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
        System::Windows::Forms::Button^  bnRollback;
        System::Windows::Forms::Button^  bnCommit;
        System::Windows::Forms::Button^  bnDelete;
        System::Windows::Forms::Button^  bnUpdate;
        System::Windows::Forms::Button^  bnAdd;
        System::Windows::Forms::ListBox^  lbAuthors;
        System::Windows::Forms::TextBox^  tbLastName;
        System::Windows::Forms::TextBox^  tbFirstName;
        System::Windows::Forms::Label^  label2;
        System::Windows::Forms::Label^  label1;

        System::ComponentModel::Container ^components;

        SqlDataAdapter ^dAdapt;
        DataSet ^dSet;
        int CurrentAuthorID;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
		{
            this->bnRollback = (gcnew System::Windows::Forms::Button());
            this->bnCommit = (gcnew System::Windows::Forms::Button());
            this->bnDelete = (gcnew System::Windows::Forms::Button());
            this->bnUpdate = (gcnew System::Windows::Forms::Button());
            this->bnAdd = (gcnew System::Windows::Forms::Button());
            this->lbAuthors = (gcnew System::Windows::Forms::ListBox());
            this->tbLastName = (gcnew System::Windows::Forms::TextBox());
            this->tbFirstName = (gcnew System::Windows::Forms::TextBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // bnRollback
            // 
            this->bnRollback->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->bnRollback->Location = System::Drawing::Point(312, 162);
            this->bnRollback->Name = L"bnRollback";
            this->bnRollback->Size = System::Drawing::Size(75, 23);
            this->bnRollback->TabIndex = 19;
            this->bnRollback->Text = L"Rollback";
            this->bnRollback->Click += gcnew System::EventHandler(this, &Form1::bnRollback_Click);
            // 
            // bnCommit
            // 
            this->bnCommit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->bnCommit->Location = System::Drawing::Point(312, 132);
            this->bnCommit->Margin = System::Windows::Forms::Padding(3, 0, 3, 3);
            this->bnCommit->Name = L"bnCommit";
            this->bnCommit->Size = System::Drawing::Size(75, 23);
            this->bnCommit->TabIndex = 18;
            this->bnCommit->Text = L"Commit";
            this->bnCommit->Click += gcnew System::EventHandler(this, &Form1::bnCommit_Click);
            // 
            // bnDelete
            // 
            this->bnDelete->Location = System::Drawing::Point(312, 78);
            this->bnDelete->Name = L"bnDelete";
            this->bnDelete->Size = System::Drawing::Size(75, 23);
            this->bnDelete->TabIndex = 17;
            this->bnDelete->Text = L"Delete";
            this->bnDelete->Click += gcnew System::EventHandler(this, &Form1::bnDelete_Click);
            // 
            // bnUpdate
            // 
            this->bnUpdate->Location = System::Drawing::Point(312, 46);
            this->bnUpdate->Name = L"bnUpdate";
            this->bnUpdate->Size = System::Drawing::Size(75, 23);
            this->bnUpdate->TabIndex = 16;
            this->bnUpdate->Text = L"Update";
            this->bnUpdate->Click += gcnew System::EventHandler(this, &Form1::bnUpdate_Click);
            // 
            // bnAdd
            // 
            this->bnAdd->Location = System::Drawing::Point(312, 18);
            this->bnAdd->Margin = System::Windows::Forms::Padding(3, 3, 3, 1);
            this->bnAdd->Name = L"bnAdd";
            this->bnAdd->Size = System::Drawing::Size(75, 23);
            this->bnAdd->TabIndex = 15;
            this->bnAdd->Text = L"Add";
            this->bnAdd->Click += gcnew System::EventHandler(this, &Form1::bnAdd_Click);
            // 
            // lbAuthors
            // 
            this->lbAuthors->FormattingEnabled = true;
            this->lbAuthors->Location = System::Drawing::Point(25, 95);
            this->lbAuthors->Name = L"lbAuthors";
            this->lbAuthors->Size = System::Drawing::Size(257, 95);
            this->lbAuthors->TabIndex = 14;
            this->lbAuthors->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::lbAuthors_SelectedIndexChanged);
            // 
            // tbLastName
            // 
            this->tbLastName->Location = System::Drawing::Point(87, 51);
            this->tbLastName->Margin = System::Windows::Forms::Padding(1, 3, 3, 3);
            this->tbLastName->Name = L"tbLastName";
            this->tbLastName->Size = System::Drawing::Size(127, 20);
            this->tbLastName->TabIndex = 13;
            // 
            // tbFirstName
            // 
            this->tbFirstName->Location = System::Drawing::Point(87, 24);
            this->tbFirstName->Margin = System::Windows::Forms::Padding(1, 3, 3, 3);
            this->tbFirstName->Name = L"tbFirstName";
            this->tbFirstName->Size = System::Drawing::Size(127, 20);
            this->tbFirstName->TabIndex = 12;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(25, 57);
            this->label2->Margin = System::Windows::Forms::Padding(3, 3, 2, 3);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(58, 13);
            this->label2->TabIndex = 11;
            this->label2->Text = L"Last Name";
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(25, 27);
            this->label1->Margin = System::Windows::Forms::Padding(3, 3, 2, 3);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(57, 13);
            this->label1->TabIndex = 10;
            this->label1->Text = L"First Name";
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(413, 208);
            this->Controls->Add(this->bnRollback);
            this->Controls->Add(this->bnCommit);
            this->Controls->Add(this->bnDelete);
            this->Controls->Add(this->bnUpdate);
            this->Controls->Add(this->bnAdd);
            this->Controls->Add(this->lbAuthors);
            this->Controls->Add(this->tbLastName);
            this->Controls->Add(this->tbFirstName);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Name = L"Form1";
            this->Text = L"Maintain Authors";
            this->ResumeLayout(false);
            this->PerformLayout();

        }

#pragma endregion

    private: 
        String ^ListBoxItem(DataRow ^row)
        {
            return String::Format("{0} {1} {2}",
                row["AuthorID"],
                row["FirstName"],
                row["LastName"]);
        }

        System::Void bnAdd_Click(System::Object^ sender, System::EventArgs^ e)
        {
			// Make sure the text boxes are populated
			if (tbFirstName->Text->Trim()->Length == 0 ||
				tbLastName->Text->Trim()->Length == 0)
				return;

			// Create a new row in the DataTable
			DataTable ^dt = dSet->Tables["Authors"];
			DataRow ^row = dt->NewRow();

			// Update the columns with the new author information
			row["FirstName"] = tbFirstName->Text;
			row["LastName"]  = tbLastName->Text;

			// Add the row to the Rows collection
			dt->Rows->Add(row);

			// Add the new row to the list box
			lbAuthors->Items->Add(ListBoxItem(row));

			// blank out the text boxes
			tbFirstName->Text = "";
			tbLastName->Text = "";
        }

        System::Void bnUpdate_Click(System::Object^ sender, System::EventArgs^ e)
        {
			// make sure we have a selected author from the listbox
			if (CurrentAuthorID < 0)
				return;

			// Select the author using its AuthorID
			DataTable ^dt = dSet->Tables["Authors"];
			array<DataRow^>^ row = 
				dt->Select(String::Format("AuthorID={0}", CurrentAuthorID));

			// Since we know that AuthorID is unique only one row will be returned
			// Update the row with the text box information
			row[0]["FirstName"] = tbFirstName->Text;
			row[0]["LastName"]  = tbLastName->Text;

			// Update listbox
			lbAuthors->Items->Insert(lbAuthors->SelectedIndex, ListBoxItem(row[0]));
			lbAuthors->Items->RemoveAt(lbAuthors->SelectedIndex);
        }

        System::Void bnDelete_Click(System::Object^ sender, System::EventArgs^ e)
        {
 			// make sure we have a selected author from the listbox
			if (CurrentAuthorID < 0)
				return;

			// Select the author using its AuthorID
			DataTable ^dt = dSet->Tables["Authors"];
			array<DataRow^>^ row = 
				dt->Select(String::Format("AuthorID={0}", CurrentAuthorID));

			// Since we know that AuthorID is unique only one row will be returned
			// Delete the row
			row[0]->Delete();

			// all went well, delete the row from list box
			lbAuthors->Items->RemoveAt(lbAuthors->SelectedIndex);
       }

        System::Void bnCommit_Click(System::Object^ sender, System::EventArgs^ e)
        {
			dAdapt->Update(dSet, "Authors");
			dSet->AcceptChanges();

            lbAuthors->Items->Clear();

            DataTable ^dt = dSet->Tables["Authors"];

            IEnumerator ^Enum = dt->Rows->GetEnumerator();
            while(Enum->MoveNext())
            {
                DataRow ^row = (DataRow^)(Enum->Current);
                lbAuthors->Items->Add(ListBoxItem(row));
            }
            CurrentAuthorID = -1;
        }

        System::Void bnRollback_Click(System::Object^ sender, System::EventArgs^ e)
        {
            dSet->RejectChanges();

            lbAuthors->Items->Clear();

            DataTable ^dt = dSet->Tables["Authors"];

            IEnumerator ^Enum = dt->Rows->GetEnumerator();
            while(Enum->MoveNext())
            {
                DataRow ^row = (DataRow^)(Enum->Current);
                lbAuthors->Items->Add(ListBoxItem(row));
            }
            CurrentAuthorID = -1;
        }

        System::Void lbAuthors_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
        {
            array<wchar_t>^ ASpace = gcnew array<wchar_t> {(wchar_t)' '};

            if (lbAuthors->SelectedItem == nullptr)
            {
                CurrentAuthorID = -1;
                tbFirstName->Text = "";
                tbLastName->Text = "";
                return;
            }
            array<String^>^ split = lbAuthors->SelectedItem->ToString()->Split(ASpace);

            CurrentAuthorID = Convert::ToInt32(split[0]);
            tbFirstName->Text = split[1];
            tbLastName->Text = split[2];
       }
   };
}

