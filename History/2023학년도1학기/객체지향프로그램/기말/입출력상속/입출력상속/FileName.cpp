#include <iostream>
#include <fstream>
#include <string>
#include <vector>
// ostream �Ķ���Ϳ�
// std::cout �Ӹ� �ƴ϶�
// std::ofstream �� ��ü�� ���� �� �ִ�.
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