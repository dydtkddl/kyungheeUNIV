#include <iostream>
#include <string>
#include <set>
#include <list>

int main() {
	std::set<int> s{ 1,445,4,2,1,1,1,1,3,4 };
	for (auto i : s) {
		std::cout << i << ',';
	}
	for (auto iter = std::begin(s); iter != std::end(s); iter++) {
		std::cout << *iter << std::endl;
	}
	s.insert(123);//
	s.insert(55);//
	for (auto i : s) {
		std::cout << i << std::endl;
	}
	for (auto iter = std::begin(s); iter != std::end(s); iter++) {
		std::cout << *iter << std::endl;
	}
}