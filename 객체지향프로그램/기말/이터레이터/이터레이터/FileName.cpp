#include <iostream>
#include <map>
#include <string>
#include <vector>
//이터레이터
	//1) 역으로 프린트하는거
	//2) 피라미드 형식으로 프린트하는거

void print_reverse(const std::map<int, std::string>& a) {
	auto be = a.begin();
	auto en= a.end();
	while (en != be) {
		en--;
		std::cout << en->first << std::endl;
		std::cout << en->second << std::endl;
	}
}
int main() {
	std::map<int, std::string> a;
	a.insert(std::pair<int, std::string>(1, "안용상"));
	a.insert(std::pair<int, std::string>(2, "이도헌"));
	a.insert(std::pair<int, std::string>(3, "이수민"));
	for (auto ir : a) {
		std::cout << ir.first << std::endl;
		std::cout << ir.second<< std::endl;
	}
	std::map<int, std::string>::iterator iter = a.begin();
	for (auto i = iter; i!= a.end(); i++) {
		std::cout << iter->first << iter->second;
	}
	print_reverse(a);
	for (int i = 1; i < a.size(); i++) {
		for (auto iter = std::begin(a); iter != std::next(std::begin(a), i+1); iter++) {
			std::cout << iter->first << iter->second;


		}
		std::cout << '\n';

	}
	std::vector<int> vec{ 10, 20, 30, 40, 50 };
	for (int i = 1; i <= vec.size(); ++i) {
		for (auto iter = std::begin(vec); iter != std::next(std::begin(vec) , i)
			; iter++)
			std::cout << *iter << ' ';
		std::cout << '\n';
	}
}