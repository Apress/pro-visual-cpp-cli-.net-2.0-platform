using namespace System;

ref class StaticTest
{
private:
    static int x = 42;
public:
   static int get_x()
   {
      return x;
   }
};

void main()
{
    Console::WriteLine ( StaticTest::get_x() );
}