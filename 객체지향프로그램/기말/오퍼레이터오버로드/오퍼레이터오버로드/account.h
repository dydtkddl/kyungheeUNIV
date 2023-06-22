#pragma once
#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <string>
#include <iostream>
#include <vector>
class Account {
public:
	std::string name;
	int id;
	float balance;
	Account() {};
	Account(std::string name, int id, float balance) :
		name(name), id(id), balance(balance) {};
	void display() {
		std::cout << this->name << std::endl;
		std::cout << this->id << std::endl;
		std::cout << this->balance << std::endl;
	};
};
#endif