//BitStringBase.h
#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include "MyDerivedException.h"
#include "MyException.h"

using namespace std;

class BitStringBase
{
	long first;
	long second;

public:
	BitStringBase();
	BitStringBase(const BitStringBase& obj);
	BitStringBase(const long& first, const long& second) throw(logic_error);/////

	long GetFirst() { return first; }
	long GetSecond()  { return second; }
	void SetFirst(long value) { first = value; }
	void SetSecond(long value) { second = value; }

	BitStringBase& operator = (const BitStringBase&);
	operator string() const;

	friend ostream& operator << (ostream&, const BitStringBase&);
	friend istream& operator >> (istream&, BitStringBase&) throw(logic_error);/////
};


