using namespace System;
using namespace System::IO;
using namespace System::Text;

int main(array<System::String ^> ^args)
{
    if (args->Length == 0)
    {
        Console::WriteLine("Usage: DirInfo <Directory>");
        return -1;
    }

    StringBuilder ^tmppath = gcnew StringBuilder();

    for each (String^ s in args)
    {
        tmppath->Append(s);
        tmppath->Append(" ");
    }

    String ^path = tmppath->ToString()->Trim();

    DirectoryInfo ^dir = gcnew DirectoryInfo(path);

    if (!dir->Exists)
    {
        Console::WriteLine("Directory Not Found");
        return -1;
    }

    Console::WriteLine("Name:       {0}", dir->FullName);

    Console::WriteLine("Created:    {0} {1}", 
        dir->CreationTime.ToShortDateString(),
        dir->CreationTime.ToLongTimeString());

    Console::WriteLine("Accessed:   {0} {1}", 
        dir->LastAccessTime.ToShortDateString(),
        dir->LastAccessTime.ToLongTimeString());

    Console::WriteLine("Updated:    {0} {1}", 
        dir->LastWriteTime.ToShortDateString(),
        dir->LastWriteTime.ToLongTimeString());

    Console::WriteLine("Attributes: {0}", 
        dir->Attributes);

    Console::WriteLine("Sub-Directories:"); 

    array<DirectoryInfo^>^ subDirs = dir->GetDirectories();
    if (subDirs->Length == 0)
        Console::WriteLine("\tNone."); 
    else
    {
        for each (DirectoryInfo^ dinfo in subDirs)
        {
            Console::WriteLine("\t{0}", dinfo->Name); 
        }
    }

    Console::WriteLine("Files:"); 

    array<FileInfo^>^ files = dir->GetFiles();
    if (files->Length == 0)
        Console::WriteLine("\tNone."); 
    else
    {
        for each (FileInfo^ finfo in files)
        {
            Console::WriteLine("\t{0}", finfo->Name); 
        }
    }

    return 0;
}
