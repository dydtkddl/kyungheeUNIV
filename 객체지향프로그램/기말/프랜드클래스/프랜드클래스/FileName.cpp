#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <random>
#include <cmath>
#include <vector>
#include <iomanip>
class ReadOnlyRational {
	int numerator;
	int denominator;
public:
	ReadOnlyRational(int n, int d) :numerator(n), denominator(d) {};
	int get_numerator() {
		return numerator;
	}
	int get_denominator() {
		return denominator;
	}
	friend class Fc;
};
class Fc {
public:
	void print(const ReadOnlyRational& r) {
		std::cout << r.numerator;
	}
};
int main() {
	std::random_device rdev;
	std::mt19937 mt(rdev());
	std::uniform_int_distribution<int> dist(0, 99);
	int hist[100] = { 0 };
	int r = dist(mt);
	ReadOnlyRational rr(1,3);
	Fc f;
	f.print(rr);

}