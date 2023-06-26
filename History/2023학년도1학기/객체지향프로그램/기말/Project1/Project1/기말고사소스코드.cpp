/*             Object-Oriented Programming, Midterm exam (2023-1, CSE103-00)                       */
// Write your answers in Korean or English(����� �ѱ��� �Ǵ� ����� �ۼ��Ͻÿ�).

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <functional>
#include <algorithm>
#include <exception>


// �а�:ȭ�а��а� �й�:2019101074, ����:�ȿ��        

/////////// ��� ����
class Vector1 {
	double x;
	double y;
public:
	Vector1(double x=0, double y=0):x(x), y(y) {};
	void Print() const {
		std::cout << x << ',' << y << std::endl;
	}
};
class Vector2 {

public:
	const Vector2(double x, double y) :x(x), y(y) {};
	double x;
	double y;
	double operator *(const Vector2& v2) const{ return (x * v2.x + y * v2.y); };
	};
std::ostream& operator<<(std::ostream& os, Vector2 v) {
	os << v.x << ", " << v.y;
	return os;
}
class B {
	int x;
public:
	B(int x) :x(x) {};
	virtual int Get() { return x; }
};
class D : public B {
	int y;
public:
	D(int x, int y) :B(x), y(y) {};
	int Get() override { return y; }
};
class X {
protected:
	int x;
public:
	X(int x) :x(x) {}
	virtual void Print() { std::cout << x << std::endl; };
};
class Y :public X {
	int y;
public:
	Y(int x, int y) :X(x), y(y) {};
	void Print() override { std::cout << x << ", " << y << std::endl; }
};
template <typename T>
class Data {
	T x;
public:
	Data(T x) :x(x) {}
	const Data& operator+(const Data& d2)const {
		return { x + d2.x };
	}
	T Get()const { return x; }
	bool IsEmpty(){
			
	}
};
class negative_value_Exception :public std::exception {
	std::string message;
public:
	negative_value_Exception() :
		message("negative value!") {};
	const char* what() {
		return message.c_str();;
	}
};


// 8(2). �Ʒ��� ���� �����ϴ� Integral �Լ��� �����϶�. - �Լ�, ���� �� ������ ����� �ּ�ȭ
	// (Define the function Integral that works as comments in the following codes. - Simplify the use of functions, variables and expressions)
//	auto Int = Integral([](double x) { return 3 * x * x + 2 * x - 1; }, 1E-7);
//	std::cout << Int(-1, 3) << std::endl;		// ���: 32
	// Int �Լ��� ù��° �Ķ���ͺ��� �ι�° �Ķ���ͱ��� f(x) = 3 * x * x + 2 * x - 1�� 1E-7 �������� �����ϴ� �Լ�(������ f(x) * 1E-7�� ��)
	// The Int is a function that integrates the f(x) = 3 * x * x + 2 * x - 1 from the first parameter to the second parameter at intervals of 1E-7 (the integral is the summation of f(x) * 1E-7)
	// [Hint]
	// double sum = 0;
	// for (double x = a; x <= b; x += delta)
	//	sum += f(x) * delta;
//template<typename T,class C>
//T Sum(C start ,C end, T first) {
//	C::iterator iter =
//	while (start != end) {
//		first+=*start
//	}
//	return first;
//};
//// 7(3). �Ʒ��� ���� �����ϴ� Sum �Լ� ���ø��� �����϶�.- ������ �Ķ���ʹ� ������ �ʱⰪ, �Լ�, ���� �� ������ ����� �ּ�ȭ
//	// (Define the function template (Sum) that works as comments in the following codes. - The last parameter is the initial value to accumulate, Simplify the use of functions, variables and expressions)
//std::vector<int> g{ 1, 2, 3, 4, 5 };
//std::list<double> h{ 1.2, 2.5, 3.2, 4.1, 5.4 };
//std::vector<std::string> i{ "C++", " ", "Programming" };
//
////	std::cout << Sum<std::vector<int>::iterator, int>(g.begin(), g.end(), 0) << std::endl;				// ���: 15
////	std::cout << Sum<std::list<double>::iterator, double>(h.begin(), h.end(), 0) << std::endl;			// ���: 16.4
////	std::cout << Sum<std::vector<std::string>::iterator, std::string>(i.begin(), i.end(), "") << std::endl;	// ���: C++ Programming
/////////// ��� ��


