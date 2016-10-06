// Compile from command line using
// cl /LD TestCOM
// regsvr32 TestCOM.dll

#define _ATL_ATTRIBUTES
#include <atlbase.h>
#include <atlcom.h>

[module(name="TestCOM",type="dll")];

// ITestCOM interface with Square method
[dual]
__interface ITestCOM : IDispatch
{
    [id(0x01)] HRESULT Square([in]LONG Value, [out,retval]LONG* Result);
};

// coclass CTestCOM implements the ITestCOM interface
[coclass, threading="both"]
class CTestCOM : public ITestCOM
{
    HRESULT Square(LONG Value, LONG* Result)
    {
        if (Value > 0x0ffff)
        {
            *Result = -1;
            return E_INVALIDARG;
        }
        else
        {
            *Result = Value * Value;
            return S_OK;
        }
    }
};
