//#include <iostream>
//class Rational {
//public:
//	int numerator;
//	int denominator;
//	Rational(int n = 0,int m = 1) : numerator(n), denominator(m) {};
//	const Rational& operator++() {
//		numerator += denominator;
//		return *this;
//		};
//	const Rational& operator++(int) {
//		Rational save(numerator, denominator);
//		numerator += denominator;
//		return save;
//	};
//	operator double() const {
//		return (double)numerator / (double)denominator;
//	}
//	
//};
//std::ostream& operator<< (std::ostream& os, const Rational& r) {
//	os << r.numerator << '/' << r.denominator << std::endl;
//	return os;
//};
//int main() {
//	Rational a(123, 421);
//	std::cout << a++;
//	std::cout << a;
//	std::cout << ++a;
//	std::cout << a;
//	std::cout << double(a) << std::endl;
//}

#include <iostream>
int gcd(int n, int m) {
	if (m == 0) {
		return n;
	}
	else {
		return gcd(m, n % m);
	}
}
class Rational {
public:
	int numerator;
	int denominator;
	Rational(int n = 0, int m = 1) :numerator(n), denominator(m) {};
	Rational& operator++() {
		numerator += denominator;
		return *this;
	}
	Rational& operator++(int) {
		Rational save(numerator, denominator);
		numerator += denominator;
		return save;
	}
	Rational& operator+(const Rational& r) {
		int nu = numerator * r.denominator + denominator * r.numerator;
		int de = denominator * r.denominator;
		int g = gcd(nu, de);
		Rational a = Rational(nu / g, de / g);
		return a;
	}
};

std::ostream& operator<< (std::ostream& os, const Rational& r) {
	os << r.numerator << '/' << r.denominator << std::endl;;
	return os;
}
int main() {
	Rational r(10, 5);
	Rational* r_ptr = new Rational(r);
	std::cout << r + *r_ptr << std::endl;
	r_ptr->operator++();
	std::cout << r + *r_ptr << std::endl;

}
































