#include <iostream>
// ī�� ����Ʈ����
// ��, ������ �Ǳ� �Ǵµ�
// ���� Ÿ���� Ŭ������ �ٸ� ��ü�� ���ڷ�
// �޾� �״�� �����ؿ��� ������ �Ҷ�.

// �׸��� �Ķ���ͷ� ���۷����� �ƴ�
// �׳� ���� �����ؼ� �����ö�
// �Լ��� ���� ������ ����� ����.
// �̶��� ī������Ʈ���� �߻�.
class Ex {
	int x;
public:
	Ex(int x = 0) : x(x) { std::cout << "qqq" << std::endl; }
	Ex(const Ex& e) : x(e.x) {
		std::cout << "123";
	}
	void print() const {
		std::cout << x << std::endl;
	}
};
Ex Copy(Ex e) {
	std::cout << "İ";
	e.print();
	std::cout << "İ";

	return e;
}
int main() {
	Ex e1(100); Ex e2(e1);
	e1.print(); e2.print();
	Copy(e1).print();
}