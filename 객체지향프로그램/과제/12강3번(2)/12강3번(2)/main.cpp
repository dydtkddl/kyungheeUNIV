#include <iostream>
#include <vector>
class Base {
	int size;
	std::vector<int> vec;
public:
	Base(int x ): size(x) { 
		for (int i = 0; i < size; i++) {
			vec.push_back(0);
		}
	};
	virtual void print() const {
		std::cout << size << std::endl;
	};
	void setN(int index, int result) {
		if (index < size) {
			vec[index] = result;
		}
	}
	virtual void printData() const {
		for (int i = 0; i < vec.size(); i++) {
			std::cout << vec[i] << ", ";
		}
		std::cout << std::endl;
	}
	std::vector<int>& get_vec() {
		return vec;
	}
};
class Derived : public Base {
public:
	Derived(int x):Base(x) {};
	void insert(int x) {
		get_vec().push_back(x);
	};
};

int main() {
	Base b1(2), b2(10);

	b1.print();		// 2
	b2.print();		// 10
	for (int i = 0; i < 5; i++) {
		b1.setN(i, (i + 1) * 20);
		b2.setN(i, (i + 1) * 10);
	}
	b1.printData();  // 20 40
	b2.printData();  // 10 20 30 40 50 0 0 0 0 0

	Derived d(5);
	d.print();		// 5
	d.printData();		// 0 0 0 0 0
	for (int i = 0; i < 10; i++) {
		d.setN(i, (i + 1) * 3);
	}
	d.printData();	// 3 6 9 12 15
	d.insert(99);	// "Base" class does not have "insert" method.
	d.printData();	// 3 6 9 12 15 99
}