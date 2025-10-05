/*
 * Names: Javely Benitez, Troy Edwards, Ashley Kaur, Anjie Obasunloye, Joy Zhu
 * Emails: jtejedabenitez@scu.edu, tedwards2@scu.edu, akaur3@scu.edu, aobasunloye@scu.edu, jhzhu@scu.edu
 *
 * Assignment: Rational Number
 */
#ifndef RATNUM_H
#define RATNUM_H

using rat_t = int;

constexpr rat_t MaxRat = std::numeric_limits<rat_t>::max();
constexpr rat_t MinRat = std::numeric_limits<rat_t>::min();

namespace csen79 {
	class RatNum {
	public:
		RatNum(): RatNum(0) {};
		RatNum(const RatNum &n): RatNum(n.num, n.den) {}
		RatNum(rat_t, rat_t n=1);

		// These are member functions
		RatNum operator+(RatNum const &n1);
		RatNum operator-(RatNum const &n1);
		RatNum operator*(RatNum const &n1);
		RatNum operator/(RatNum const &n1);
		bool operator<(RatNum const &n1);
		bool operator==(RatNum const &n1);

	private:
		rat_t num;
		rat_t den;
		void simplify(void);
		unsigned int gcd(unsigned, unsigned);

	// this is not a member function
	friend std::ostream& operator<<(std::ostream& os, const RatNum& n);
	};
}
#endif
