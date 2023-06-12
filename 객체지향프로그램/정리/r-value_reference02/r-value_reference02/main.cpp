#include <iostream>
class Ex {
public:
	int x;
	Ex(int x = 0) : x(x) {
		std::cout << "constructor. " << std::endl;
	};
	Ex(const Ex& e) : x(e.x) {
		std::cout << "copy_constructor." << std::endl;
	};
	void Set(int xx) {
		x = xx;
	};
	Ex operator+(int n) { return x + n; };
};
void Fn1(Ex e1) {
	e1.Set(1);
};
void Fn2(Ex&& e1) {
	e1.Set(2);
}
int main() {
	Ex e; // constructor 생성자
	Fn1(e); // copy constructor
	Fn2(e+1) ; // operator+가 return 타입이 Ex였으니까
	// Ex타입의 새로운 객체가 생성되고
	// 그것의 x 값은 e.x + n을 한값인
	// e + 1이 생성 
//	constructor
	std::cout << e.x << std::endl;
}