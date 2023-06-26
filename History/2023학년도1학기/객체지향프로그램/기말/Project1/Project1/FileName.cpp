#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
void print(std::string a);
void print(int a);

int main() {
	/*string
	1. find
		1) 문자열 찾기
		2) n번째 인덱스부터 찾기
	2. size
		사이즈 반환받기
	3. at, []
		인덱스 추출하기
		at은 아웃레인지 체크
		[]는 체크 x
	4. resize
		문자열 길이를 수정
		넘치면 삭제
		그렇지않고 널널해지면 빈값
	5. length
		문자열 길이
	6. empty
		빈문자열인지 체크
	7. += append
		추가
		*/
	std::string name = "안용상";
	print(name);
	print(name.find("용"));
	print(name[2]);
	print(name.at(1));
	print(name.length());
	print(name.size());
	name.append("입니다");
	print(name);
	std::string sub = name.substr(4);
	sub += name;
	sub.operator+=(name);
	print(sub);
	int a;
	//
	std::cin >> a;
	print(a);
	while (!(std::cin >> a)) {
		print("다시입력해주세요");
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	};
	std::string line;
	std::cout << "1223" << std::endl;
	std::cin.ignore();

	getline(std::cin, line);
	print(line);
	std::ifstream fin;
	fin.open("안녕.txt");

	std::ofstream fout;
	fout.open("안녕.txt");

	//
};
void print(std::string a) {
	std::cout << a << std::endl;
}
void print(int a) {
	std::cout << a << std::endl;
}