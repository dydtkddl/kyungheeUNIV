#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;
using std::string;
int main() {
	//string objects (1)
	string name = "joe";
	std::cout << name << '\n';
	name = "jane";
	std::cout << name << std::endl;

	string name1 = "joe", name2;
	name2 = name1;
	std::cout << name1 << " " << name2 << '\n';

	//string objects(2)
		/* operator[], operator=, operator+=
		at, lengt, size
		find, substr, empty, clear */
			// 1. substr
				std::string str1 = "C++ Programming", str2;
				str2 = str1.substr(4); // 인덱스 4부터 끝까지 추출
				std::cout << str1 << std::endl << str2 << std::endl;
			// 2. find
				//문자열내에 존재하는 구간의 문자열을 찾는경우
				std::cout << str1.find("Pro") << ", " << str2.find("Pro") << std::endl;
				//찾으려는 것이 없으면
				std::cout << str1.find("dyd") << std::endl;
























}