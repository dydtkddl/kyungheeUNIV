#include <iostream>
class Ex {
	int x;
public:
	Ex(int x = 0) : x(x) {};
	Ex(const Ex& e) : x(e.x) {};
	Ex& operator=(Ex& e) {
		x = e.x;
		return *this;
	}
	void print() const {
		std::cout << x << std::endl;
	}
	// className(const className &) = default;
	// className(const className &) = delete; 기본 카피컨스트럭터 안쓰고싶을때
};
Ex Copy(Ex e) {
	e.print();
	return e;
}
int main() {
	Ex e1(100);
	Ex e2(e1);
	e1.print();
	e2.print();
	Copy(e1).print();
	Ex e3 = e2;
	e3.print();
}