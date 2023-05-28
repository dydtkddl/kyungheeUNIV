/* abstract class 
추상적 
기본적 틀만 만들고
실제 인스턴스화 할 수 없는 클래스
pure virtual function (method)를 하나라도 포함하면 추상클래스
public:
	virtual double span() const = 0; 이런식으로 정의하지 않았다는 것을
	= 0 로 설정*/
#include <iostream>
class Shape {
public:
	virtual double span() const = 0;
	virtual double area() const = 0;
};
//Shape myShape; 불가능 추상클래스여서

class Ellipse : public Shape {
protected:
	double major_radius;
	double minor_radius;
public:
	Ellipse(double major, double minor);
	double span() const override;
	double area() const override;
};
class Circle : public Ellipse {
public:
	Circle(double radius) : Ellipse(radius, radius) {};
};