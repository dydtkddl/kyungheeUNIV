#include <iostream>
int g(int& n) {
	return 10 * n;
}
int g2(int&& n) {
	return 10 * n;
}
int g3(const int& n) {
	return 10 * n;
}
class Ex {
public:
	int x;
	Ex(int x) :x(x) { std::cout << "����Ʈ����" << std::endl; };
	Ex(const Ex& e) : x(e.x) { std::cout << "ī������Ʈ���� " << std::endl; };
	void Set(int xx) { x = xx; };
	Ex operator+(int n) { return { x + n }; };
};
int main() {
	//int &r = 3
	int x = 5;
	const int& y = 4;
	//std::cout << g(x + 2) << std::endl;
	std::cout << g2(x + 2) << std::endl;
	std::cout << g3(x + 3) << std::endl;
	// ī�ǰ� �ƴ϶� ��ü�� �ǳ׸鼭��, ���ٷ� ������ �ٲٸ鼭 �ǳ� �� �ְ�
	Ex e(12);
	Ex e2 = e + 2;
	Ex e3 = Ex(e2);
}