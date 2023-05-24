#include <iostream>
#include <vector>
void print_v(std::vector<int> v) {
	for (int i : v) {
		std::cout << i << ',';
	}
}
void print_v2d(std::vector<std::vector<int>> v) {
	for (std::vector<int> v_: v) {
		for (int i : v_) {
			std::cout << i << ',';
		}
		std::cout << std::endl;
	}
}
int main() {
	std::vector<int> a;
	std::vector<int> a1(10);
	std::vector<int>a2 = { 1,2,3,45 };
	std::vector<std::vector<int>> v = { {1,2},{2,3} };
	print_v2d(v);
	print_v(a);
	print_v(a1);
	print_v(a2);
	a1.assign(10, 32);
	print_v(a1);
	std::cout << "aÇÁ¸°Æ®" << std::endl;
	print_v(a);
	a.assign(12, 999);
	print_v(a);
}