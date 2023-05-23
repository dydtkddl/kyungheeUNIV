#include <iostream>
class Point {
	int x, y;
public:
	Point(int x, int y) : x(x), y(y) {
	};
	Point* set(int x,int y) {
		*this = { x , y };
		return this;
	}
	void print() const{
		std::cout << x << ',' << y << std::endl;
	};
	void inc() {
		x++;
		y++;
	}
};
int main() {
	Point p(1, 2); 
	std::cout << p.set(1, 2) << std::endl;
	std::cout << p.set(2, 3) << std::endl;
	p.set(5, 6)->print();
	p.inc();
	p.print();
}