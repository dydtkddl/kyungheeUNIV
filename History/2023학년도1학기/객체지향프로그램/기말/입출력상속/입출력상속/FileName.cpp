#include <iostream>
#include <fstream>
#include <string>
#include <vector>
// ostream 파라미터에
// std::cout 뿐만 아니라
// std::ofstream 의 객체도 넣을 수 있다.
void print(std::ostream&  os, int n){
	os << n << '\n';
}
int main() {
	print(std::cout, 36);
	std::ofstream ofs("123.txt");
	if (ofs.good()) {
		print(ofs, 3555);
		ofs.close();
	}
}