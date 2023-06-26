#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>//
template<typename T>
void print(T a) {
	std::cout << a << std::endl;
}
template<typename T>
void print(std::vector<T> a) {
	for (int i = 0; i < a.size(); i++) {
		std::cout << a[i] << ", ";
	}
	std::cout << std::endl;
}
int main() {
	std::stringstream ss;
	for (int i = 0; i < 10; i++) {
		ss << i << ", ";
	}
	std::cout << ss.str() << std::endl;

	int number = 123;
	std::stringstream ss2;
	ss2 << number;
	std::string str = ss2.str();
	std::cout << ss2.str();
}