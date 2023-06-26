#include <iostream>
#include <vector>
#include <string>
class Account {
public:
	std::string name;
	int id;
	int money;
	Account(std::string name, int id, int money) :name(name), id(id), money(money) {}
};
class Point {
public:
	int x;
	int y;
	Point(int x = 10, int y = -10) :x(x), y(y) {}
};

void printVector_Account(std::vector<Account *> accv) {
	for (Account* a : accv) {
		std::cout << a->name << a->id << ',' << a->money << ',' << std::endl;
	}
}
int main() {
	std::vector<Point> pointvector(100);
	// std::vector<Account> accountvector(100); 이는 불가능함
	// 그 이유는 벡터에 Account 인스턴스를 100개를 생성하는데,
	//생성에 대한 정보를 전달하지 않았으므로, default생성자가 쓰여야함
	//하지만 이 Account 클래스에는 생성자는 명시되어있지만 default생성자는
	//정의되어있지 않아서, 인스턴스가 생성자에 의해 생성될수 없음
	//따라서 다른 방법을 사용해야함..

	std::vector<Account*> AccountPtrVector(2);
	for (Account* a : AccountPtrVector) {
		std::string name;
		int id;
		int money;
		std::cin >> name >> id >> money;
		a = new Account(name, id, money);
		std::cout << 1 << std::endl;
	};
	printVector_Account(AccountPtrVector);
}