#include <iostream>
#include <cmath>

class Shape {
public:
	Shape() {};
	virtual ~Shape() {};
	static double PI; // ���� ��� ���� PI ����
	virtual void area() const = 0; // ������ ����ϰ� ����ϴ� ���� ���� �Լ�
};

///

class TwoDimensional : public Shape {
	double width;
	double height;
public:
	TwoDimensional(double x, double y) : width(x), height(y) {}; // �����ڷ� �ʺ�� ���� �ʱ�ȭ
	virtual ~TwoDimensional() {}
	virtual void area() const = 0; // ������ ����ϰ� ����ϴ� ���� ���� �Լ�
	virtual void round() const = 0; // �ѷ��� ����ϰ� ����ϴ� ���� ���� �Լ�
	double get_width() const { return width; }; // �ʺ� getter
	double get_height() const { return height; }; // ���� getter
};

class Triangle : public TwoDimensional {
	double cross_x;
public:
	Triangle(double x, double y, double cross_x) :
		TwoDimensional(x, y), cross_x(cross_x) {}; // �����ڷ� �ʺ�, ����, ������ x��ǥ �ʱ�ȭ
	virtual ~Triangle() {};
	void area() const override {
		std::cout << "this is Triangle \n this area is "
			<< get_width() * get_height() / 2 << std::endl << std::endl; // �ﰢ���� ���� ��� �� ���
	};
	double get_cross_x() const {
		return cross_x;
	}
	void round() const override {
		std::cout << "this is Triangle \n this round is " << get_width() + std::sqrt(std::pow(get_cross_x(), 2) + std::pow(get_height(), 2)) +
			std::sqrt(std::pow(get_width() - get_cross_x(), 2) + std::pow(get_height(), 2)) << std::endl << std::endl; // �ﰢ���� �ѷ� ��� �� ���
	};
};

class Rectangle : public TwoDimensional {
public:
	Rectangle(double x, double y) : TwoDimensional(x, y) {}; // �����ڷ� �ʺ�� ���� �ʱ�ȭ
	~Rectangle() {};
	void area() const override {
		std::cout << "this is Rectangle \n this area is "
			<< get_width() * get_height() << std::endl << std::endl; // ���簢���� ���� ��� �� ���
	};
	void round() const override {
		std::cout << "this is Rectangle \n this round is " << get_width() * 2 + get_height() * 2 << std::endl << std::endl; // ���簢���� �ѷ� ��� �� ���
	};
};

class Circle : public TwoDimensional {
public:
	Circle(double x) : TwoDimensional(x, x) {}; // �����ڷ� ������ �ʱ�ȭ
	~Circle() {};
	void area() const override {
		std::cout << "this is circle \n this area is "
			<< get_width() * get_width() * Shape::PI << std::endl << std::endl; // ���� ���� ��� �� ���
	};
	void round() const override {
		std::cout << "this is circle \n this round is " << PI * 2 * get_width() << std::endl << std::endl; // ���� �ѷ� ��� �� ���
	}
};

///

class ThreeDimensional : public Shape {
	double width;
	double height;
	double z_index;
public:
	ThreeDimensional(double w, double h, double z) : width(w), height(h), z_index(z) {}; // �����ڷ� �ʺ�, ����, z�� �� �ʱ�ȭ
	virtual ~ThreeDimensional() {};

	virtual void area() const = 0; // ������ ����ϰ� ����ϴ� ���� ���� �Լ�
	virtual void volume() const = 0; // ���Ǹ� ����ϰ� ����ϴ� ���� ���� �Լ�
	double get_width() const {
		return width;
	};
	double get_height() const {
		return height;
	}
	double get_zindex() const {
		return z_index;
	}
};

class Cube : public ThreeDimensional {
public:
	Cube(int x, int y, int z) : ThreeDimensional(x, y, z) {} // �����ڷ� �ʺ�, ����, z�� �� �ʱ�ȭ
	~Cube() {};
	void area() const override {
		std::cout
			<< "this is a cube\n this area is "
			<< get_width() * get_height() * 2 + get_width() * get_zindex() * 2 + get_height() * get_zindex() * 2
			<< std::endl
			<< std::endl; // ������ü�� ���� ��� �� ���
	};
	void volume() const override {
		std::cout
			<< "this is a cube\n this volume is "
			<< get_width() * get_height() * get_zindex()
			<< std::endl
			<< std::endl; // ������ü�� ���� ��� �� ���
	};
};

class Sphere : public ThreeDimensional {
public:
	Sphere(int x) : ThreeDimensional(x, x, x) {}; // �����ڷ� ������ �� �ʱ�ȭ
	~Sphere() {};

	void area() const override {
		std::cout
			<< "this is a sphere\n this area is "
			<< get_width() * get_width() * 4 * PI
			<< std::endl
			<< std::endl; // ���� ���� ��� �� ���
	};
	void volume() const override {
		std::cout
			<< "this is a sphere\n this volume is "
			<< std::pow(get_width(), 3) * 4 / 3 * PI
			<< std::endl
			<< std::endl; // ���� ���� ��� �� ���
	};
};

double Shape::PI = 3.14159; // ���� ��� ���� PI �ʱ�ȭ

int main() {
	Circle cir(4); // �������� 4�� �� ��ü cir�� ����
	cir.area();//cir ��ü�� ������ ����ϰ� ���
	cir.round(); //cir ��ü�� �ѷ��� ����ϰ� ���
	Triangle tri(3, 4, 1); // �غ��� ���̰� 3, ���̰� 4�� �ﰢ�� ��ü tri�� ����
	tri.area(); // tri ��ü�� ������ ����ϰ� ���
	tri.round(); // tri ��ü�� �ѷ��� ����ϰ� ���
	Rectangle rec(6, 4); //  �ʺ� 6�̰� ���̰� 4�� ���簢�� ��ü rec�� ����
	rec.area(); // rec ��ü�� ������ ����ϰ� ���
	rec.round(); // rec ��ü�� �ѷ��� ����ϰ� ���
	Cube cube(12, 3, 5); // �ʺ� 12, ���̰� 3, z�� ���� 5�� ������ü ��ü cube�� ����
	cube.area(); // cube ��ü�� ������ ����ϰ� ���
	cube.volume(); // cube ��ü�� ���Ǹ� ����ϰ� ���
	Sphere sph(6); // �������� 6�� �� ��ü sph�� ����
	sph.area(); // sph ��ü�� ������ ����ϰ� ���
	sph.volume(); // sph ��ü�� ���Ǹ� ����ϰ� ���
	return 0;// main �Լ��� ��ȯ���� 0���� �����Ͽ� ���α׷��� ����
}