
#include <iostream>

class A {
	int x;
public:
	A(int x) :x(x) {};
	A operator+(A& a) {
		A result = this->x + a.x;
		return result;
	}
	int getX() {
		return this->x;
	}
	int getX2() const {
		return this->x;
	}
};
int main() {
	A a1(1);
	A a2(2);
	A a3 = A(13);
	A sum = a1 + a2 + a3; 
	std::cout << sum.getX();
	const A a4 = A(14);
	std::cout << a3.getX2();
	//const타입으로 선언된 객체가 const함수가 아닌 멤버함수를 사용하면 오류가 나지만
	//const타입이 아니라 일반 객체로 선언된 객체는 const함수와 const함수가 아닌 멤버함수 둘다 접근할 수 있다.
}