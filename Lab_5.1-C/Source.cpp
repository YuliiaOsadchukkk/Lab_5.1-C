//Source.cpp
#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <sstream>
#include "BitString_PUBLIC.h"
#include "BitString_PRIVATE.h"

void _unexpected_to_bad()
{
	cerr << "bad_exception" << endl;
	throw;
}

void Call_Bad() throw(int)
{
	throw 'x';
}

using namespace std;

int main()
{
	set_unexpected(_unexpected_to_bad);

	try
	{
		cout << "BitString_PRIVATE" << endl;
		BitString_PRIVATE B(0, 1);
		cout << B << endl << endl;


		cout << "Size of class: " << sizeof(B) << endl;

		cout << "--------------------------------------------------------" << endl;

		BitString_PRIVATE o;
		int n;
		int z;
		cin >> o;
		cout << o << endl << endl;
		// ShiftLeft
		cout << "How many bits do you want to shift left?" << endl;
		cout << "Input:  "; cin >> n;
		BitString_PRIVATE a = o << n;
		cout << a << endl << endl;

		// ShiftRight
		cout << "How many bits do you want to shift right?" << endl;
		cout << "Input:  "; cin >> z;
		BitString_PRIVATE b = o >> z;
		cout << b << endl << endl;

		// Xor
		cout << "Xor: " << endl;
		cout << (a ^ b) << endl;

		cout << "try o--" << endl;
		try
		{
			o--;
		}
		catch (MyDerivedException a)
		{
			cerr << a.What() << endl << endl;
		}
		catch (MyDerivedException* a)
		{
			cerr << a->What() << endl << endl;
		}
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}


	cout << "--------------------------------------------------------" << endl;

	BitString_PRIVATE N;
	cin >> N;
	cout << N;

	cout << endl << "try N++" << endl;
	try
	{
		N++;
	}
	catch (MyException& a)
	{
		cerr << "Exception: " << a.What() << endl;
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	try
	{
		Call_Bad();
	}
	catch (bad_exception)
	{
		cerr << "catch (bad_exception)" << endl;
	}




	cout << "====================================================================" << endl;

	try
	{
		cout << "PUBLIC" << endl;
		BitString_PUBLIC Bo( 0,1 );
		cout << Bo << endl << endl;


		cout << "Size of class: " << sizeof(Bo) << endl;

		cout << "--------------------------------------------------------" << endl;

		BitString_PUBLIC oo;
		int no;
		int zo;
		cin >> oo;
		cout << oo << endl << endl;
		// ShiftLeft
		cout << "How many bits do you want to shift left?" << endl;
		cout << "Input:  "; cin >> no;
		BitString_PUBLIC ao = oo << no;
		cout << ao << endl << endl;

		// ShiftRight
		cout << "How many bits do you want to shift right?" << endl;
		cout << "Input:  "; cin >> zo;
		BitString_PUBLIC bo = oo >> zo;
		cout << bo << endl << endl;

		// Xor
		cout << "Xor: " << endl;
		cout << (ao ^ bo) << endl;

		cout << "try o--" << endl;
		try
		{
			oo--;
		}
		catch (MyDerivedException a)
		{
			cerr << a.What() << endl << endl;
		}
		catch (MyDerivedException* a)
		{
			cerr << a->What() << endl << endl;
		}
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}


	cout << "--------------------------------------------------------" << endl;

	BitString_PUBLIC No;
	cin >> No;
	cout << No;

	cout << endl << "try N++" << endl;
	try
	{
		No++;
	}
	catch (MyException& a)
	{
		cerr << "Exception: " << a.What() << endl;
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	try
	{
		Call_Bad();
	}
	catch (bad_exception)
	{
		cerr << "catch (bad_exception)" << endl;
	}

	return 0;
}
