#include <iostream>
class Ex {
public:
	int x;
	Ex(int x = 0) : x(x) {
		std::cout << "constructor. " << std::endl;
	};
	Ex(const Ex& e) : x(e.x) {
		std::cout << "copy_constructor." << std::endl;
	};
	void Set(int xx) {
		x = xx;
	};
	Ex operator+(int n) { return x + n; };
};
void Fn1(Ex e1) {
	e1.Set(1);
};
void Fn2(Ex&& e1) {
	e1.Set(2);
}
int main() {
	Ex e; // constructor ������
	Fn1(e); // copy constructor
	Fn2(e+1) ; // operator+�� return Ÿ���� Ex�����ϱ�
	// ExŸ���� ���ο� ��ü�� �����ǰ�
	// �װ��� x ���� e.x + n�� �Ѱ���
	// e + 1�� ���� 
//	constructor
	std::cout << e.x << std::endl;
}