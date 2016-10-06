#pragma once


namespace MonthCalendarEx 
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
        System::Windows::Forms::Label^  End;
        System::Windows::Forms::Label^  Start;
        System::Windows::Forms::MonthCalendar^  monthCal;
        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->End = (gcnew System::Windows::Forms::Label());
            this->Start = (gcnew System::Windows::Forms::Label());
            this->monthCal = (gcnew System::Windows::Forms::MonthCalendar());
            this->SuspendLayout();
            // 
            // End
            // 
            this->End->BorderStyle = 
                System::Windows::Forms::BorderStyle::FixedSingle;
            this->End->Location = System::Drawing::Point(230, 323);
            this->End->Name = L"End";
            this->End->Size = System::Drawing::Size(83, 20);
            this->End->TabIndex = 5;
            // 
            // Start
            // 
            this->Start->BorderStyle = 
                System::Windows::Forms::BorderStyle::FixedSingle;
            this->Start->Location = System::Drawing::Point(122, 323);
            this->Start->Name = L"Start";
            this->Start->Size = System::Drawing::Size(83, 20);
            this->Start->TabIndex = 4;
            // 
            // monthCal
            // 
            this->monthCal->AnnuallyBoldedDates = 
                gcnew cli::array< System::DateTime >(1) 
                {System::DateTime(2004, 12, 31, 0, 0, 0, 0)};
            this->monthCal->CalendarDimensions = System::Drawing::Size(2, 2);
            this->monthCal->Location = System::Drawing::Point(13, 11);
            this->monthCal->MaxSelectionCount = 365;
            this->monthCal->MonthlyBoldedDates = 
                gcnew cli::array< System::DateTime >(2) 
                {System::DateTime(2004, 10, 1, 0, 0, 0, 0), 
                 System::DateTime(2004, 10, 15, 0, 0, 0, 0)};
            this->monthCal->Name = L"monthCal";
            this->monthCal->ShowWeekNumbers = true;
            this->monthCal->Size = System::Drawing::Size(410, 297);
            this->monthCal->TabIndex = 3;
            this->monthCal->DateChanged += 
                gcnew System::Windows::Forms::DateRangeEventHandler(this, 
                                                 &Form1::monthCal_DateChanged);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(436, 355);
            this->Controls->Add(this->End);
            this->Controls->Add(this->Start);
            this->Controls->Add(this->monthCal);
            this->Name = L"Form1";
            this->Text = L"Month Calendar";
            this->ResumeLayout(false);

        }
#pragma endregion
    private: 
        System::Void monthCal_DateChanged(System::Object^ sender, 
                                 System::Windows::Forms::DateRangeEventArgs^ e)
        {
            // Update start and end range labels when date changes
            Start->Text = e->Start.Date.ToShortDateString(); 
            End->Text   = e->End.Date.ToShortDateString(); 
        }
    };
}

