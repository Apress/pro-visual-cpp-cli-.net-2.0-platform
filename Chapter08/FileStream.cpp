using namespace System;
using namespace System::IO;

void main()
{
    FileStream ^fso = gcnew FileStream("file.dat", FileMode::Create, 
                                       FileAccess::Write, FileShare::None);

    array<unsigned char>^ data = gcnew array<unsigned char> { 'T', 'h', 'i', 
                               's', ' ', 'i', 's', ' ', 'a', ' ', 't', 'e', 
                               's', 't', '!', '\r', '\n', 'T', 'h', 'i', 's', 
                               ' ', 'i', 's', ' ', 'o', 'n', 'l', 'y', ' ', 
                               'a', ' ', 't', 'e', 's', 't', '.','\r', '\n' };
    
    for (int i = 0; i < data->Length-5; i += 5)
    {
        fso->Write(data, i, 5);
    }

    for (int i = data->Length-4; i < data->Length; i++)
    {
        fso->WriteByte(data[i]);
    }

    fso->Close();

    FileInfo ^fi = gcnew FileInfo("file.dat");
    FileStream ^fsi = fi->OpenRead();

    int b;
    while ((b = fsi->ReadByte()) != -1)
    {
        Console::Write((Char)b);
    }

    fsi->Position = 0;

    array<unsigned char>^ ca = gcnew array<unsigned char>(17);
    fsi->Read(ca, 0, 17);
    for (int i = 0; i < ca->Length; i++)
    {
        Console::Write((Char)ca[i]);
    }

    Console::WriteLine();

    fsi->Close();

    fi->Delete();  // If you want to get rid of it
}