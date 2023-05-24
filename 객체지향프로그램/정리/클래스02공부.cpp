#include <iostream>

class A {
public:
	int x;
	A(int x) :x(x) {};
	void printX() {
		std::cout << x << std::endl;
	}
	void constProntX() const {
		std::cout << x << std::endl;
	}
};
void Print1(A a) { // 인자로 전달된 변수가 copy가 됌
	a.printX();
};
void Print2(const A& a) { //인자로 전달된 변수가 별명을 가지고 실체를 끌고옴
	std::cout << a.x << std::endl;
	// a.printX(); -> 주석 풀면 컴파일 오류가 남.. 왜냐하면, 이함수에 인자로 전달받은
	// a를 const로 받았기 때문에, const함수로만 받을 수 있기 때문
	// 이함수는 인자로 const A를 받았으나
	// 그 a의 멤버 메소드중 const하지 않은 함수를 끌고 왔으므로, 에러가남
	a.constProntX(); // 이 경우는 가능
}
int main() {
	A a1(1);
	a1.printX();
	Print1(a1);
	Print2(a1);
}