/*
 * Sin-Yaw Wang <swang24@scu.edu>
 *
 * Assignment: Rational Number
 */
#ifndef RATNAM_H
#define RATNAM_H

using rat_t = int;
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
