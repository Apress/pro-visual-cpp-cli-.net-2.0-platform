#pragma once

using namespace System;
using namespace System::IO;

namespace AllTags
{
    public ref class AClass
    {
    public:

        /// <summary> 
        /// This is a summary tag for the summaryTag() method 
        /// </summary>
        void summaryTag() {}

        /// <param name="param1">The first int parameter</param>
        /// <param name="param2">The second String^ parameter</param>
        void paramTag(int param1, String ^param2) {}

        /// <returns> returnsTag returns an int </returns>
        int returnsTag() {return 0;}

        /// <value> valueTag property has a value of double</value>
        property double valueTag
        {
            double get() {return 0.0;}
            void set(double val) {}
        }

        /// <remarks> 
        /// This is a remarks tag for the remarksTag() method 
        /// </remarks>
        void remarksTag() {}

        /// <example>
        ///   <para> Example summary </para>
        ///   <para>[Visual Basic]</para>
        ///   <code> 
        ///   Visual Basic .NET code example
        ///   </code>
        ///   <para>[C#]</para>
        ///   <code>
        ///   C# code example
        ///   </code>
        ///   <para>[C++]</para>
        ///   <code>
        ///   C++ code example
        ///   </code>
        /// </example>
        void exampleTag() {}

        /// <exception cref="System::OverflowException"> 
        /// This method might throw this exception (NOT)
        /// </exception> 
        void exceptionTag() {}

        /// <permission cref="System::Security::PermissionSet">
        ///   Go ahead anyone can access me.
        /// </permission>
        void permissionTag() {}

        /// <summary> 
        /// Some <c>Program code</c> in a summary 
        /// </summary>
        void cTag() {}

        /// <example>
        /// Some code in an example tag
        /// <code> 
        ///   A code statement;
        ///   Another code statement;
        /// </code>
        /// </example>
        void codeTag() {}

        /// <summary> 
        /// <para>This is the first paragraph which spans nore than one line 
        /// When the document window is small enough.</para><para>This is the 
        /// next paragraph which started in a new line.</para>
        /// </summary>
        void paraTag() {}

        /// <summary> 
        /// A bullet list
        /// <list type="bullet">
        ///   <item> bullet </item>
        ///   <item> bullet </item>
        /// </list>
        /// A numbered list
        /// <list type="number">
        ///   <item> entry 1 </item>
        ///   <item> entry 2 </item>
        ///   <item> entry n </item>
        /// </list>
        /// A table
        /// <list type="table">
        ///   <item>
        ///     <description>row 1 -- column a</description>
        ///     <description>row 1 -- column b</description>
        ///     <description>row 1 -- column c</description>
        ///   </item>
        ///   <item>
        ///     <description>row 2 -- column a</description>
        ///     <description>row 2 -- column b</description>
        ///     <description>row 2 -- column c</description>
        ///   </item>
        /// </list>
        /// A definition of terms
        /// <list type="table">
        ///   <listheader>
        ///     <term>Properties</term>
        ///     <description>Initial Value</description>
        ///   </listheader>
        ///   <item>
        ///     <term>term1 name</term>
        ///     <description>term1 description</description>
        ///   </item>
        ///   <item>
        ///     <term>term2 name</term>
        ///     <description>term2 description</description>
        ///   </item>
        ///   <item>
        ///     <term>termN name</term>
        ///     <description>termN description</description>
        ///   </item>
        /// </list>
        /// </summary>
        void listTag() {}

        /// <summary> This is a summary with an &lt;include&gt; tag containing 
        ///    a &lt;list type="bullet"&gt;
        ///    <include file='document.xml' path='AllDoc/Entry[@num="1"]/*' />
        /// </summary>
        /// <include file='document.xml' path='AllDoc/Entry[@num="2"]/*' />
        void includeTag() {}

        /// <summary> This summary reference the <paramref name="param1"/> 
        /// parameter of the method
        /// </summary>
        void paramrefTag(int param1) {}

        /// <summary>
        /// The basic see tag <see cref="File" />
        /// The enhanced see tag <see cref="FileInfo">System::IO:FileInfo</see>
        /// </summary>
        void seeTag() {}

        /// <summary>
        /// The basic see tag [<seealso cref="File" />] Nothing here
        /// The enhanced see tag <seealso cref="FileInfo">FileInfo</seealso>
        /// </summary>
        void seealsoTag() {}
    };
}
