using namespace System;

// Character Literals in Action
void main()
{
    char a = 'a';        // character 'a'
    Char b = L'b';       // Unicode 'b'

    char t = '\t';       // tab escape
    Char s = L'\\';      // Unicode backslash escape

    char d = '\45';      // octal escape
    Char e = L'\x0045';  // Unicode hexadecimal escape

    Console::WriteLine ( a ); // displays numeric equiv of 'A'
    Console::WriteLine ( b ); // displays the letter 'b'
    Console::WriteLine ( t ); // displays numeric equiv of tab
    Console::WriteLine ( s ); // displays backslash
    Console::WriteLine ( d ); // displays decimal equiv of octal 45
    Console::WriteLine ( e ); // displays the letter 'e'
}
