#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <random>
#include <stdio.h>
class Point {
public:
	int x;
	int y;
};
class Account {
public:
	std::string name;
	int id;
	float balance;
	Account(std::string n, int id, float b) :name(n), id(id), balance(b) {};
};
int main() {
	std::random_device rdev;
	std::mt19937 mt(rdev());
	std::uniform_int_distribution<int> dist(0, 99);
	int hist[100] = { 0 };
	int r = dist(mt);
	/*ù��°��� : ����ũ�⸦ ���� ���صΰ� ����Ʈ �����ڷ�
	������ ��ü���� �� ������ŭ ä���
	Ȥ�� ���ص� �����ŭ�� ��ü�����͸� �����ϱ� 
	�׸��� �����Ҵ����� �� �����ϱ�*/
	
	std::vector<Point> ptr(100);
	//�̰� ������ 
	//std::vector<Account> acc(100);
	std::string name;
	int id;
	float balance;
	std::vector<Account*> acc(100);
	for (int i = 0; i < 3; i++) {
		std::cin >> name >> id >> balance;
		acc[i] = new Account(name, id, balance);
	}
	for (int i = 0; i < acc.size(); i++) {
		delete acc[i];
	}

	/*�ι�°��� : ���͸� �� ���ͷ� �����ϰ� �ű⿡ 
	�ϳ��� Ǫ�����ϱ�*/
	std::vector<Account> acc2;
	for (int i = 0; i < 3; i++) {
		std::cin >> name >> id >> balance;
		acc2.push_back(Account(name, id, balance));
	}

}