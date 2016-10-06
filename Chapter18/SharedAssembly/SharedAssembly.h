#pragma once

using namespace System;
using namespace System::Reflection;

namespace SharedAssembly
{
    public ref class SharedClass
    {
    public:
		property System::Version^ Version
        {
			System::Version^ get()
			{
				Assembly ^assembly = Assembly::GetExecutingAssembly();
				return assembly->GetName()->Version;
			}
        }
    };
}
