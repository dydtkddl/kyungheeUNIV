#include <iostream>
// 카피 컨스트럭터
// 즉, 생성이 되긴 되는데
// 같은 타입의 클래스의 다른 객체를 인자로
// 받아 그대로 복사해오는 생성을 할때.

// 그리고 파라미터로 레퍼런스가 아닌
// 그냥 새로 복사해서 가져올때
// 함수에 들어가는 순간도 복사로 생성.
// 이때도 카피컨스트럭터 발생.
class Ex {
	int x;
public:
	Ex(int x = 0) : x(x) { std::cout << "qqq" << std::endl; }
	Ex(const Ex& e) : x(e.x) {
		std::cout << "123";
	}
	void print() const {
		std::cout << x << std::endl;
	}
};
Ex Copy(Ex e) {
	std::cout << "캅";
	e.print();
	std::cout << "캅";

	return e;
}
int main() {
	Ex e1(100); Ex e2(e1);
	e1.print(); e2.print();
	Copy(e1).print();
}