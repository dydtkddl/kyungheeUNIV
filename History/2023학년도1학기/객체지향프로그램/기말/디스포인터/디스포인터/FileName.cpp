#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <stdio.h>
#include <random>
class Account {
public:
	Account(std::string name, int id, float amount) :
		name(name), id(id), balance(amount) {};
	std::string name;
	float balance;
	int id;
	void display() {
		std::cout << this->id << std::endl;
		std::cout << this->name << std::endl;
		std::cout << this->balance << std::endl;
	}
};
int main() {
	std::random_device rdev;
	std::mt19937 mt(rdev());
	std::uniform_int_distribution<int> dist(0, 10);
	int hist[100] = { 0 };
	int r = dist(mt);
	std::vector<Account*> accvec(5);
	std::string name;
	float balance;
	int id;
	for (int i = 0; i < 5; i++) {
		std::cin >> name >> id >> balance;
		accvec[i] = new Account(name, id, balance);
		accvec[i]->display();
	}


	for (int i = 0; i < 5; i++) {
		delete accvec[i];
	}
}