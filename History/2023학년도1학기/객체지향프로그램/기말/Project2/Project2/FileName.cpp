#include <iostream>
#include <string>
// Base의 타입으로 Derive 객체를 받을 때,
// 이제 이게 소멸이될때 Base의 타입 기준으로
// Base의 소멸자만 실행이 될 수 있다
// 이 또한 소멸자에 대해서 같은 함수로 보기때문인데,
// 이를 해결하기 위해서 소멸자에도 virtual가상함수 표시를 해줘야한다.
class Base {
public:
	Base(){
		std::cout << "Base 생성" << std::endl;
	}
	virtual ~Base() {
		std::cout << "Base 소멸" << std::endl;
	}
};
class Derive : public Base {
public:
	Derive() {
		std::cout << "Derive생성" << std::endl;
	}
	~Derive() {
		std::cout << "Derive 소멸" << std::endl;
	};
};
int main() {
	Base* b1 = new Derive;
	delete b1;
}