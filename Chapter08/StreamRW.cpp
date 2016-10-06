using namespace System;
using namespace System::IO;

void main()
{
    array<String^>^ data = gcnew array<String^> {
        "This is ", "a test!", "This is only a test." };
    
    StreamWriter ^sw = gcnew StreamWriter(gcnew FileStream("file.dat", 
                       FileMode::Create, FileAccess::Write, FileShare::None));

    for (int i = 0; i < data->Length-1; i++)
    {
        sw->Write(data[i]);
    }
    sw->WriteLine();

    sw->WriteLine(data[2]);

    sw->Close();

    StreamReader ^sr = File::OpenText("file.dat");

    String^ in = sr->ReadLine();
    Console::WriteLine(in);

    Console::WriteLine(sr->ReadToEnd());
    
    sw->Close();
}