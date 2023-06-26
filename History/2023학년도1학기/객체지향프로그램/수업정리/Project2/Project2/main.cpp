#include <iostream>
// const className &operator++();
// const className &operator++(int
class Rational {
public:
	int numerator;
	int denominator;
	Rational(int n = 0, int d = 1) : numerator(n), denominator(d) {};
	const Rational& operator++() {
		numerator += denominator;
		return *this;
	};
	const Rational& operator++(int) {
		std::cout << "dasda" << std::endl;
		const Rational save(*this);
		numerator += denominator;
		return save;
	}
	operator double() const {
		return (double)numerator / denominator;
	};
};

std::ostream& operator<<(std::ostream& os, const Rational& r) {
	os << r.numerator << '/' << r.denominator;
	return os;
}
int main() {
	Rational r1(1, 5), r2, r3;
	r2 = r1++;
	std::cout << r2 << std::endl;
	r3 = ++r1;
	std::cout << r3 << std::endl;
	std::cout << (double)r1 << std::endl;
	std::cout << static_cast<double>(r1) << std::endl;
}