#include <iostream>
#include <string>
// Base�� Ÿ������ Derive ��ü�� ���� ��,
// ���� �̰� �Ҹ��̵ɶ� Base�� Ÿ�� ��������
// Base�� �Ҹ��ڸ� ������ �� �� �ִ�
// �� ���� �Ҹ��ڿ� ���ؼ� ���� �Լ��� ���⶧���ε�,
// �̸� �ذ��ϱ� ���ؼ� �Ҹ��ڿ��� virtual�����Լ� ǥ�ø� ������Ѵ�.
class Base {
public:
	Base(){
		std::cout << "Base ����" << std::endl;
	}
	virtual ~Base() {
		std::cout << "Base �Ҹ�" << std::endl;
	}
};
class Derive : public Base {
public:
	Derive() {
		std::cout << "Derive����" << std::endl;
	}
	~Derive() {
		std::cout << "Derive �Ҹ�" << std::endl;
	};
};
int main() {
	Base* b1 = new Derive;
	delete b1;
}