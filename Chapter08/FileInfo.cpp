using namespace System;
using namespace System::IO;
using namespace System::Text;

int main(array<System::String ^> ^args)
{
    if (args->Length == 0)
    {
        Console::WriteLine("Usage: FileInfo <File>");
        return -1;
    }

    StringBuilder ^tmpfile = gcnew StringBuilder();

    for each (String^ s in args)
    {
        tmpfile->Append(s);
        tmpfile->Append(" ");
    }

    String ^strfile = tmpfile->ToString()->Trim();

    FileInfo ^fileinfo = gcnew FileInfo(strfile);

    if (!fileinfo->Exists)
    {
        Console::WriteLine("File Not Found");
        return -1;
    }

    Console::WriteLine("Name:       {0}", fileinfo->FullName);

    Console::WriteLine("Created:    {0} {1}", 
        fileinfo->CreationTime.ToShortDateString(),
        fileinfo->CreationTime.ToLongTimeString());

    Console::WriteLine("Accessed:   {0} {1}", 
        fileinfo->LastAccessTime.ToShortDateString(),
        fileinfo->LastAccessTime.ToLongTimeString());

    Console::WriteLine("Updated:    {0} {1}", 
        fileinfo->LastWriteTime.ToShortDateString(),
        fileinfo->LastWriteTime.ToLongTimeString());

    Console::WriteLine("Length:     {0}", fileinfo->Length);

    Console::WriteLine("Attributes: {0}", fileinfo->Attributes);

    return 0;
}