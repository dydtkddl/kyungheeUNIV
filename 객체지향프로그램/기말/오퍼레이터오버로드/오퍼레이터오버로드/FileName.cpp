#include <iostream>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <string>
#include "account.h"
#include "Point.h"
#include <sstream>
//+
///�߿�
//���۷����� <<�� class���� ������ �� ����
//���۷����� << �� �ݵ�� class �ۿ� ���ǵǾ���Ѵ�.


Point operator+(const Point& p1, const Point& p2) {
	Point result;
	result.x = p1.x + p2.x;
	result.y = p1.y + p2.y;
	return result;
};
std::ostream& operator<< (std::ostream& os, const Point& p1) {
	os << "���¾ȿ��" << p1.x<< "���ȴ³�" << p1.y << std::endl;
	return os;
}
//std::ostream& operator<<(std::ostream& os, const Point& p1) {
//	os << '(' << p1.x << ',' << p1.y << ')' << std::endl;
//	return os;
//}
// << ���
int main() {
	std::string str;
	size_t size;
	std::ofstream ofs("�ȿ��.bin", std::ios::binary);
	std::ifstream ifs("�ȿ��.bin", std::ios::binary);
	if (ofs.good()) {
		std::cin >> str;
		size = str.size();
		ofs.write((const char*)&size, sizeof(size_t));
		ofs.write((const char*)&str[0], size);
		ofs.close();
	}
	if (ifs.good()) {
		size_t s;
		std::cout << "123";
		std::string new_str;
		ifs.read((char*)&s, sizeof(size_t));
		std::cout << s << std::endl;
		new_str.resize(s);
		ifs.read((char*)&new_str[0], s);
		std::cout << new_str << std::endl;
	}
	Point p1(1, 2);
	Point p2 = Point(123, 5513);
	Point p3 = p1 + p2;
	std::cout << p3;
	std::cout << p3 - p1;




}