#include <iostream>
#include <cmath>

class Shape {
public:
	Shape() {}; // Shape 클래스의 기본 생성자
	virtual ~Shape() {}; // Shape 클래스의 가상 소멸자
	static double PI; // 정적 멤버 변수 PI 선언
	virtual void area() const = 0; // 면적을 계산하고 출력하는 순수 가상 함수
};

class TwoDimensional : public Shape {
	double width; // 너비
	double height; // 높이
public:
	TwoDimensional(double x, double y) : width(x), height(y) {}; // 생성자로 너비와 높이 초기화
	virtual ~TwoDimensional() {} // TwoDimensional 클래스의 가상 소멸자
	virtual void area() const = 0; // 면적을 계산하고 출력하는 순수 가상 함수
	virtual void round() const = 0; // 둘레를 계산하고 출력하는 순수 가상 함수
	double get_width() const { return width; }; // 너비 getter
	double get_height() const { return height; }; // 높이 getter
};

class Triangle : public TwoDimensional {
	double cross_x; // 교차점 x 좌표
public:
	Triangle(double x, double y, double cross_x) : 
		TwoDimensional(x, y), cross_x(cross_x) {}; // 생성자로 너비, 높이, 교차점 x 좌표 초기화
	virtual ~Triangle() {}; // Triangle 클래스의 가상 소멸자
	void area() const override { //추상클래스였던 area를 Triangle클래스에서 override해서 정의
		std::cout << "this is Triangle \n this area is " 
			<< get_width() * get_height() / 2 
			<< std::endl 
			<< std::endl; // 삼각형의 면적 계산 및 출력
	};
	double get_cross_x() const {//삼각형의 둘레를 어떻게 얻을 수 있을까 고민하다가, 
		//높이 선과 밑변선이 서로 교차하는 지점을 이용하는 아이디어를 내봤습니다.
		return cross_x; // 교차점 x 좌표 getter
	}
	void round() const override {//추상클래스였던 round를 Triangle클래스에서 override해서 정의
		std::cout << "this is Triangle \n this round is "
			<< get_width() + std::sqrt(std::pow(get_cross_x(), 2) + std::pow(get_height(), 2))
			+ std::sqrt(std::pow(get_width() - get_cross_x(), 2) + std::pow(get_height(), 2)) 
			<< std::endl << std::endl; // 삼각형의 둘레 계산 및 출력
	};
};

class Rectangle : public TwoDimensional {
public:
	Rectangle(double x, double y) : TwoDimensional(x, y) {}; // 생성자로 너비와 높이 초기화
	~Rectangle() {}; // Rectangle 클래스의 소멸자
	void area() const override {//추상클래스였던 area를 Rectangle클래스에서 override해서 정의
		std::cout << "this is Rectangle \n this area is " 
			<< get_width() * get_height() 
			<< std::endl 
			<< std::endl; // 직사각형의 면적 계산 및 출력
	};
	void round() const override {//추상클래스였던 round를 Rectangle클래스에서 override해서 정의
		std::cout << "this is Rectangle \n this round is " 
			<< get_width() * 2 + get_height() * 2 
			<< std::endl 
			<< std::endl; // 직사각형의 둘레 계산 및 출력
	};
};

class Circle : public TwoDimensional {
public:
	Circle(double x) : TwoDimensional(x, x) {}; // 생성자로 반지름 초기화
	~Circle() {}; // Circle 클래스의 소멸자
	void area() const override {//추상클래스였던 area를 Circle클래스에서 override해서 정의
		std::cout << "this is circle \n this area is " 
			<< get_width() * get_width() * Shape::PI 
			<< std::endl 
			<< std::endl; // 원의 면적 계산 및 출력
	};
	void round() const override {//추상클래스였던 round를 Circle클래스에서 override해서 정의
		std::cout << "this is circle \n this round is " 
			<< PI * 2 * get_width() 
			<< std::endl 
			<< std::endl; // 원의 둘레 계산 및 출력
	}
};

class ThreeDimensional : public Shape {
	double width; // 너비
	double height; // 높이
	double z_index; // Z 축 값
public:
	ThreeDimensional(double w, double h, double z) : width(w), height(h), z_index(z) {}; 
	// 생성자로 너비, 높이, Z 축 값 초기화
	virtual ~ThreeDimensional() {}; // ThreeDimensional 클래스의 가상 소멸자
	virtual void area() const = 0; // 면적을 계산하고 출력하는 순수 가상 함수
	virtual void volume() const = 0; // 부피를 계산하고 출력하는 순수 가상 함수
	double get_width() const {
		return width; // 너비 getter
	};
	double get_height() const {
		return height; // 높이 getter
	}
	double get_zindex() const {
		return z_index; // Z 축 값 getter
	};
};

class Cube : public ThreeDimensional {
public:
	Cube(int x, int y, int z) : ThreeDimensional(x, y, z) {} // 생성자로 너비, 높이, Z 축 값 초기화
	~Cube() {}; // Cube 클래스의 소멸자
	void area() const override {
		std::cout
			<< "this is a cube\n this area is "
			<< get_width() * get_height() * 2 + get_width() * get_zindex() * 2 + get_height() * get_zindex() * 2
			<< std::endl
			<< std::endl; // 정육면체의 면적 계산 및 출력
	};
	void volume() const override {
		std::cout
			<< "this is a cube\n this volume is "
			<< get_width() * get_height() * get_zindex()
			<< std::endl
			<< std::endl; // 정육면체의 부피 계산 및 출력
	};
};

class Sphere : public ThreeDimensional {
public:
	Sphere(int x) : ThreeDimensional(x, x, x) {}; // 생성자로 반지름 값 초기화
	~Sphere() {}; // Sphere 클래스의 소멸자
	void area() const override {
		std::cout
			<< "this is a sphere\n this area is "
			<< get_width() * get_width() * 4 * PI
			<< std::endl
			<< std::endl; // 구의 면적 계산 및 출력
	};
	void volume() const override {
		std::cout
			<< "this is a sphere\n this volume is "
			<< std::pow(get_width(), 3) * 4 / 3 * PI
			<< std::endl
			<< std::endl; // 구의 부피 계산 및 출력
	};
};

double Shape::PI = 3.14159; // 정적 멤버 변수 PI 초기화

int main() {
	Circle cir(4); // 반지름이 4인 원 객체 cir를 생성
	cir.area(); // cir 객체의 면적을 계산하고 출력
	cir.round(); // cir 객체의 둘레를 계산하고 출력
	Triangle tri(3, 4, 1); // 밑변의 길이가 3, 높이가 4인 삼각형 객체 tri를 생성
	tri.area(); // tri 객체의 면적을 계산하고 출력
	tri.round(); // tri 객체의 둘레를 계산하고 출력

	Rectangle rec(6, 4); // 너비가 6이고 높이가 4인 직사각형 객체 rec를 생성
	rec.area(); // rec 객체의 면적을 계산하고 출력
	rec.round(); // rec 객체의 둘레를 계산하고 출력

	Cube cube(12, 3, 5); // 너비가 12, 높이가 3, Z 축 값이 5인 정육면체 객체 cube를 생성
	cube.area(); // cube 객체의 면적을 계산하고 출력
	cube.volume(); // cube 객체의 부피를 계산하고 출력

	Sphere sph(6); // 반지름이 6인 구 객체 sph를 생성
	sph.area(); // sph 객체의 면적을 계산하고 출력
	sph.volume(); // sph 객체의 부피를 계산하고 출력

	return 0; // main 함수의 반환값을 0으로 설정하여 프로그램을 종료
}