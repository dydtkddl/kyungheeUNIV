#include <iostream>
#include <iomanip>
#include <random>

int main() {
	std::random_device rdev;
	std::mt19937 mt(rdev());
	std::uniform_int_distribution<int> dist(0, 49);
	int hist[50] = { 0 };
	for (int i = 0; i < 100000; i++) {
		int r = dist(mt);
		hist[r]++;
	}
	for (int i = 0; i < 50; i++) {
		std::cout << hist[i] << std::endl;
	}
}