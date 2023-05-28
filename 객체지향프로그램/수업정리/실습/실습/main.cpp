/* abstract class 
�߻��� 
�⺻�� Ʋ�� �����
���� �ν��Ͻ�ȭ �� �� ���� Ŭ����
pure virtual function (method)�� �ϳ��� �����ϸ� �߻�Ŭ����
public:
	virtual double span() const = 0; �̷������� �������� �ʾҴٴ� ����
	= 0 �� ����*/
#include <iostream>
class Shape {
public:
	virtual double span() const = 0;
	virtual double area() const = 0;
};
//Shape myShape; �Ұ��� �߻�Ŭ��������

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