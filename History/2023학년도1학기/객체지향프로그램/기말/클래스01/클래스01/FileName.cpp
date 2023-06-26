#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
class Account {
public:
	std::string name="123";
	int id=0;
	double balance=0;
};
template<typename T>
void add_account(std::vector<T>& vec) {
	std::string name;
	int id = vec.size();
	float balance;
	std::cin >> name >> balance;
	Account acc;
	acc.id = id;
	acc.name = name;
	acc.balance = balance;
	vec.push_back(acc);
}
template<typename T>
void print(const std::vector<T>& vec) {
	for (T acc : vec) {
		std::cout << "----------" << std::endl;
		std::cout << acc.name << std::endl;
		std::cout << acc.id<< std::endl;
		std::cout << acc.balance<< std::endl;
		std::cout << "----------" << std::endl;
	}
}
int main() {
	std::vector<Account>vec;
	for (int i=0; i<5; i++) add_account(vec);
	print(vec);
}