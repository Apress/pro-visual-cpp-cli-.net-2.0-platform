using namespace System;

ref class Student 
{
public:
    Student(String^ s, int g) 
    {
        Name  = s; 
        Grade = g;
    }

    property String^ Name;
    property int Grade;
};

ref class Course 
{
   ref struct StuList 
   {
      Student ^stu;
      StuList ^next;
   };
   StuList ^Stu;
   static StuList ^ReportCards = nullptr;

public:
    property Student^ ReportCard [String^]
    {
        Student^ get(String^ n)
        {
            for(Stu = ReportCards; Stu && (Stu->stu->Name != n); Stu = Stu->next)
                ;
            if (Stu != nullptr) 
                return Stu->stu; 
            else 
                return gcnew Student("",0);  // empty student
        }

        void set(String^ n, Student^ s)
        {
            for(Stu = ReportCards; Stu && (Stu->stu->Name != n); Stu = Stu->next)
                ;
            if (Stu == nullptr) 
            {
                StuList ^stuList = gcnew StuList; 
                stuList->stu = s; 
                stuList->next = ReportCards; 
                ReportCards = stuList;
            }
        }
    }
};

void main() 
{
   Course  EnglishLit;
   Student Stephen("Stephen", 95);              // student as stack variable
   Student ^Sarah = gcnew Student("Sarah", 98); // student as heap variable

   EnglishLit.ReportCard[ "Stephen" ] = %Stephen;   // index as String literal
   EnglishLit.ReportCard[ Sarah->Name ] = Sarah;    // index as String^

   Console::WriteLine(EnglishLit.ReportCard[ Stephen.Name ]->Grade);
   Console::WriteLine(EnglishLit.ReportCard[ "Sarah" ]->Grade);
}