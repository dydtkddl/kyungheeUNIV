//char 01
//char 변수는 1byte 정수이다.
#include <iostream>
#include <string>
void print(char* A) {
	std::cout << A << std::endl;
}
int main() {
	char char01[] = "c++을 공부하는 안용상";
	char char02[24] = "나는 c++을 공부한다.";
	const char* char03 = "123";
	print(char01);
	print(char02);
}