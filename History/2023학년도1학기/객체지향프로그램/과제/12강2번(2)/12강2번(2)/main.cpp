// All data members of Base and Derived classes must be declared 
// as private access types
#include <iostream>
class Base {
	int x;
public:
	Base(int x):x(x) { };
	virtual ~Base() {};
	virtual void print() const{
		std::cout << x << std::endl;
		};
	int get_x() const {
		return x;
	}
}; 
class Derived : public Base{
	int y;
public:
	Derived(int x, int y) :Base(x), y(y) {};
	void print() const override {
		std::cout << get_x() << ',' << y << std::endl;
	}
	bool operator<(const Derived& de) {
		if ((get_x() + y) > (de.get_x(), de.y)) {
			return false;
		}
		else {
			return true;
		}
	}
};
int main() {
	Base* p1 = new Derived(10, 20);		// (x, y)
	Base* p2 = new Base(5);			// (x) 
	p1->print();			// prints 10, 20
	p1->Base::print();		// prints 10
	p2->print(); 			// prints 5
	Derived* p3 = dynamic_cast<Derived*>(p1);
	if (p3 != nullptr) p3->print();			// prints 10, 20

	const Base b1 = *p2;
	b1.print();				// prints 5

	Derived d1(1, 3), d2(2, 4);
	Derived d3 = (d1 < d2) ? d1 : d2;	// operator <: (d1.x+d1.y) < (d2.x+d2.y)
	d3.print();				// prints 1, 3
}