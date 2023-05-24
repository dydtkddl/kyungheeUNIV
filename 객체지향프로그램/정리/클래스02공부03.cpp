#include <iostream>
#include <string>
class Acount {
	
	
public:
	std::string name;
	int y;
	int z;
	Acount(std::string name, int y, int z) :name(name), y(y), z(z) {};
	};
int main() {
	Acount acct("Joe", 1023, 123);
	Acount* acct_ptr;
	acct_ptr = &acct;
	std::cout << acct_ptr << std::endl;

	acct_ptr = new Acount("Moe", 1233, 3412);
	std::cout << acct_ptr << std::endl;
	delete acct_ptr;
	std::cout << acct_ptr << std::endl;
	(*acct_ptr).y = 100;
	acct_ptr->y= 100;
	std::cout << (*acct_ptr).y;
}