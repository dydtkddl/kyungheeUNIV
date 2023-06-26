
#include <iostream>
class Base {
	int x;  // private data member x
public:
	Base(int x) : x(x) {};  // Base 클래스의 생성자
	virtual void print() const {  // 가상 함수 print() 정의
		std::cout << x << std::endl;  // x 출력
	}
	int get_x() const {  // x 값을 반환하는 멤버 함수
		return x;
	}
};
class Derived : public Base {
	int y;  // private data member y
public:
	Derived(int x, int y) : Base(x), y(y) {};  // Derived 클래스의 생성자, Base 클래스의 생성자 호출
	void print() const override {  // print() 함수를 오버라이드하여 재정의
		std::cout << get_x() << ", " << y << std::endl;  // x와 y 출력
	}
	Derived& operator=(const Derived& der) = default;  // 대입 연산자를 디폴트로 설정
	bool operator<(const Derived& der) {  // < 연산자 정의
		if ((this->get_x() + this->y) > (der.get_x() + der.y)) return 0;  // x + y가 der.x + der.y보다 크면 false 반환
		else return 1;  // 그렇지 않으면 true 반환
	}
};
int main() {
	Base* p1 = new Derived(10, 20);  // Base 포인터 p1은 Derived 객체를 가리킴
	Base* p2 = new Base(5);  // Base 포인터 p2는 Base 객체를 가리킴
	p1->print();  // Derived 클래스의 print() 함수 호출, 10, 20 출력
	p1->Base::print();  // Base 클래스의 print() 함수 호출, 10 출력
	p2->print();  // Base 클래스의 print() 함수 호출, 5 출력
	Derived* p3 = dynamic_cast<Derived*>(p1);  // p1을 Derived 포인터로 다운캐스팅
	if (p3 != nullptr) p3->print();  // p3가 nullptr이 아니라면 Derived 클래스의 print() 함수 호출, 10, 20 출력

	const Base b1 = *p2;  // b1은 p2의 복사본, const로 선언되어 값을 수정할 수 없음
	b1.print();  // Base 클래스의 print() 함수 호출, 5 출력

	Derived d1(1, 3), d2(2, 4);  // Derived 객체 d1과 d2 생성
	Derived d3 = (d1 < d2) ? d1 : d2;  // < 연산자를 이용하여 d1과 d2를 비교하여 작은 값을 d3에 할당
	d3.print();  // Derived 클래스의 print() 함수 호출, 1, 3 출력
}