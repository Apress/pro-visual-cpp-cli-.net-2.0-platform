using namespace System;

ref class Point
{
public:
    int X;
};

void main()
{
    Point ^p = gcnew Point();

    interior_ptr<Point^> ip1 = &p;   // pointer to Point

    (*ip1)->X = 1;

    Console::WriteLine("(&ip1)={0:X}\tp->X={1}\t(*ip1)->X={2}",
        (int)&ip1, p->X, (*ip1)->X);

    interior_ptr<int> ip2 = &p->X;  // pointer to Member variable X

    *ip2 += (*ip1)->X;

    Console::WriteLine("(&ip2)={0:X}\t*ip2={1}",
        (int)&ip2, *ip2);
}
