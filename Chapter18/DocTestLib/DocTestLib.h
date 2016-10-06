// DocTestLib.h

#pragma once

using namespace System;
using namespace Documentation;

namespace DocTestLib
{
    [Description("Stephen Fraser", 
                 "This is TestClass1 to test the documentation Attribute.")]
    [History("Stephen Fraser", "Original Version.", ModifyDate="11/27/02")]
    [History("Stephen Fraser", "Added DoesNothing Method to do nothing.")]
    public ref class TestClass1
    {
    public:
        [Description("Stephen Fraser", 
                     "This is default constructor for TextClass1.")]
        TestClass1() {}

        [Description("Stephen Fraser", 
                     "This is method does nothing for TestClass1.")]
        void DoesNothing() {}

        [Description("Stephen Fraser", "Added Variable property.")]
        [History("Stephen Fraser", "Removed extra CodeDoc Attribute")]
        property String^ Variable;
    };

    [Description("Stephen Fraser", 
                 "This is TestClass2 to test the documentation Attribute.")]
    public ref class TestClass2
    {
    };
}
