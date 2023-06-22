#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <iomanip>
template<typename T>
void print(T a) {
	std::cout << a << std::endl;
}
template<typename T>
void print(std::vector<T> a) {
	for (int x : a) {
		std::cout << x << ',' << std::endl;
	}
	std::cout << std::endl;
}
template<typename T>
T sum(const std::vector<T>& v) {
	int sum=0;
	for (T vv : v) {
		sum += vv;
	}
	return sum;
}
template<typename T>
void swap(T& a, T& b) {
	T c = a;
	a = b;
	b = c;
}
template<int N>
int scale(int value) {
	return value * N;
}
template<typename T, int N>
T scale(T value) {
	return N * value;
}
int main() {
	std::random_device rdev;
	std::mt19937 mt(rdev());
	std::uniform_int_distribution<int> dist(0, 99);
	std::vector<double> s;
	double r = double(dist(mt));
	s.resize(134);
	for (int i = 0; i < 134; i++) {
		s[i] = r * i;
		r = double(dist(mt));
	}
	print(s);
	double su = sum<double>(s);
	print(su);
	
	double sss = 123;
	swap(sss, su);
	scale<132>(sss);
	print(scale<double, 23>(1.44));
}