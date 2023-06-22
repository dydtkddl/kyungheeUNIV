#include <iostream>

class Ex {
	int x;
public:
	Ex(int x = 0) : x(x) {
		std::cout << "EX 생성" << std::endl;
	};
	~Ex() {
		std::cout << "EX 소멸" << std::endl;
	}
	Ex(const Ex& e) : x(e.x) { 
		std::cout << "카피컨스트럭터" << std::endl;
	}
	Ex& operator=(const Ex& e) {
		x = e.x;
		std::cout << "카피operator" << std::endl;
		return *this;
	}
};
int main() {
	Ex a(12); // 생성자
	Ex c(a);//카피컨스트럭터 직접초기화
	Ex b = c; // 카피컨스트럭터 직접초기화
	b = c; // operator 복사초기화
}