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
	/*첫번째방법 : 벡터크기를 먼저 정해두고 디폴트 생성자로
	생성된 객체들을 그 갯수만큼 채우기
	혹은 정해둔 사이즈만큼의 객체포인터를 저장하기 
	그리고 동적할당으로 값 설정하기*/
	
	std::vector<Point> ptr(100);
	//이건 오류남 
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

	/*두번째방법 : 벡터를 빈 벡터로 생성하고 거기에 
	하나씩 푸쉬백하기*/
	std::vector<Account> acc2;
	for (int i = 0; i < 3; i++) {
		std::cin >> name >> id >> balance;
		acc2.push_back(Account(name, id, balance));
	}

}