#using <system.dll>

using namespace System;
using namespace System::Collections::Generic;

// Make the dictionary sort in reverse
ref class Reverse : public IComparer<int>
{
public:
    virtual int Compare(int x, int y) { return y - x; }
    virtual bool Equals(int x, int y) { return x == y; }
    virtual int GetHashCode(int obj) { return obj.GetHashCode(); }
};

Dictionary<int,String^>^ DictionaryExample()
{
    Dictionary<int,String^>^ dict = gcnew Dictionary<int,String^>();

    dict->Add(1,  "One");
    dict->Add(6,  "Six");
    dict->Add(5,  "Five");
    
    dict->Add(3,  "3");
//  dict->Add(3,  "3");  // throws an exception
    dict[3] = "Three";

    dict[7] = "Seven";
    
    String^ t = dict[3];
    Console::WriteLine("dict[3] = {0}\n", t);

    for each (KeyValuePair<int,String^>^ pair in dict)
    {
        Console::WriteLine("Key = [{0}]\tValue = [{1}]", 
            pair->Key, pair->Value);
    }

    Console::WriteLine("\nDictionary contains 6? [{0}]", 
        dict->ContainsKey(6));

    dict->Remove(6);

    Console::WriteLine("\nDictionary had 6 removed? [{0}]\n", 
        !dict->ContainsKey(6));

    Dictionary<int,String^>::KeyCollection::Enumerator ^key = 
        dict->Keys->GetEnumerator();
    Dictionary<int,String^>::ValueCollection::Enumerator ^value = 
        dict->Values->GetEnumerator();

    while ( key->MoveNext() && value->MoveNext())
    {
        Console::WriteLine("Key = [{0}]\tValue = [{1}]", 
            key->Current, value->Current);
    }

    return dict;
}

void SortedDictionaryExample(Dictionary<int,String^>^ inDict)
{
    SortedDictionary<int,String^>^ dict = 
        gcnew SortedDictionary<int,String^>(inDict, gcnew Reverse());
    
    dict->Add(6,  "Six");

    String^ t = dict[3];
    Console::WriteLine("dict[3] = {0}\n", t);

    Console::WriteLine("Sorted Values:");
    for each (String ^s in dict->Values)
        Console::WriteLine("\t{0}",s);

    Console::WriteLine();

    for each (KeyValuePair<int,String^>^ pair in dict)
    {
        Console::WriteLine("Key = [{0}]\tValue = [{1}]", 
            pair->Key, pair->Value);
    }

    Console::WriteLine("\nSortedDictionary contains 'Six'? [{0}]", 
        dict->ContainsValue("Six"));

    dict->Remove(6);

    Console::WriteLine("\nSortedDictionary had 'Six' removed? [{0}]\n", 
        !dict->ContainsValue("Six"));

    SortedDictionary<int,String^>::KeyCollection::Enumerator ^key = 
        dict->Keys->GetEnumerator();
    SortedDictionary<int,String^>::ValueCollection::Enumerator ^value = 
        dict->Values->GetEnumerator();

    while ( key->MoveNext() && value->MoveNext())
    {
        Console::WriteLine("Key = [{0}]\tValue = [{1}]", 
            key->Current, value->Current);
    }
}

void main()
{
    Console::WriteLine("Dictionary\n----------");
    Dictionary<int,String^>^ dict = DictionaryExample();

    Console::WriteLine();

    Console::WriteLine("\nReverse SortedDictionary\n----------------");
    SortedDictionaryExample(dict);

    Console::WriteLine();
}
