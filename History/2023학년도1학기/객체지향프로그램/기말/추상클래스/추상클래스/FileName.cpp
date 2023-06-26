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
		std::cout << "�ϸ����Ƹ���";
		return 1;
	};
	virtual double span() override {
		std::cout << "�ϸ�������";
		return 1;
	}
};
class Circle : public Ellipse {
public:
	Circle(double r) :Ellipse(r, r) {};
	double area() const override {
		std::cout << "��Ŭ�Ƹ���" << std::endl;
		return 1;
	}
	double span() override {
		std::cout << "��Ŭ����" << std::endl;
		return 23;
	}
};
int main() {
	//Shape a; �߻�Ŭ������ �����ȉ�
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