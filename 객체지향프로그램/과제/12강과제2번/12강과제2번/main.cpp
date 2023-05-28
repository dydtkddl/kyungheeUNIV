
#include <iostream>
class Base {
	int x;  // private data member x
public:
	Base(int x) : x(x) {};  // Base Ŭ������ ������
	virtual void print() const {  // ���� �Լ� print() ����
		std::cout << x << std::endl;  // x ���
	}
	int get_x() const {  // x ���� ��ȯ�ϴ� ��� �Լ�
		return x;
	}
};
class Derived : public Base {
	int y;  // private data member y
public:
	Derived(int x, int y) : Base(x), y(y) {};  // Derived Ŭ������ ������, Base Ŭ������ ������ ȣ��
	void print() const override {  // print() �Լ��� �������̵��Ͽ� ������
		std::cout << get_x() << ", " << y << std::endl;  // x�� y ���
	}
	Derived& operator=(const Derived& der) = default;  // ���� �����ڸ� ����Ʈ�� ����
	bool operator<(const Derived& der) {  // < ������ ����
		if ((this->get_x() + this->y) > (der.get_x() + der.y)) return 0;  // x + y�� der.x + der.y���� ũ�� false ��ȯ
		else return 1;  // �׷��� ������ true ��ȯ
	}
};
int main() {
	Base* p1 = new Derived(10, 20);  // Base ������ p1�� Derived ��ü�� ����Ŵ
	Base* p2 = new Base(5);  // Base ������ p2�� Base ��ü�� ����Ŵ
	p1->print();  // Derived Ŭ������ print() �Լ� ȣ��, 10, 20 ���
	p1->Base::print();  // Base Ŭ������ print() �Լ� ȣ��, 10 ���
	p2->print();  // Base Ŭ������ print() �Լ� ȣ��, 5 ���
	Derived* p3 = dynamic_cast<Derived*>(p1);  // p1�� Derived �����ͷ� �ٿ�ĳ����
	if (p3 != nullptr) p3->print();  // p3�� nullptr�� �ƴ϶�� Derived Ŭ������ print() �Լ� ȣ��, 10, 20 ���

	const Base b1 = *p2;  // b1�� p2�� ���纻, const�� ����Ǿ� ���� ������ �� ����
	b1.print();  // Base Ŭ������ print() �Լ� ȣ��, 5 ���

	Derived d1(1, 3), d2(2, 4);  // Derived ��ü d1�� d2 ����
	Derived d3 = (d1 < d2) ? d1 : d2;  // < �����ڸ� �̿��Ͽ� d1�� d2�� ���Ͽ� ���� ���� d3�� �Ҵ�
	d3.print();  // Derived Ŭ������ print() �Լ� ȣ��, 1, 3 ���
}