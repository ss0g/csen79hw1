/*
 * Names: Javely Benitez, Troy Edwards, Ashley Kaur, Anjie Obasunloye, Joy Zhu
 * Emails: jtejedabenitez@scu.edu, tedwards2@scu.edu, akaur3@scu.edu, aobasunloye@scu.edu, jhzhu@scu.edu
 *
 * Assignment: Rational Number
 */
#include <cstdio>
#include <limits>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include "ratnum.h"

using namespace std;	// for ostream

namespace csen79 {
	/*
	 * Construct a rational number.  Accept one or two integers.
	 * If only one, assume the denominator is 1.
	 * Otherwise, simplify the rational number by dividing both with GCD.
	 */
	RatNum::RatNum(rat_t n, rat_t d) : num(n), den(d) {
		if (d == 0)
			throw std::invalid_argument("denominator cannot be zero");
		if (d < 0) {
			n = -n;
			d = -d;
		}
		
		int todivide = gcd(abs(n), d);
		num = n/todivide;
		den = d/todivide;
	}

	// trivial implementaion of GCD
	unsigned int RatNum::gcd(unsigned int a, unsigned int b) {
		if (a == 0)
			return b;
		return gcd(b % a, a);
	}

	ostream& operator<<(ostream& os, const RatNum& n) {
		if (n.den == 1 || n.num == 0)	
			os << n.num;
		else
			os << n.num << '/' << n.den;
		return os;
	}

	RatNum RatNum::operator+(RatNum const &n1) {
    	if (den == 0 || n1.den == 0) {
      		throw std::invalid_argument("denominator cannot be zero");
    	}
		if (den < MinRat || n1.den < MinRat) {
			throw std::overflow_error("denominator too small");
		}
		if (num > MaxRat || n1.num > MaxRat) {
			throw std::overflow_error("numerator too large");
		}
    	if (den == n1.den) {
      		if (num >= MaxRat - n1.num) {
        		throw std::overflow_error("argument too large");
      		}
      		return RatNum(num + n1.num, den);
    	}
    	if (num > MaxRat / n1.den || n1.num > MaxRat / den) {
      		throw std::overflow_error("argument too large");
    	}
    	return RatNum(num * n1.den + n1.num * den, den * n1.den);
	}

	/*
	RatNum RatNum::operator-(RatNum const &n1) { return RatNum();}
	RatNum RatNum::operator*(RatNum const &n1) { return RatNum();}
	RatNum RatNum::operator/(RatNum const &n1) { return RatNum();}
	bool RatNum::operator<(RatNum const &n1) { return true;}
	bool RatNum::operator==(RatNum const &n1) {return true;}
	*/
}

