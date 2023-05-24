// Const 혹은 non-const로 선언된 객체와 
// const & non-const 멤버메서드
#include <iostream>
class A {
public:
	int x;
	A(int x = 10) :x(x) {};

	// printX를 const한경우와 아닌경우를 모두 오버로딩
	void printX() {
		std::cout << "non-const : " << x << std::endl;
	};
	void printX()const {
		std::cout << "const : " << x << std::endl;
	};
};
int main() {
	A a(12); // 생성자에 의해서 x= 12로 생성됌
	const A a_const; // default 생성자에 의해서 x = 10으로 생성됌
	a.printX(); // non-const객체이기 때문에, 두 오버로딩 함수 중에서 non-const함수가 끌고와짐
	a_const.printX(); // cosnt객체이기 때문에, 두 오버로딩 함수 중에서 const함수가 끌고와짐.
}
// non-const객체는 const함수와 non-const함수를 둘다 사용할 수 있지만, 둘 다있다면 non-const함수를 먼저 사용.
// const객체는 오직 const함수 메서드만 사용가능