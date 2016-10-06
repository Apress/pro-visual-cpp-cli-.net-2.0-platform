#pragma once

namespace TreeViewEx
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
        System::Windows::Forms::TreeView^  tView;
        System::Windows::Forms::ImageList^  imFolders;
        System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            System::Windows::Forms::TreeNode^ treeNode1 = 
                (gcnew System::Windows::Forms::TreeNode(L"<holder>"));
            System::Windows::Forms::TreeNode^ treeNode2 = 
                (gcnew System::Windows::Forms::TreeNode(
                    L"Root Node A", 0, 1, 
                    gcnew cli::array< System::Windows::Forms::TreeNode^ >(1) 
                    {treeNode1}));
            System::Windows::Forms::TreeNode^ treeNode3 = 
                (gcnew System::Windows::Forms::TreeNode(L"<holder>"));
            System::Windows::Forms::TreeNode^ treeNode4 = 
                (gcnew System::Windows::Forms::TreeNode(
                    L"Root Node B", 0, 1, 
                    gcnew cli::array< System::Windows::Forms::TreeNode^ >(1) 
                    {treeNode3}));
            System::ComponentModel::ComponentResourceManager^ resources = 
       (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
            this->tView = (gcnew System::Windows::Forms::TreeView());
            this->imFolders = 
                (gcnew System::Windows::Forms::ImageList(this->components));
            this->SuspendLayout();
            // 
            // tView
            // 
            this->tView->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tView->ImageIndex = 0;
            this->tView->ImageList = this->imFolders;
            this->tView->LabelEdit = true;
            this->tView->Location = System::Drawing::Point(0, 0);
            this->tView->Name = L"tView";
            treeNode1->Name = L"Node1";
            treeNode1->Text = L"<holder>";
            treeNode2->ImageIndex = 0;
            treeNode2->Name = L"Node0";
            treeNode2->SelectedImageIndex = 1;
            treeNode2->Text = L"Root Node A";
            treeNode3->Name = L"Node3";
            treeNode3->Text = L"<holder>";
            treeNode4->ImageIndex = 0;
            treeNode4->Name = L"Node2";
            treeNode4->SelectedImageIndex = 1;
            treeNode4->Text = L"Root Node B";
            this->tView->Nodes->AddRange(
                gcnew cli::array< System::Windows::Forms::TreeNode^ >(2) 
                    {treeNode2, treeNode4});
            this->tView->SelectedImageIndex = 1;
            this->tView->Size = System::Drawing::Size(194, 481);
            this->tView->TabIndex = 0;
            this->tView->BeforeExpand += 
                gcnew System::Windows::Forms::TreeViewCancelEventHandler(this,
                                                  &Form1::tView_BeforeExpand);
            // 
            // imFolders
            // 
            this->imFolders->ImageStream = 
                (cli::safe_cast<System::Windows::Forms::ImageListStreamer^ >
                (resources->GetObject(L"imFolders.ImageStream")));
            this->imFolders->Images->SetKeyName(0, L"CLSDFOLD.ICO");
            this->imFolders->Images->SetKeyName(1, L"OPENFOLD.ICO");
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(194, 481);
            this->Controls->Add(this->tView);
            this->Name = L"Form1";
            this->Text = L"Tree View Example";
            this->ResumeLayout(false);

        }
#pragma endregion
    private: 
        System::Void tView_BeforeExpand(System::Object^ sender, 
                            System::Windows::Forms::TreeViewCancelEventArgs^ e)
        {
            // Already expanded before?
            if (e->Node->Nodes->Count > 1)
                return;  // Already expanded
            else if (e->Node->Nodes->Count == 1)
            {
                if (e->Node->Nodes[0]->Text->Equals("<holder>"))
                    e->Node->Nodes->RemoveAt(0); // Node ready for expanding
                else
                    return; // Already expanded but only one sub node
            }
            // Randomly expand the Node
            Random ^rand = gcnew Random();
            int rnd = rand->Next(1,5);
            for (int i = 0; i < rnd; i++) // Randon number of sub nodes 
            {
                TreeNode ^stn = 
                    gcnew TreeNode(String::Format("Sub Node {0}", i+1), 0, 1);
                e->Node->Nodes->Add(stn);

                if (rand->Next(2) == 1)  // Has sub sub-nodes
                    stn->Nodes->Add(gcnew TreeNode("<holder>", 0, 1));
            }
        }
    };
}