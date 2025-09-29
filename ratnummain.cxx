/*
 * Sin-Yaw Wang <swang24@scu.edu>
 *
 * Assignment: Rational Number
 */
#include <cstdio>
#include <iomanip>
#include <iostream>
#include "ratnum.h"

using namespace std;	// for ostream
using namespace csen79;

int main(int argc, char *argv[])
{
	constexpr int LOOP=20;
	RatNum x(1, 3);	// basic construction
	RatNum y(x);	// copy construction
	RatNum z(-124);	// construction with one argument
	RatNum w;		// construction with zero argument
	w = y;	// assignment

	// Replace these with your test code
	cout << x << endl;
	cout << y << endl;
	cout << z << endl;
	cout << w << endl;
	cout << "Try operators" << endl;
	int loop = LOOP;
	rat_t n1, d1;
	rat_t n2, d2;
	int i = 0;
	while (loop-- >= 0 && (cin >> n1 >> d1) && (cin >> n2 >> d2)) { 
		cout << "#" << i++ << ": " << endl;
		x = RatNum(n1, d1);
		y = RatNum(n2, d2);
		RatNum z;
		cout << "op1=" << x << endl;
		cout << "op2=" << y << endl;
		z = x + y;
		cout << "op1+op2=" << z << endl;
		z = x - y;
		cout << "op1-op2=" << z << endl;
		z = x * y;
		cout << "op1*op2=" << z << endl;
		z = x / y;
		cout << "op1/op2=" << z << endl;
		if (x < y)
			cout << "(op1<op2) == True" << endl;
		if (x == static_cast<const RatNum>(y))
			cout << "(op1==op2) == True" << endl;
	}
	return EXIT_SUCCESS;
}
