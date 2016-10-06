using namespace System;

// String Type in Action
void main()
{
	// Create some strings
    String^ s1 = "This will ";
    String^ s2 = "be a ";
    String^ s3 = "String";
    Console::WriteLine(String::Concat(s1, s2, s3));

	// Create a copy, then concatenate new text
    String^ s4 = s2;  
    s4 = String::Concat(s4, "new ");
    Console::WriteLine(String::Concat(s1, s4, s3));

    // Replace stuff in a concatenated string
	String^ s5 = String::Concat(s1, s2, s3)->Replace("i", "*");
	Console::WriteLine(s5); 

	// Insert into a string
    String^ s6 = s3->Insert(3, "ange Str");
    Console::WriteLine(String::Concat(s1, s2, s6));

	// Remove text from strings
    s1 = s1->Remove(4, 5);  // remove ' will' from middle
    s2 = s2->Remove(0, 3);  // remove 'be ' from start
    Console::WriteLine(String::Concat(s1, "is ", s2, s3));
}
