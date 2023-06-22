#include <iostream>
class A {
	int x;
public:
	A(int x) : x(x) {}
	void printX() const {
		std::cout << x << std::endl;
	}
};
void Print(const A& a) {
	a.printX();
}
int main() {
	A a1(1);
	a1.printX();
	Print(a1);
}
//멤버함수에서 const로 정의해야만
//const로 객체를 받은 함수에서 그 메서드를 이용할 수 있다/