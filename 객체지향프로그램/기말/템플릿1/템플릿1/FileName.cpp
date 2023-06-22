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
	Ex(int x) :x(x) { std::cout << "컨스트럭터" << std::endl; };
	Ex(const Ex& e) : x(e.x) { std::cout << "카피컨스트럭터 " << std::endl; };
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
	// 카피가 아니라 실체를 건네면서도, 한줄로 내용을 바꾸면서 건넬 수 있게
	Ex e(12);
	Ex e2 = e + 2;
	Ex e3 = Ex(e2);
}