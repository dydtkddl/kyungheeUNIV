#include <iostream>
class A {
	int x;
public:
	A(int x) : x(x) {}
	void printX() const {
		std::cout << x << std::endl;
	}
};
void Print(const A& a) {
	a.printX();
}
int main() {
	A a1(1);
	a1.printX();
	Print(a1);
}
//����Լ����� const�� �����ؾ߸�
//const�� ��ü�� ���� �Լ����� �� �޼��带 �̿��� �� �ִ�/