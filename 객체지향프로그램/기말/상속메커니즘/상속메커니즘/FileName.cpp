#include <iostream>
#include <fstream>
#include <string>
#include <vector>
// 가상함수를 쓰는 이유
// 가상함수를 쓰지않을때 이상없는경우
	// 이제 상속클래스를 그 상속클래스 타입으로 받을때는
	// 가상함수를 쓰지않아도, 상속클래스 타입을 기준으로 
	// 똑같은 이름의 함수를 재정의 하기에
	// 상속클래스의 함수를 사용하게 된다
// 가상함수를 쓰지않았을때 이상이 생기는 경우
	// 그러나, 객체보다 더 높은 부모클래스의 타입으로 받게될때
	// 그 높은 부모클래스의 타입을 기준으로 함수를 정의하기에
	// 자식클래스인 객체 본인의 재정의하고싶은 함수가 무시되고
	// 부모클래스의 함수로 사용되게 된다.
// 그러면 그냥 상속받는 자식클래스를 생성할거면
// 자식클래스 타입으로만 자식클래스를 만들면 되지않겠느냐?
// 할 수 있겠지만,
// 넓은 범위의 부모클래스를 파라미터 인자의 타입으로 설정해두고
// 그 자식들이 범용적으로 그 파라미터를 사용하는 함수의 인자로
// 들어갈 수 있게 열어두는 코딩을 하려면, 자식클래스타입으로만
// 해당 객체를 선언할 수 없다.
// 객체 본인의 타입보다 더 폭넓은 부모클래스의 타입으로 생성이
// 되는 상황이 분명히 필요하다
// 
// 물론 그렇게 할 필요가 정말 없다면, 그냥 함수를 재정의하는
// 방식만 사용하고 가상함수를 쓰지않을 수 도 있다
//
// 하지만 그렇지 않으면서, 클래스의 다형성을 이용하고싶을때는
// 그 유용함을 위해서, 가상함수에 대한 명시를 꼭 해줘야한다.
// >> 가상 함수를 사용하는 이유에 대한 설명이 정확하고 타당합니다
class Main{
	int x;
	int y;
public:
	void set(int x2,int y2) {
		x = x2;
		y = y2;
	}
	virtual void print() {
		std::cout << x << ", " << y << std::endl;
	}
};
class I1 : public Main{
public:
	void print() override {
		std::cout << "ㅇㄷㅂㅈㅂㅇ";
	}
};
class I2 :public Main {
};

int main() {
	Main a;
	I1 b;
	Main& l12 = b;
	l12.print();
	a.set(123, 43);
	b.set(12355, 66422);
	a.print();
}