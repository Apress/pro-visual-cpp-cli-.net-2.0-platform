using namespace System;

// Function Template  --------------------------------------

template <class T>
T min ( T a, T b)
{
    return (a < b) ? a : b;
}

// Class Template  -----------------------------------------

template <class T>
ref class Point2D
{
public:
    Point2D();
    Point2D(T x, T y);

    T X;
    T Y;

    static Point2D^ operator-(const Point2D^ lhs, const Point2D^ rhs);
    static Point2D^ operator*(const Point2D^ lhs, const T rhs);

    virtual String^ ToString() override;
};

template <class T>
Point2D<T>::Point2D() : X((T)0), Y((T)0) {}

template <class T>
Point2D<T>::Point2D(T x, T y) : X(x), Y(y) {}

template <class T>
Point2D<T>^ Point2D<T>::operator-(const Point2D^ lhs, const Point2D^ rhs)
{
    Point2D^ ret = gcnew Point2D();

    ret->X = lhs->X - rhs->X;
    ret->Y = lhs->Y - rhs->Y;

    return ret;
}

template <class T>
Point2D<T>^ Point2D<T>::operator*(const Point2D^ lhs, const T rhs)
{
    Point2D^ ret = gcnew Point2D();

    ret->X = lhs->X * rhs;
    ret->Y = lhs->Y * rhs;

    return ret;
}

template <class T>
String^ Point2D<T>::ToString()
{
    return String::Format("X={0} Y={1}", X, Y);
}

// Class Template Specialization  ----------------------------

template <>
ref class Point2D<char>
{
public:
    Point2D() { throw gcnew Exception("Data Type is too small"); }
    Point2D(char x, char y) { throw gcnew Exception("Data Type is too small"); }
};

// main function  --------------------------------------------

void main()
{
    int    a = 5;
    int    b = 6;
    double c = 5.1;

    Console::WriteLine("The min of {0} and {1} is {2}", a, b, min(a,b));
    Console::WriteLine("The min of {0} and {1} is {2}", a, c, min<double>(a,c));

    Console::WriteLine("----------------------------");

    Point2D<int>^ TopLeftI = gcnew Point2D<int>(10, 10);
    Point2D<int>^ BottomRightI = gcnew Point2D<int>(15, 20);

    Point2D<int>^ SizeI = BottomRightI - TopLeftI;
    Console::WriteLine(SizeI);

    SizeI = SizeI * 2;
    Console::WriteLine(SizeI);

    Console::WriteLine("----------------------------");

    Point2D<double>^ TopLeft = gcnew Point2D<double>(10.5, 10.9);
    Point2D<double>^ BottomRight = gcnew Point2D<double>(15.2, 20.3);

    Point2D<double>^ SizeD = BottomRight - TopLeft;
    Console::WriteLine(SizeD);

    SizeD = SizeD * 0.5;
    Console::WriteLine(SizeD);

    Console::WriteLine("----------------------------");

    try
    {
        Point2D<char>^ TopLeft = gcnew Point2D<char>(10, 10);
    }
    catch (Exception^ ex)
    {
        Console::WriteLine(ex->Message);
    }
}