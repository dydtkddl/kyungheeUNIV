#include <iostream>
#include <cmath>
class Shape {
public:
	static double PI;
	virtual void print_area() const = 0;
};
double Shape::PI = 3.14159;
class TwoDimensional : public Shape {
public:
	virtual void print_area() const = 0;
	virtual void print_round() const = 0;
};
class Triangle : public TwoDimensional {
public:
	double width;
	double height;
	double cross;
	Triangle(double width, double height, double cross):width(width), height(height), cross(cross) {};
	void print_area() const override {
		std::cout << "삼각형 넓이 : " << width * height * 0.5 << std::endl;
	}
	void print_round() const override {
		double _cross = width - cross;
		double result = width
			+ std::sqrt(std::pow(cross, 2) + std::pow(height, 2))
			+ std::sqrt(std::pow(_cross, 2) + std::pow(height, 2));
		std::cout << "삼각형 둘레 : " << result << std::endl;
	}
};
class Rectangle : public TwoDimensional {
public:
	double w;
	double h;
	Rectangle(double w, double h) : w(w), h(h) {};
	void print_area() const override {
		std::cout << "사각형넓이 : " <<w*h << std::endl;
	};
	void print_round() const override {
		std::cout << "사각형둘레 : " << 2 * (w + h) << std::endl;
	};
};
class Circle : public TwoDimensional {
public:
	double r;
	Circle(double r) :r(r) {};
	void print_area() const override {
		std::cout << "원넓이 : " << std::pow(r, 2) * PI << std::endl;
	}
	void print_round() const override {
		std::cout << "원둘레 : " << 2*PI*r << std::endl;
	}
};

class ThreeDimensional : public Shape {
public:
	virtual void print_area() const = 0;
	virtual void print_volume() const = 0;
};
class Cube : public ThreeDimensional {
public:
	double x; double y; double z;
	Cube(double x, double y, double z) :x(x), y(y), z(z) {};
	void print_area() const override {
		std::cout << "큐브겉면적 : " << 2 * (x * y + x * z + y * z) << std::endl;
	}
	void print_volume() const override {
		std::cout << "큐브부피 : " << x * y * z << std::endl;
	}
};
class Sphere : public ThreeDimensional {
public:
	double r;
	Sphere(double r):r(r) { };
	void print_area() const override {
		std::cout << "구의 겉넓이 : " << 4 * PI * r * r << std::endl;
	}
	void print_volume() const override {
		std::cout << "구의 부피 : " << (double)3/4 * PI * std::pow(r,3) << std::endl;
	}
};


int main() {
	Triangle tri(13, 4, 4);
	Rectangle rec(10, 32);
	Circle cir(32);

	Cube cube(32, 33, 12);
	Sphere sph(22);

	tri.print_area();
	tri.print_round();

	rec.print_area();
	rec.print_round();

	cir.print_area();
	cir.print_round();

	cube.print_area();
	cube.print_volume();

	sph.print_area();
	sph.print_volume();

	return 0;
}