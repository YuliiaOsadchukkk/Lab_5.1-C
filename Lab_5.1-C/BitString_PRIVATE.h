//BitString_PRIVATE.h
#pragma once
#include "BitStringBase.h"


using namespace std;

class BitString_PRIVATE : private BitStringBase
{
public:


	BitString_PRIVATE() :BitStringBase() {}

	BitString_PRIVATE(const BitString_PRIVATE& obj) : BitStringBase(obj) {}
	BitString_PRIVATE(const long& first, const long& second) : BitStringBase(first, second) {}	

	friend ostream& operator << (ostream& out, const BitString_PRIVATE& a);
	friend istream& operator >> (istream& in, BitString_PRIVATE& a) throw(logic_error);/////

	BitString_PRIVATE& operator --() throw(MyDerivedException);
	BitString_PRIVATE& operator ++() throw(MyException);
	BitString_PRIVATE operator --(int) throw(MyDerivedException);
	BitString_PRIVATE operator ++(int) throw(logic_error);

	friend BitString_PRIVATE operator ^ (BitString_PRIVATE& a, BitString_PRIVATE& b);
	friend BitString_PRIVATE operator << (BitString_PRIVATE& a, int n);
	friend BitString_PRIVATE operator >> (BitString_PRIVATE& a, int n);

};


