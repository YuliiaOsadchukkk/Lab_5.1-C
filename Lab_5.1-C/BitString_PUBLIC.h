//BitString_PUBLIC.h
#pragma once
#include "BitStringBase.h"


class BitString_PUBLIC : public BitStringBase
{
public:
	BitString_PUBLIC() : BitStringBase() {}
	BitString_PUBLIC(const BitString_PUBLIC& obj) : BitStringBase(obj) {}
	BitString_PUBLIC(const long& first, const long& second) : BitStringBase(first, second) {}

	BitString_PUBLIC& operator --() throw(MyDerivedException);
	BitString_PUBLIC& operator ++() throw(MyException);
	BitString_PUBLIC operator --(int) throw(MyDerivedException);
	BitString_PUBLIC operator ++(int) throw(logic_error);

	friend BitString_PUBLIC operator ^ (BitString_PUBLIC& a, BitString_PUBLIC& b);
	friend BitString_PUBLIC operator << (BitString_PUBLIC& a, int n);
	friend BitString_PUBLIC operator >> (BitString_PUBLIC& a, int n);
};

