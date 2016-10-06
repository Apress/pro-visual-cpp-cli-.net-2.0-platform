#include "Documentation.h"

namespace Documentation
{
    // ------------- DescriptionAttribute -------------------

    DescriptionAttribute::DescriptionAttribute(String ^Author, String ^Description)
    {
        mAuthor = Author;
        mDescription = Description;
        mCompileDate = DateTime::Now;
    }

    String^ DescriptionAttribute::Author::get()
    {
        return mAuthor;
    }

    String^ DescriptionAttribute::Description::get()
    {
        return mDescription;
    }

    String^ DescriptionAttribute::CompileDate::get()
    {
        return mCompileDate.ToShortDateString();
    }

    // ------------- HistoryAttribute -------------------

    HistoryAttribute::HistoryAttribute(String ^Author, String ^Description)
    {
        mAuthor = Author;
        mDescription = Description;
        mModifyDate = DateTime::Now;
    }

    String^ HistoryAttribute::Author::get()
    {
        return mAuthor;
    }

    String^ HistoryAttribute::Description::get()
    {
        return mDescription;
    }

    String^ HistoryAttribute::ModifyDate::get()
    {
        return mModifyDate.ToShortDateString();
    }

    void HistoryAttribute::ModifyDate::set(String ^value)
    {
        mModifyDate = Convert::ToDateTime(value);
    }
}