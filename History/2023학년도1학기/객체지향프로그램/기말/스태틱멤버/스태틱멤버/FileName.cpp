//����Ʈ�� Ŭ��������� �ν��Ͻ������ �����ȴ�.
//����ƽ����ε� �����غ��ڴ�.
//�̴� ���� Ŭ������ ���ǵ� ��� ��ü�� ���� �ٸ� ��ü����
//�� ������ �����Ѵ�.
//����ƽ�� �ݵ�� Ŭ���� �ܺο��� �����ؾ��Ѵ�.
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
			std::cout << "���� ����Ʈ ��ü �� : " << how_many_point << std::endl;

		}
		else { how_many_point += 1;
		std::cout << "���� ����Ʈ ��ü �� : " << how_many_point << std::endl;
		}
	};
	~Point() {
		 how_many_point -= 1;
		 std::cout << "���� ����Ʈ ��ü �� : " << how_many_point << std::endl;
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