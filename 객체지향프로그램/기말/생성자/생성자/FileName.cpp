#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <random>
class Account {
	std::string name;
	int id;
	float balance;
public:
	Account(const std::string& str, int id, float balance) :name(str), id(id), balance(balance) {
		if (balance < 0) {
			std::cout << "0���� ū �ݾ� \n";
			balance = 0.0;
	}
	};
	void deposit(float amount) {
		if (amount > 0) balance += amount;
		else std::cout << "0����ū�ݾ��Է��ϼ�" << std::endl;
	}
	bool withdraw(float amount) {
		if ((balance - amount) >= 0) {
			balance -= amount;
			return true;
		}

		else {
			std::cout << "�ܾ׺���" << std::endl;
			return false;
		}

	}
	void display() {
		std::cout << "NAME : " << name << std::endl;
		std::cout << "ID : " << id << std::endl;
		std::cout << "remain balance : " << balance << std::endl;
	}
	int getid() const{
		return id;
	}
	std::string getname() const{
		return name;
	}
	float getbalance() const{
		return balance;
	}

};
void add_account(std::vector<Account>& vec) {
	std::string name;
	float balance;
	std::cout << "�̸��Է� : ";
	std::cin >> name;
	std::cout << std::endl << "�ݾ��Է� : ";
	std::cin >> balance;
	int id = vec.size();
	vec.push_back(Account(name, id, balance));
}
bool  display_all_account(const std::vector<Account>& vec) {
	/*if (vec.size() == 0) {
		std::cout << "���� �����Ȱ� ���� ! ";
		return false;
	}*/
	int count = 0;
	for (Account acc : vec) {
		count++;
		std::cout << "---------" << std::endl;
		std::cout << "identify_id : " << count << std::endl;
		std::cout << "real_id : " << acc.getid() << std::endl;
		std::cout << "name : " << acc.getname() << std::endl;
		std::cout << "balance : " << acc.getbalance() << std::endl;
	}
	return true;
}
int main() {
	std::random_device rdev;
	std::mt19937 mt(rdev());
	std::uniform_int_distribution<int> dist(0, 99);
	int hist[100] = { 0 };
	for (int i = 0; i < 100000; i++) {
		int r = dist(mt);
		hist[r]++;
	}
	for (int i = 0; i < 100; i++) {
		std::cout << i << ":" << hist[i] << std::endl;
	}
	char command;
	bool status = true;
	int id;
	float amount;
	std::vector<Account> vec;

	while (status) {
		printf("\n----\nM)ake new account \n R)emove old account \n");
		printf("D)eposit to account \n W)ithdraw from account \n");
		printf("S)how detail a Account\nQ)uit\n");
		std::cin >> command;
		switch (command) {
		case 'M':
		case 'm':
			add_account(vec);
			std::cout << "���� ���� �Ϸ�" << std::endl;
			break;

		case 'D':
		case 'd':
			if (display_all_account(vec)) {
				std::cout << "������ ������ �ĺ��ڸ� �Է� : ";
				std::cin >> id;
				std::cout << std::endl;
				std::cout << "������ �ݾ��� �Է� : ";
				std::cin >> amount;
				std::cout << std::endl;
				vec[(id - 1)].deposit(amount);
			}
			break;

		case 'R':
		case 'r':
			if (display_all_account(vec)) {
				std::cout << "������ ������ �ĺ��ڸ� �Է� : ";
				std::cin >> id;
				std::cout << std::endl;
				vec.erase(vec.begin() + id);
				std::cout << "�����Ϸ�" << std::endl;
			}

			break;

		case 'W':
		case 'w':
			if (display_all_account(vec)) {
				std::cout << "����� ������ �ĺ��ڸ� �Է� : ";
				std::cin >> id;
				std::cout << std::endl;
				std::cout << "����� �ݾ��� �Է� : ";
				std::cin >> amount;
				std::cout << std::endl;
				vec[(id - 1)].withdraw(amount);
			}
			break;

		case 'S':
		case 's':
			if (display_all_account(vec)) {
				std::cout << "�ڼ��� �� ������ �ĺ��ڸ� �Է� : ";
				std::cin >> id;
				std::cout << std::endl;
				vec[(id - 1)].display();
			}
			break;
		case 'q':
		case 'Q':
			status = true;
			break;
		}
	}
}