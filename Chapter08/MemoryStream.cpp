using namespace System;
using namespace System::IO;

void main()
{
    array<unsigned char>^ data = gcnew array<unsigned char> { 'T', 'h', 'i',
                    's', ' ', 'i', 's', ' ', 'a', ' ', 't', 'e', 's', 't',
                    '!', '\r', '\n', 'T', 'h', 'i', 's', ' ', 'i', 's', ' ',
                    'o', 'n', 'l', 'y', ' ', 'a', ' ', 't', 'e', 's', 't',
                    '.','\r', '\n' };
    
    MemoryStream ^ms = gcnew MemoryStream();
    ms->Capacity = 40;

    for (int i = 0; i < data->Length-5; i += 5)
    {
        ms->Write(data, i, 5);
    }

    for (int i = data->Length-4; i < data->Length; i++)
    {
        ms->WriteByte(data[i]);
    }

    array<unsigned char>^ ca = ms->GetBuffer();
    for each (unsigned char c in ca)
    {
        Console::Write((Char)c);
    }
    Console::WriteLine();

    FileStream ^fs = File::OpenWrite("file.dat");
    
    ms->WriteTo(fs);

    fs->Close();
    ms->Close();
}