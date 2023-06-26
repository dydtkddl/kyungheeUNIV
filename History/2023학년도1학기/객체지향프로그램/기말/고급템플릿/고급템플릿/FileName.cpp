#include <list>
#include <vector>
#include <iostream>
#include <string>

int main() {
	std::list<int> ls{ 1,2,3,4,5 };
	for (auto i : ls) {
		std::cout << i << std::endl;
	}
	std::cout << std::endl;
	for (auto iter = std::begin(ls); iter != std::end(ls); iter++) {
		std::cout << *iter << std::endl;

	}
}