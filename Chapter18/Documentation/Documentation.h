#pragma once

using namespace System;
using namespace System::Text;
using namespace System::Reflection;

namespace Documentation
{
    [AttributeUsage(AttributeTargets::All, Inherited=true, AllowMultiple=false)]
    public ref class DescriptionAttribute : public Attribute
    {
        String  ^mAuthor;
        DateTime mCompileDate;
        String  ^mDescription;

    public:
        DescriptionAttribute(String ^Author, String ^Description);

        property String^ Author { String^ get(); }
        property String^ Description { String^ get(); }
        property String^ CompileDate { String^ get(); }
    };

    [AttributeUsage(AttributeTargets::All, Inherited=true, AllowMultiple=true)]
    public ref class HistoryAttribute : public Attribute
    {
        String  ^mAuthor;
        DateTime mModifyDate;
        String  ^mDescription;

    public:
        HistoryAttribute(String ^Author, String ^Description);

        property String^ Author { String^ get(); }
        property String^ Description { String^ get(); }
        property String^ ModifyDate
        {
            String^ get();
            void set(String^ value);
        }
    };
}
