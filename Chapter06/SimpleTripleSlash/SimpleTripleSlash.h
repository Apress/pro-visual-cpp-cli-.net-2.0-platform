// SimpleTripleSlash.h

#pragma once

using namespace System;
using namespace System::IO;


namespace SimpleTripleSlash
{
	/// <summary>
	///   This is a summary comment for Class1
	/// </summary>
	public ref class Class1
	{
	public:
		/// <summary>This is a summary comment for Method1 <see cref="File">Boo Boo</see>
		/// <seealso cref="System::Int32"/>
		/// </summary>
		void Method1() {}

		/// <summary>This is a summary comment for Variable1</summary>
		int Variable1;
	};
}
