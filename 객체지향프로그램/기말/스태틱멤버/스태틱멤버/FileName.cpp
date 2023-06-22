//디폴트로 클래스멤버는 인스턴스멤버로 생성된다.
//스태틱멤버로도 생성해보겠다.
//이는 같은 클래스로 정의된 모든 객체는 각각 다른 객체더라도
//그 변수를 공유한다.
//스태틱은 반드시 클래스 외부에서 생성해야한다.
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <random>
#include <cmath>
class Point {
public:
	static int how_many_point;
	int x;
	int y;
	Point(int x, int y) : x(x), y(y) {
		if (how_many_point==0) {
			how_many_point = 1;
			std::cout << "현재 포인트 객체 수 : " << how_many_point << std::endl;

		}
		else { how_many_point += 1;
		std::cout << "현재 포인트 객체 수 : " << how_many_point << std::endl;
		}
	};
	~Point() {
		 how_many_point -= 1;
		 std::cout << "현재 포인트 객체 수 : " << how_many_point << std::endl;
	};
	Point operator+(const Point& p1) {
		 Point*  result = new Point(this->x + p1.x, this->y + p1.y);
		return *result;
	}
};
int Point::how_many_point = 0;

std::ostream& operator<< (std::ostream& os, const Point& p1) {
	os << '(' << p1.x << ", " << p1.y << ')' << std::endl;
	return os;
}
int main() {
	Point x(10,12);
}