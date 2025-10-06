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
		long long temp_64 = 0;

    	if (den == 0 || n1.den == 0) {
			throw std::invalid_argument("Error 1: denominator cannot be zero");
    	}
		if (num > MaxRat || n1.num > MaxRat) {
			throw std::overflow_error("Error 2: numerator too large");
		}

		cout << "num = " << num << ", den = " << den << endl;
		cout << "n1.num = " << n1.num << ", n1.den = " << n1.den << endl;
    	if (den == n1.den) {
			if (num > 0 && n1.num > 0) {	// might have overflow --> check num + n1.num <= MaxRat
				if (num > MaxRat - n1.num) {
        			throw std::overflow_error("Error 3: numerator argument too large");
				}
			}
			if (num < 0 && n1.num < 0) {	// might have underflow --> check num + n1.num >= MinRat
				if (num < MinRat - n1.num) {
					throw std::underflow_error("Error 4: numerator argument too small");
				}
			}
			return RatNum(num + n1.num, den);
    	}

		/* Two Constraints for (num * n1.den + n1.num * den) / (den * n1.den)
		 * 1. MinRat <= num * n1.den + n1.num * den <= MaxRat
		 	  MinRat <= num * n1.den + n1.num * den --> (MinRat - n1.num * den) / n1.den <= num
			  num * n1.den + n1.num * den <= MaxRat --> num <= (MaxRat - n1.num * den) / n1.den
		 * 2. den * n1.den <= MaxRat  (all denominators are positive at this point)
		*/
		temp_64 = num * n1.den;
		if (temp_64 > MaxRat) {	// check num * n1.den <= MaxRat
			throw std::overflow_error("Error 5: argument overflow");
		}
		if (temp_64 < MinRat) {	// check MinRat <= num * n1.den
			throw std::underflow_error("Error 6: argument underflow");
		}
		temp_64 = n1.num * den;
		if (n1.num > 0 && (temp_64 > MaxRat)) {	// check n1.num * den <= MaxRat
			throw std::overflow_error("Error 7: argument overflow");
		}
		if (n1.num < 0 && (temp_64 < MinRat)) {	// check MinRat <= n1.num * den
			throw std::underflow_error("Error 8: argument underflow");
		}
		if (num > 0 && n1.num > 0) {
			/* Checking for overflow from num * n1.den + n1.num * den <= MaxRat
			 * We have: num * n1.den <= MaxRat
			 *          n1.num * den <= MaxRat
			 * 			num * n1.den <= MaxRat - n1.num * den
			*/
			if ((num * n1.den) > (MaxRat - n1.num * den)) {
            	throw std::overflow_error("Error 9: argument too large");
			}
		}
		if (num < 0 && n1.num < 0) {
			/* Checking for overflow from MinRat <= num * n1.den + n1.num * den
			 * We have: MinRat <= num * n1.den
			 *          MinRat <= n1.num * den
			 * 			num * n1.den <= MinRat - n1.num * den
			*/
			if ((num * n1.den) < (MinRat - n1.num * den)) {
            	throw std::underflow_error("Error 10: argument too small");
			}
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

