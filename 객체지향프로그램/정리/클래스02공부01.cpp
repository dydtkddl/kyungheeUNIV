// Passing Object Paraeters
// 파라미터로 객체를 & reference variable로 받을 때.
#include <iostream>
// &와 const &로 두가지 방법으로 받을 수 있다.

// & 
// &로 받은 객체는 그 함수내의 로직으로 실제 그 객체까지 수정시킬 수 있다.

// & const
// const &object로 받은 객체는 그 실체를 들고오지만 const선언을 함으로써, 수정할 수 없게 만든다.
// 그리고 const 선언을 해서 받았기때문에, 그 object의 메서드를 쓸때, 그 메서드 이름을 가진
// const함수 메서드가 미리 정의 되어 있어야한다.
class A {
public:
	int x;
	A(int x) :x(x) {};
	void printX() {
		std::cout << "일반메서드 ";
		std::cout << x << std::endl;
	}
	void constprintX() const {
		std::cout << "const메서드 :";
		std::cout << x << std::endl;
	}
	void change() {
		std::cout << x << std::endl;
		x *= -1;
		std::cout << x << std::endl;
	}
};
void Print1(A a) { // copy값이 들어가므로 스코프 내에서만 수정 가능.
	a.printX();
	a.x = 0;
}
void Print2(const A &a) { // 읽기전용 수정 불가.
	std::cout << a.x << std::endl;
	a.constprintX();
}
void Change(A& a) {
	a.change(); // 체인지함수는 실제 reference 를 넘겨주니까, 실제 그 객체에 수정사항이
	//반영이 된다.

	//만약 & reference variable이 아닌, 일반 변수가 넘겨진다면, 그 함수의 스코프 내에서만
	// 수정사항이 유효하고 다시 밖으로 나오면 그 객체는 아무 변화도 없는 상태로 남아있을 것이다
	// 왜냐하면 복사본을 보냈기 때문에;
}
int main() {
	A a(123);
	a.printX();
	Print1(a);
	const A b(1234);
	b.constprintX();
	Print2(a);
	Change(a); 
}