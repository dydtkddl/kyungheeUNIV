#include <iostream>

class Ex {
	int x;
public:
	Ex(int x = 0) : x(x) {
		std::cout << "EX ����" << std::endl;
	};
	~Ex() {
		std::cout << "EX �Ҹ�" << std::endl;
	}
	Ex(const Ex& e) : x(e.x) { 
		std::cout << "ī������Ʈ����" << std::endl;
	}
	Ex& operator=(const Ex& e) {
		x = e.x;
		std::cout << "ī��operator" << std::endl;
		return *this;
	}
};
int main() {
	Ex a(12); // ������
	Ex c(a);//ī������Ʈ���� �����ʱ�ȭ
	Ex b = c; // ī������Ʈ���� �����ʱ�ȭ
	b = c; // operator �����ʱ�ȭ
}