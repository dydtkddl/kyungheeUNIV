#include <iostream>
#include <string>
#include <vector>
// 바깥에 함수를 정의하는데
// 마침 클래스가 템플릿을 이용한다?
// void Point<int>::print(){}
// 이런식으로 정의해야함

// 그리고 T에 들어갈 수 있는경우중에
// 예외적으로 한가지경우만 빼주고싶으면
// template<>를 한다음에 실제로 <지정을할때> <int>와 같이 지정해주면된다.
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
	std::cout << x << "시발!" << y << std::endl;
}
int main() {
	Point<int> p1(1, 2);
	Point<double> p2(3.2, 2);
	Point<std::string> p3("d", "dsa");
	p1.print();
	p3.print();
	p2.print();
}