#pragma once

namespace ListViewEx
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
            FillListView();
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
        System::Windows::Forms::ImageList^  imFruitSmall;
        System::Windows::Forms::ImageList^  ilFruitLarge;
        System::Windows::Forms::RadioButton^  rbDetails;
        System::Windows::Forms::RadioButton^  rbList;
        System::Windows::Forms::RadioButton^  rbSmallIcon;
        System::Windows::Forms::RadioButton^  rbLargeIcon;
        System::Windows::Forms::Label^  label;
        System::Windows::Forms::ListView^  lView;
        System::Windows::Forms::ColumnHeader^  Fruit;
        System::Windows::Forms::ColumnHeader^  Price;
        System::Windows::Forms::ColumnHeader^  Available;
        System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            System::ComponentModel::ComponentResourceManager^ resources = 
       (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
            this->imFruitSmall = 
                (gcnew System::Windows::Forms::ImageList(this->components));
            this->ilFruitLarge = 
                (gcnew System::Windows::Forms::ImageList(this->components));
            this->rbDetails = (gcnew System::Windows::Forms::RadioButton());
            this->rbList = (gcnew System::Windows::Forms::RadioButton());
            this->rbSmallIcon = (gcnew System::Windows::Forms::RadioButton());
            this->rbLargeIcon = (gcnew System::Windows::Forms::RadioButton());
            this->label = (gcnew System::Windows::Forms::Label());
            this->lView = (gcnew System::Windows::Forms::ListView());
            this->Fruit = (gcnew System::Windows::Forms::ColumnHeader());
            this->Price = (gcnew System::Windows::Forms::ColumnHeader());
            this->Available = (gcnew System::Windows::Forms::ColumnHeader());
            this->SuspendLayout();
            // 
            // imFruitSmall
            // 
            this->imFruitSmall->ImageStream = 
                (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>
                (resources->GetObject(L"imFruitSmall.ImageStream")));
            this->imFruitSmall->Images->SetKeyName(0, L"apple.ico");
            this->imFruitSmall->Images->SetKeyName(1, L"banana.ico");
            this->imFruitSmall->Images->SetKeyName(2, L"orange.ico");
            // 
            // ilFruitLarge
            // 
            this->ilFruitLarge->ImageStream = 
                (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>
                (resources->GetObject(L"ilFruitLarge.ImageStream")));
            this->ilFruitLarge->Images->SetKeyName(0, L"apple.ico");
            this->ilFruitLarge->Images->SetKeyName(1, L"banana.ico");
            this->ilFruitLarge->Images->SetKeyName(2, L"orange.ico");
            // 
            // rbDetails
            // 
            this->rbDetails->Anchor = 
                static_cast<System::Windows::Forms::AnchorStyles>
                ((System::Windows::Forms::AnchorStyles::Bottom | 
                  System::Windows::Forms::AnchorStyles::Right));
            this->rbDetails->AutoSize = true;
            this->rbDetails->Checked = true;
            this->rbDetails->Location = System::Drawing::Point(154, 201);
            this->rbDetails->Name = L"rbDetails";
            this->rbDetails->Size = System::Drawing::Size(53, 17);
            this->rbDetails->TabIndex = 17;
            this->rbDetails->Text = L"Details";
            this->rbDetails->CheckedChanged += 
               gcnew System::EventHandler(this, &Form1::rbType_CheckedChanged);
            // 
            // rbList
            // 
            this->rbList->Anchor = 
                static_cast<System::Windows::Forms::AnchorStyles>
                ((System::Windows::Forms::AnchorStyles::Bottom | 
                  System::Windows::Forms::AnchorStyles::Right));
            this->rbList->AutoSize = true;
            this->rbList->Location = System::Drawing::Point(154, 177);
            this->rbList->Name = L"rbList";
            this->rbList->Size = System::Drawing::Size(37, 17);
            this->rbList->TabIndex = 16;
            this->rbList->Text = L"List";
            this->rbList->CheckedChanged += 
               gcnew System::EventHandler(this, &Form1::rbType_CheckedChanged);
            // 
            // rbSmallIcon
            // 
            this->rbSmallIcon->Anchor = 
                static_cast<System::Windows::Forms::AnchorStyles>
                ((System::Windows::Forms::AnchorStyles::Bottom | 
                  System::Windows::Forms::AnchorStyles::Right));
            this->rbSmallIcon->AutoSize = true;
            this->rbSmallIcon->Location = System::Drawing::Point(154, 153);
            this->rbSmallIcon->Name = L"rbSmallIcon";
            this->rbSmallIcon->Size = System::Drawing::Size(70, 17);
            this->rbSmallIcon->TabIndex = 15;
            this->rbSmallIcon->Text = L"Small Icon";
            this->rbSmallIcon->CheckedChanged += 
               gcnew System::EventHandler(this, &Form1::rbType_CheckedChanged);
            // 
            // rbLargeIcon
            // 
            this->rbLargeIcon->Anchor = 
                static_cast<System::Windows::Forms::AnchorStyles>
                ((System::Windows::Forms::AnchorStyles::Bottom | 
                  System::Windows::Forms::AnchorStyles::Right));
            this->rbLargeIcon->AutoSize = true;
            this->rbLargeIcon->Location = System::Drawing::Point(154, 129);
            this->rbLargeIcon->Name = L"rbLargeIcon";
            this->rbLargeIcon->Size = System::Drawing::Size(72, 17);
            this->rbLargeIcon->TabIndex = 14;
            this->rbLargeIcon->Text = L"Large Icon";
            this->rbLargeIcon->CheckedChanged += 
               gcnew System::EventHandler(this, &Form1::rbType_CheckedChanged);
            // 
            // label
            // 
            this->label->Anchor = 
                static_cast<System::Windows::Forms::AnchorStyles>
                ((System::Windows::Forms::AnchorStyles::Bottom | 
                  System::Windows::Forms::AnchorStyles::Left));
            this->label->BorderStyle = 
                System::Windows::Forms::BorderStyle::FixedSingle;
            this->label->Location = System::Drawing::Point(19, 162);
            this->label->Name = L"label";
            this->label->Size = System::Drawing::Size(64, 21);
            this->label->TabIndex = 13;
            this->label->TextAlign = 
                System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // lView
            // 
            this->lView->Anchor = 
                static_cast<System::Windows::Forms::AnchorStyles>
                ((((System::Windows::Forms::AnchorStyles::Top | 
                    System::Windows::Forms::AnchorStyles::Bottom) | 
                    System::Windows::Forms::AnchorStyles::Left) | 
                    System::Windows::Forms::AnchorStyles::Right));
            this->lView->Columns->AddRange(
                gcnew cli::array< System::Windows::Forms::ColumnHeader^>(3) 
                {
                    this->Fruit, this->Price, this->Available
                });
            this->lView->FullRowSelect = true;
            this->lView->GridLines = true;
            this->lView->LabelEdit = true;
            this->lView->LargeImageList = this->ilFruitLarge;
            this->lView->Location = System::Drawing::Point(0, 0);
            this->lView->MultiSelect = false;
            this->lView->Name = L"lView";
            this->lView->Size = System::Drawing::Size(270, 109);
            this->lView->SmallImageList = this->imFruitSmall;
            this->lView->TabIndex = 12;
            this->lView->View = System::Windows::Forms::View::Details;
            this->lView->SelectedIndexChanged += 
                gcnew System::EventHandler(this, 
                                           &Form1::lView_SelectedIndexChanged);
            // 
            // Fruit
            // 
            this->Fruit->Text = L"Fruit";
            this->Fruit->Width = 115;
            // 
            // Price
            // 
            this->Price->Text = L"Price";
            this->Price->Width = 50;
            // 
            // Available
            // 
            this->Available->Text = L"Available";
            this->Available->Width = 100;
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(269, 229);
            this->Controls->Add(this->rbDetails);
            this->Controls->Add(this->rbList);
            this->Controls->Add(this->rbSmallIcon);
            this->Controls->Add(this->rbLargeIcon);
            this->Controls->Add(this->label);
            this->Controls->Add(this->lView);
            this->Name = L"Form1";
            this->Text = L"List View Example";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private:
        void FillListView()
        {
            array<String^>^ itemRec1 = gcnew array<String^> { 
                "Apple", "1.50", "September" 
            };
            lView->Items->Add(gcnew ListViewItem(itemRec1, 0));

            array<String^>^ itemRec2 = gcnew array<String^> { 
                "Banana", "3.95", "November" 
            };
            lView->Items->Add(gcnew ListViewItem(itemRec2, 1));

            array<String^>^ itemRec3 = gcnew array<String^> { 
                "Orange", "2.50", "March" 
            };
            lView->Items->Add(gcnew ListViewItem(itemRec3, 2));
        }

        System::Void lView_SelectedIndexChanged(System::Object^ sender,
                                                System::EventArgs^ e) 
        {
             if (lView->FocusedItem != nullptr)
                label->Text = lView->FocusedItem->SubItems[1]->Text; 
        }

        System::Void rbType_CheckedChanged(System::Object^ sender, 
                                           System::EventArgs^ e)
        {
            if (rbLargeIcon->Checked)
                lView->View = View::LargeIcon;
            else if (rbSmallIcon->Checked)
                lView->View = View::SmallIcon;
            else if (rbList->Checked)
                lView->View = View::List;
            else if (rbDetails->Checked)
                lView->View = View::Details;
        }
    };
}


