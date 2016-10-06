// FindZipCode.cpp : main project file.

#include "stdafx.h"
#include "FindZipCodeClass.h"
#include "Global.asax.h"


namespace FindZipCode
{
    int FindZipCodeClass::GetZip(String ^city, String ^state)
    {
        // Obviously very simplified 
        if (city->Equals("Louisville") && state->Equals("KY"))
            return 40241;
        else if (city->Equals("San Jose") && state->Equals("CA"))
            return 95138;
        else
            throw gcnew Exception("Zip Code not found");
    }
};

