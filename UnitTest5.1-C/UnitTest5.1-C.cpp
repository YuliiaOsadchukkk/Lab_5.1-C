#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5.1-C/BitString_PUBLIC.h"
#include "../Lab_5.1-C/BitString_PUBLIC.cpp"
#include "../Lab_5.1-C/BitStringBase.h"
#include "../Lab_5.1-C/BitStringBase.cpp"
#include "../Lab_5.1-C/MyException.h"
#include "../Lab_5.1-C/MyException.cpp"
#include "../Lab_5.1-C/MyDerivedException.h"
#include "../Lab_5.1-C/MyDerivedException.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest51C
{
	TEST_CLASS(UnitTest51C)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			
			BitString_PUBLIC a, b;
			a.SetFirst(0);
			a.SetSecond(0);

			b.SetFirst(0);
			b.SetSecond(0);

			BitString_PUBLIC c = (a ^ b);
			Assert::AreEqual(c.GetFirst(), 0l);
			Assert::AreEqual(c.GetSecond(), 0l);
			
		}
	};
}
