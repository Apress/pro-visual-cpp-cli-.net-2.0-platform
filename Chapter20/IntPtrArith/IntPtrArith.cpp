
using namespace System;

void main()
{
    array<int>^ primes = gcnew array<int> {1,2,3,5,7,11,13,17};

    interior_ptr<int> ip = &primes[0];

    int total = 0;
    while(ip != &primes[0] + primes->Length)
    {
        total += *ip;
        ip++;
    }

    Console::WriteLine("Sum of the first 8 prime numbers is {0}", total);
}
