#include <iostream>
class Point {
public:
	int x;
	Point() {
		x = 12;
	}
	Point(int x) :x(x) {};
};
class Account {
public:
	int x;
	Account() {};
};
int main() {
	Point P(12);
	Account A();
	std::cout << P.x;
}