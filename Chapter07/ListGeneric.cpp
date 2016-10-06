using namespace System;
using namespace System::Collections::Generic;

// -------- StringEx class ---------------------------------------

ref class StringEx
{
public:
    String^ Value;

    StringEx(String^ in);
    virtual String^ ToString() override;

    static bool With_e_Predicate(StringEx^ val);
    static void SurroundInStars(StringEx^ val);
};

StringEx::StringEx(String^ in) : Value(in) {}

String^ StringEx::ToString() { return Value; }

bool StringEx::With_e_Predicate(StringEx^ val)
{
    return val->Value->ToUpper()->IndexOf("E") > 0;
}

void StringEx::SurroundInStars(StringEx^ val)
{
    val->Value = String::Format("** {0} **", val->Value);
}

// ---------- Main function ---------------------------------------

void main()
{
    List<StringEx^>^ alist = gcnew List<StringEx^>();

    alist->Add(gcnew StringEx("One"));
    alist->Add(gcnew StringEx("-"));
    alist[1] = gcnew StringEx("Three");

    alist->Insert(1, gcnew StringEx("Two"));

    List<StringEx^>^ morenums = gcnew List<StringEx^>();
    morenums->Add(gcnew StringEx("Four"));
    morenums->Add(gcnew StringEx("Five"));
 
    alist->AddRange(morenums);

//  alist[0] = "Six";    // Compile time error not a StringEx
//  alist->Add("Six");   // Compile time error not a StringEx

    Console::WriteLine("*** The List<StringEx^> ***");
    for (int i = 0; i < alist->Count; i++)
        Console::WriteLine("{0} ", alist[i]);

    // Find all words in list that contain an 'e'
    List<StringEx^>^ With_e = 
        alist->FindAll(gcnew Predicate<StringEx^>(StringEx::With_e_Predicate));

    Console::WriteLine("\n\n*** The List<StringEx^> containing an 'e' ***");

    for each(StringEx^ str in With_e)
        Console::WriteLine("{0} ", str);

    // Surround all elements with stars
    alist->ForEach(gcnew Action<StringEx^>(StringEx::SurroundInStars));

    Console::WriteLine("\n\n*** The List<StringEx^> surrounded by stars ***");

    for each(StringEx^ str in alist)
        Console::WriteLine("{0} ", str);

    Console::WriteLine("\n");
}