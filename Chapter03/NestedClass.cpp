using namespace System;

ref class SurroundClass
{
public:
   ref class NestedClass      // Declaration of the nested class
   {
   public:
      int publicMember;
   protected:
      int protectedMember;
   private:
      int privateMember;
   };

   NestedClass^ protectedNC;   // protected variable reference to NestedClass

private:
   NestedClass^ privateNC;     // private variable reference to NestedClass

public:
   NestedClass^ publicNC;      // public variable reference to NestedClass

   // Constructor for SurroundClass
   // Notice the initializer list declaration of the reference member variable
   SurroundClass() : publicNC(gcnew NestedClass),
                     protectedNC(gcnew NestedClass),
                     privateNC(gcnew NestedClass)
   {}

   // A member showing how to access NestedClass within SurroundClass
   // Notice only public member varibles of the nested class are accessed
   // The private and protected are hidden
   void method()  
   {
      int x;

      NestedClass nc1;              // Declared another reference NestedClass
 
      x = nc1.publicMember;         // Accessing new NestedClass variable

      x = publicNC->publicMember;   // Accessing public NestedClass variable
      x = protectedNC->publicMember;// Accessing protected NestedClass variable
      x = privateNC->publicMember;  // Accessing private NestedClass variable
   }
};

// A inhertied class showing how to access NestedClass within a member method
// Notice only public and protected NestedClass are accessed
// The private is hidden
ref class inheritSurroundClass : public SurroundClass
{
public:
   void method()
   {
      int x;

      NestedClass nc1;          // can access because NestedClass 
                                // declaration protected
      x = nc1.publicMember;

      x = publicNC->publicMember;
      x = protectedNC->publicMember;
   }
};

// The main function shows how to access NestedClass from outside SurroundClass
// inhertance tree
// Notice only the public NestedClass reference is accessible
void main()
{
   SurroundClass sc;
   int x = sc.publicNC->publicMember;
}
