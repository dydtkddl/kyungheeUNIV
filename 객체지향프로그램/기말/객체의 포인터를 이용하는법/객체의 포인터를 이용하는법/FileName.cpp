#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
class Point {
public:
	int x;
	int y;
};
class Point2 {
public:
	int x;
	int y;
	Point2(int x, int y) :x(x), y(y) {}
};
int main() {
	std::vector<Point> pt(100);
	std::vector<Point2>pt2(102); //���� ����Ʈ����Ʈ���� ������ �̷��� �Ұ�
}