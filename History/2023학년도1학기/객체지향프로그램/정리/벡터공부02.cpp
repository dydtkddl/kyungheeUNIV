#include <iostream>
#include <vector>
//begin()? 
void get_begin_and_end(std::vector<int> v) {
	std::vector<int>::iterator iter = v.begin();
	for (iter; iter != v.end(); ++iter) {
		std::cout << *iter << " ";
	}
}

int main() {
	std::vector<int> a(10);
	std::vector<int> b = { 1,2,3,4 };
	std::vector<int> c;
	c.assign(12, 49);
	get_begin_and_end(c);
}