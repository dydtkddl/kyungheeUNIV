//1. �������� ���� �޾Ƽ� ������ �����
//2. ���Ϸ� �����ϱ�(�ؽ�Ʈ, ���̳ʸ�)
//3. ������� �̿��ϱ�
//4. �����ɶ� ������ ��ü ���Ƹ���
//5. ���۷����� �����ϱ� + - <<
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <cmath>
#include <random>
#include <sstream>
#include <iostream>
class Rational {
	int numerator;
	int denominator;
	// Compute the greatest common divisor (GCD) of two integers
	static int gcd(int m, int n) {
		if (n == 0)
			return m;
		else
			return gcd(n, m % n);
	}
	// Compute the least common multiple (LCM) of two integers
	static int lcm(int m, int n) {
		return m * n / gcd(m, n);
	}

public:
	Rational(int n, int d) : numerator(n), denominator(d) {
		if (d == 0) {
			std::cout << "*****Warning---Illegal Rational\n";
			numerator = 0; // Make up a reasonable default fraction
			denominator = 1;
		}
	}
	// Default fraction is 0/1
	Rational() : numerator(0), denominator(1) {}
	int get_numerator() const {
		return numerator;
	}
	int get_denominator() const {
		return denominator;
	}
Rational reduce() const {
	int factor = gcd(numerator, denominator);
	//return Rational(numerator/factor, denominator/factor);
	return { numerator / factor, denominator / factor };
}
// Equal fractions have identical numerators and denominators
bool operator==(const Rational& fract) const {
	Rational f1 = reduce(),
		f2 = fract.reduce();
	// ...then see if their components match.
	return (f1.numerator == f2.numerator)
		&& (f1.denominator == f2.denominator);
}

bool operator!=(const Rational& other) const {
	return !(*this == other);
}
Rational operator+(const Rational& fract) const {
	int commonDenominator = lcm(denominator, fract.denominator);
	int newNumerator = numerator * commonDenominator / denominator
		+ fract.numerator * commonDenominator / fract.denominator;
	return { newNumerator, commonDenominator };
}
Rational operator*(const Rational& fract) const {
	return Rational(numerator * fract.numerator,
		denominator * fract.denominator).reduce();
}
};
std::ostream& operator<<(std::ostream& os, const Rational& r) {
	os << r.get_numerator() << "/" << r.get_denominator();
	return os;
}

int main() {
	std::random_device rdev;
	std::mt19937 mt(rdev());
	std::uniform_int_distribution<int> dist(0, 300);
	int r = dist(mt);
	std::ifstream ifs;
	std::ofstream ofs;
	Rational f1(4, 124), f2(1, 3);
	std::cout << f1 << " + " << f2 << " = " << (f1 + f2) << '\n';
	std::cout << f1 << " * " << f2 << " = " << (f1 * f2) << '\n';
}