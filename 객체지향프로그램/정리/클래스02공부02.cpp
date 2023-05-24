#include <iostream>
class A {
	int x, y;
public:
	A(int x, int y) : x(x), y(y) {};
	void PrintX() {
		std::cout << "non_const : " << x << std::endl;
	};
	void PrintX() const {
		std::cout << "const : " << x << std::endl;
	};
	void PrintY() const{
		std::cout << y << std::endl;
	}
};
int main() {
	A a(130, 984);
	const A b(-132, 345);
	a.PrintX();
	a.PrintY();
	b.PrintX();
	b.PrintY();
}	
// 일반 정의된 A클래스 인스턴스는 const든 const아닌 메소드이든 둘다 사용할 수 있지만
// 두개 다 오버로딩 되어있다면 const메소드를 후순위에 둔다.

//const정의된 A클래스 인스턴스는 const메소드만 사용할 수 있으며, 오버로딩 되어있을떄
// const멤버함수를 찾아 사용한다.
//const멤버함수가 정의되어있지 않은데 사용하려고 하면 이는 컴파일 오류가 난다/