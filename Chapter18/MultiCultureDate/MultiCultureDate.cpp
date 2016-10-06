using namespace System;
using namespace System::Globalization;

void main()
{
    DateTime dt = DateTime::Now;

    Console::WriteLine("en-us {0}", dt.ToString("D", gcnew CultureInfo("en-us")));
    Console::WriteLine("en-gb {0}", dt.ToString("D", gcnew CultureInfo("en-gb")));
    Console::WriteLine("fr-fr {0}", dt.ToString("D", gcnew CultureInfo("fr-fr")));
    Console::WriteLine("de-de {0}", dt.ToString("D", gcnew CultureInfo("de-de")));
}