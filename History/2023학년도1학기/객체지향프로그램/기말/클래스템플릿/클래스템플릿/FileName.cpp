#include <iostream>
#include <string>
#include <vector>
// �ٱ��� �Լ��� �����ϴµ�
// ��ħ Ŭ������ ���ø��� �̿��Ѵ�?
// void Point<int>::print(){}
// �̷������� �����ؾ���

// �׸��� T�� �� �� �ִ°���߿�
// ���������� �Ѱ�����츸 ���ְ������
// template<>�� �Ѵ����� ������ <�������Ҷ�> <int>�� ���� �������ָ�ȴ�.
template<typename T>
class Point {
public:
	T x; 
	T y;
	Point(T x, T y):x(x) , y(y) {};
	void print();
};
template<typename T>
void Point<T>::print() {
	std::cout << x << ',' << y << std::endl;
}
template<>
void Point<int>::print() {
	std::cout << x << "�ù�!" << y << std::endl;
}
int main() {
	Point<int> p1(1, 2);
	Point<double> p2(3.2, 2);
	Point<std::string> p3("d", "dsa");
	p1.print();
	p3.print();
	p2.print();
}