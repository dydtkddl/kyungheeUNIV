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
	// �� ���� ������ ���Ŭ������ ���� ������ ĳ���� �Ұ�
	//D& p2 = dynamic_cast<D&>(*p1);
	//std::cout << "1:" << p2.d << "\n"; // ���۷������� ���� ���ܹ߻�
	//D* pp = dynamic_cast<D*>(p1);
	//if(pp)std::cout << "1:" << pp->d << "\n";// �����Ͱ��� ��쿡��nullptr�� �ٲ�
	
	D* p3 = new D;
	B* p4 = dynamic_cast<B*>(p3);
	if (p4) std::cout << "2:" << p4->b << "\n";
	B* p5 = new D;
	D* p6 = dynamic_cast<D*>(p5);
	if (p6) std::cout << "3:" << p6->d << "\n";
}