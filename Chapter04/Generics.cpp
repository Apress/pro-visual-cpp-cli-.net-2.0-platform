using namespace System;

// Generic Class ----------------------------------------

generic<class K, class V>
    where K : IComparable
ref class KVClass
{
public:
    property K Key;
    property V Value;
    KVClass(K key, V value);

    V isGreater(KVClass ^in);
};

generic<class K, class V>
KVClass<K,V>::KVClass(K key, V value)
{
    Key = key;
    Value = value;
}


generic<class K, class V>
    where K : IComparable
V KVClass<K,V>::isGreater(KVClass ^in)
{
    if (Key->CompareTo(in->Key) > 0)
        return Value;
    else
        return in->Value;
}


// main function  ----------------------------------------

void main()
{
    KVClass<int,String^> ^a = gcnew KVClass<int,String^>(5, "Five");
    KVClass<int,String^> ^b = gcnew KVClass<int,String^>(6, "Six");

    Console::WriteLine(a->isGreater(b));

    KVClass<String^,int> ^t = gcnew KVClass<String^,int>("Tomato", 1);
    KVClass<String^,int> ^c = gcnew KVClass<String^,int>("Carrot", 2);

    Console::WriteLine(t->isGreater(c));
}