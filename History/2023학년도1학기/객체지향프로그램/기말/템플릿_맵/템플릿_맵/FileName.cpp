#include <set>
#include <list>
#include <vector>
#include <map>
#include <iostream>
#include <string>

int main() {
	std::set<int> s;
	std::vector<int> v;
	std::list<int> l;
	std::map<std::string, int> st = { std::pair<std::string, int>("�ȿ��", 12) };
	st.insert(std::pair<std::string, int>("�۰���", 12));
	st.insert(std::pair<std::string, int>("�̽���", 112));
	st.insert(std::pair<std::string, int>("������", 122));
	for (auto i : st) {
		std::cout << i.first << std::endl;
		std::cout << i.second << std::endl;
	}
	for (auto iter = std::begin(st); iter != std::end(st); iter++) {
		std::cout << iter->first << std::endl;
		std::cout << iter->second << std::endl;
	}
}