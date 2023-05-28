/*dynamic cast
static_cast는 컴파일시간에 완전히 결정해 버리는것
dynamic cast는 실행시간에 판단해서 결정해주는것
dynamic_cast<type>(expression)
pointer or reference type conversion (up , down , sideways) 
fail : pointer-nullptr , reference-exception*/

#include <iostream>
class B {
public:
	int b;
	B() : b(10) {};
	virtual ~B() {};
};
class D : public B {
public:
	int d;
	D() : d(20) { };
	~D() override {};
};
int main() {
	B* p1 = new B;
	D* p2 = dynamic_cast<D*>(p1); // 이경우 D가 더 많은 멤버정보를 가지므로
	// 캐스팅이 불가능해서 nullptr로 바뀜
	if (p2) std::cout << "1: " << p2->d << '\n';

	D* p3 = new D;
	B* p4 = dynamic_cast<B*>(p3);
	if (p4) std::cout << "2: " << p4->b << '\n';

	B* p5 = new D; // 이경우에는 B타입으로 받았으나 사실은 동적으로 D타입으로 선언되었으므로
	// 이경우에는 D로 캐스트가 가능함.
	D* p6 = dynamic_cast<D*>(p5);
	if (p6) std::cout << "3 : " << p6->d << std::endl;


}