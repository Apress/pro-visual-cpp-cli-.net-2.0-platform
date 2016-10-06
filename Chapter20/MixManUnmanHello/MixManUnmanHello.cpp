#include "stdio.h"
#include "vcclr.h"

using namespace System;

void main()
{
    String ^hstr = "Hello World!";

    pin_ptr<const wchar_t> pstr = PtrToStringChars(hstr);

    wprintf(pstr);
}