int main() {
	// ���� ���� �� ǥ�� �Լ� ��� ����(Do not use global variables and standard functions)

	std::cout << "\n### 1 ###" << std::endl;
	// 1(2). �Ʒ��� ���� �����ϴ� Vector1 Ŭ������ �����϶�. - �Լ�, ���� �� ������ ����� �ּ�ȭ
	// (Define the Vector1 class that works as comments in the following codes. - Simplify the use of functions, variables and expressions)
	Vector1 v1, v2(1.2, 3.5);
	const Vector1 v3(2.0, -4.1);
	v1.Print();		v2.Print();		v3.Print();			// ���: 0,0     1.2, 3.5     2,-4.1

	std::cout << "\n### 2 ###" << std::endl;
	// 2(2). �Ʒ��� ���� �����ϴ� Vector2 Ŭ������ << ������(����)�� �����϶�. - �Լ�, ���� �� ������ ����� �ּ�ȭ
	// (Define the Vector2 class and operator << (non-member) that work as comments in the following codes. - Simplify the use of functions, variables and expressions)
	const Vector2 w1(2, 3), w2(5.2, -1.1);
	std::cout << w1 << "     " << w2 << std::endl;		// ���: 2, 3     5.2, -1.1
	std::cout << w1 * w2 << std::endl;		// ���: 7.1		<- (2*5.2 + 3*-1.1), ��� �޼ҵ�� ����(Define it as a member method)

	std::cout << "\n### 3 ###" << std::endl;
	// 3(2). �Ʒ��� ���� �����ϴ� B�� D Ŭ������ �����϶�. - B�� D�� base class, �Լ�, ���� �� ������ ����� �ּ�ȭ
	// (Define the B and D classes that work as comments in the following codes. - B is the base class of D, Simplify the use of functions, variables and expressions)
	B b(1);
	D d(3, 4);	// D�� ��ӹ޴� ����� �����ϰ� �� ���� ������ ����� ����(D has only one data member, excluding inherited ones)
	std::cout << b.Get() << std::endl;							// ���: 1
	std::cout << d.B::Get() << ", " << d.Get() << std::endl;	// ���: 3, 4

	std::cout << "\n### 4 ###" << std::endl;
	// 4(2). �Ʒ��� ���� �����ϴ� X�� Y Ŭ������ �����϶�. - X�� Y�� base class, �Լ�, ���� �� ������ ����� �ּ�ȭ
	// (Define the X and Y classes that work as comments in the following codes. - X is the base class of Y, Simplify the use of functions, variables and expressions)
	X x1(2), x2(6);
	Y y1(3, 5), y2(7, 9);	// Y�� ��ӹ޴� ����� �����ϰ� �� ���� ������ ����� ����(Y has only one data member, excluding inherited ones)
	X* ptr = &x1;	ptr->Print();	// ���: 2
	ptr = &x2;		ptr->Print();	// ���: 6
	ptr = &y1;		ptr->Print();	// ���: 3, 5
	ptr = &y2;		ptr->Print();	// ���: 7, 9

	std::cout << "\n### 5 ###" << std::endl;
	// 5(4). �Ʒ��� ���� �����ϴ� Data Ŭ���� ���ø��� �����϶�. - �Լ�, ���� �� ������ ����� �ּ�ȭ
	// (Define the class template (Data) that works as comments in the following codes. - Simplify the use of functions, variables and expressions)
	const Data<int> d1(10), d2(0), d3(5);
	const Data<std::string> s1("C++ "), s2(""), s3("Programming");
	Data<int> d4 = d1 + d2 + d3;	// 10+0+5
	Data<std::string> s4 = s1 + s2 + s3;			// "C++ " + "" + "Programming"
	std::cout << d4.Get() << std::endl;				// ���: 15
	std::cout << s4.Get() << std::endl;				// ���: C++ Programming
//	std::cout << std::boolalpha;
//	std::cout << d1.IsEmpty() << ", " << d2.IsEmpty() << std::endl;		// ���: false, true		<- true: 0
//	std::cout << s1.IsEmpty() << ", " << s2.IsEmpty() << std::endl;		// ���: false, true		<- true: empty string

	std::cout << "\n### 6 ###" << std::endl;
	// 6(2). �Ʒ� �ڵ忡�� v�� ��ҿ��� [0, 9]������ ���� ������ ����ϵ��� [A] ��ġ�� ���� �Լ��� �����϶�. - �Լ�, ���� �� ������ ����� �ּ�ȭ
	// (Define a lambda function on [A] to print the number of elements of v in the range [0, 9] in the following codes. - Simplify the use of functions, variables and expressions)
	std::vector<int> v{ 10, 2, 13, 6, 14, 19, 1 };
	std::cout << std::count_if(v.begin(), v.end(), [](int x)->bool {return (x >= 0 && x < 10); }) << std::endl; // ���: 3

	std::cout << "\n### 7 ###" << std::endl;
	// 7(3). �Ʒ��� ���� �����ϴ� Sum �Լ� ���ø��� �����϶�.- ������ �Ķ���ʹ� ������ �ʱⰪ, �Լ�, ���� �� ������ ����� �ּ�ȭ
	// (Define the function template (Sum) that works as comments in the following codes. - The last parameter is the initial value to accumulate, Simplify the use of functions, variables and expressions)
	std::vector<int> g{ 1, 2, 3, 4, 5 };
	std::list<double> h{ 1.2, 2.5, 3.2, 4.1, 5.4 };
	std::vector<std::string> i{ "C++", " ", "Programming" };

	//std::cout << Sum<std::vector<int>::iterator, int>(g.begin(), g.end(), 0) << std::endl;				// ���: 15
	//std::cout << Sum<std::list<double>::iterator, double>(h.begin(), h.end(), 0) << std::endl;			// ���: 16.4
	//std::cout << Sum<std::vector<std::string>::iterator, std::string>(i.begin(), i.end(), "") << std::endl;	// ���: C++ Programming

	std::cout << "\n### 8 ###" << std::endl;
	// 8(2). �Ʒ��� ���� �����ϴ� Integral �Լ��� �����϶�. - �Լ�, ���� �� ������ ����� �ּ�ȭ
	// (Define the function Integral that works as comments in the following codes. - Simplify the use of functions, variables and expressions)
//	auto Int = Integral([](double x) { return 3 * x * x + 2 * x - 1; }, 1E-7);
//	std::cout << Int(-1, 3) << std::endl;		// ���: 32
	// Int �Լ��� ù��° �Ķ���ͺ��� �ι�° �Ķ���ͱ��� f(x) = 3 * x * x + 2 * x - 1�� 1E-7 �������� �����ϴ� �Լ�(������ f(x) * 1E-7�� ��)
	// The Int is a function that integrates the f(x) = 3 * x * x + 2 * x - 1 from the first parameter to the second parameter at intervals of 1E-7 (the integral is the summation of f(x) * 1E-7)
	// [Hint]
	// double sum = 0;
	// for (double x = a; x <= b; x += delta)
	//	sum += f(x) * delta;

	std::cout << "\n### 9 ###" << std::endl;
	// 9(1). �Ʒ��� ���� �����ϴ� Exception Ŭ������ �����϶�. - �Լ�, ���� �� ������ ����� �ּ�ȭ
	// (Define the Exception class that works as comments in the following codes. - Simplify the use of functions, variables and expressions)
	try {
		int x = 1;
		if (x < 0) {
			throw negative_value_Exception();//		throw Exception();
		}
		std::cout << x << std::endl;	// ���: 1

		x = -1;
		if (x < 0) {
			
			throw negative_value_Exception();//			throw Exception();			// exception throw
		}
		std::cout << x << std::endl;	// ��µ��� ����(This does not be printed)

		x = 2;
		if (x < 0) {
			throw negative_value_Exception();//			throw Exception();
		}
		std::cout << x << std::endl;	// ��µ��� ����(This does not be printed)
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;		// ���: Negative number
	}
}