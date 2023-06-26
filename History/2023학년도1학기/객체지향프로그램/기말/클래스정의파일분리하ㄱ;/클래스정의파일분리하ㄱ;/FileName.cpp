#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <string>
#include <iomanip>
#include <random>
#include "Account.h"
int main() {
	//氦磐积己规过 1
	std::vector<Account*> acc(100);
	std::string name = "救侩惑";
	float b=1232124;
	int id=12;
	for (Account* a : acc) {
		a = new Account(name, b, id);
	}
	//氦磐积己规过 2
	std::vector<Account> acc2(100);
	for (Account a : acc2) {
		a.display();
		a.id = 123;
		a.name = "123";
		a.balance = 12455;
		a.display();
	}

}