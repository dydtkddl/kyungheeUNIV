#include <iostream>
class B {
public:
	int b;
	B() : b(10) {}
	virtual ~B() {}
};
class D : public B {
public:
	int d;
	D() : d(20) {}
	~D() override {}
};
int main() {
	B* p1 = new B;
	// 더 넓은 범위의 기반클래스를 좁은 범위로 캐스팅 불가
	//D& p2 = dynamic_cast<D&>(*p1);
	//std::cout << "1:" << p2.d << "\n"; // 레퍼런스같은 경우는 예외발생
	//D* pp = dynamic_cast<D*>(p1);
	//if(pp)std::cout << "1:" << pp->d << "\n";// 포인터같은 경우에는nullptr로 바뀜
	
	D* p3 = new D;
	B* p4 = dynamic_cast<B*>(p3);
	if (p4) std::cout << "2:" << p4->b << "\n";
	B* p5 = new D;
	D* p6 = dynamic_cast<D*>(p5);
	if (p6) std::cout << "3:" << p6->d << "\n";
}