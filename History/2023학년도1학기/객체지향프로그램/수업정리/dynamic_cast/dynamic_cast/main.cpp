/*dynamic cast
static_cast�� �����Ͻð��� ������ ������ �����°�
dynamic cast�� ����ð��� �Ǵ��ؼ� �������ִ°�
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
	D* p2 = dynamic_cast<D*>(p1); // �̰�� D�� �� ���� ��������� �����Ƿ�
	// ĳ������ �Ұ����ؼ� nullptr�� �ٲ�
	if (p2) std::cout << "1: " << p2->d << '\n';

	D* p3 = new D;
	B* p4 = dynamic_cast<B*>(p3);
	if (p4) std::cout << "2: " << p4->b << '\n';

	B* p5 = new D; // �̰�쿡�� BŸ������ �޾����� ����� �������� DŸ������ ����Ǿ����Ƿ�
	// �̰�쿡�� D�� ĳ��Ʈ�� ������.
	D* p6 = dynamic_cast<D*>(p5);
	if (p6) std::cout << "3 : " << p6->d << std::endl;


}