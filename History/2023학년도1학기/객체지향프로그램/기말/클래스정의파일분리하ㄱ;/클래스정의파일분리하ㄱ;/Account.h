#pragma once
#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <iostream>
#include <vector>
#include <string>
class Account {
public:
	Account() {};
	Account(std::string name, int id, float balance) :
		name(name), id(id), balance(balance) {};
	std::string name;
	float balance;
	int id;
	void display() {
		std::cout << this->id << std::endl;
		std::cout << this->balance << std::endl;
		std::cout << this->name << std::endl;
		//쉬프트알트 동시선택
	}
};


#endif
