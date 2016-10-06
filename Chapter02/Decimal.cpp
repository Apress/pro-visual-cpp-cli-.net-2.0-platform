using namespace System;

// Decimal Fundamental Type in Action
void main()
{
    Decimal w = System::Convert::ToDecimal("123456789012345678901.2345678");
    Console::WriteLine( w );

    Decimal x = (Decimal)0.1234567890123456789012345678; // will get truncated 
    Decimal y = (Decimal)0.0000000000000000789012345678; // works fine

    Console::WriteLine( x );
    Console::WriteLine( y );

    // Decimal constructor
    Decimal z(0xeb1f0ad2, 0xab54a98c, 0, false, 0); // = 12345678901234567890
    Console::WriteLine( z );

    // Create a 28 significate digit number
    Decimal a = (Decimal)123456789012345000000.00000000;
    Decimal b = (Decimal)678901.23456780;
    Decimal c = -(a + b);

    Console::WriteLine( c );                  // display pre broken Decimal
 
    // Break it up into 4 parts
    array<int>^ d = Decimal::GetBits(c);

    // Reassemble using Decimal constructor
    Decimal e(d[0], d[1], d[2],                    // digits
              ((d[3] & 0x80000000) == 0x80000000), // sign
              ((d[3] >> 16) & 0xff) );             // decimal location

    Console::WriteLine( d[0] );               // display part 1
    Console::WriteLine( d[1] );               // display part 2
    Console::WriteLine( d[2] );               // display part 3
    Console::WriteLine( d[3].ToString("X") ); // display part 4
    Console::WriteLine( e );                  // display reassembled Decimal
}
