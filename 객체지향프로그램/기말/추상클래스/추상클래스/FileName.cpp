#include <iostream>

class Shape {
public:
	virtual double area() const = 0;
	virtual double span() = 0;
};
class Ellipse: public Shape {
	double a;
	double b;
public:
	Ellipse(double a, double b) : a(a), b(b) {};
	virtual double area() const override {
		std::cout << "일립스아리아";
		return 1;
	};
	virtual double span() override {
		std::cout << "일립스스팬";
		return 1;
	}
};
class Circle : public Ellipse {
public:
	Circle(double r) :Ellipse(r, r) {};
	double area() const override {
		std::cout << "써클아리아" << std::endl;
		return 1;
	}
	double span() override {
		std::cout << "써클스팬" << std::endl;
		return 23;
	}
};
int main() {
	//Shape a; 추상클래스라 생성안됌
	Shape* a = new Ellipse(1, 2);
	Ellipse e(32, 32);
	Circle c(454);
	a->area();
	a->span();
	e.area();
	e.span();
	c.area();
	c.span();
	Ellipse* e2 = new Circle(344);
	e2->area();
	e2->span();
}