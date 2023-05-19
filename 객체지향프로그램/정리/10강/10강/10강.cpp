#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
using namespace std;
using std::string;
void save_vector(const std::string& filename, const std::vector<int>& vec) {
	std::ofstream out(filename);
	if (out.good()) {
		int n = vec.size();
		for (int i = 0; i < n; i++) {
			out << vec[i] << " ";
		}
		out << '\n';
		out.close();
	}
	else
		std::cout << "Unable to load in the file\n";
};
void load_vector(const std::string& filename, std::vector<int>& vec) {
	std::ifstream in(filename);
	if (in.good()) {
		vec.clear();
		int value;
		while (in >> value)// eof가 되면 false가 됌
			vec.push_back(value);
		in.close();
	}
	else
		std::cout << "Unable to load in the file\n";
};
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
				std::cout << str1.find("dyd") << std::endl;//이상한 값이 나온다
			// 3. operator
				std::string word;
				word = "good";
				std::cout << word << std::endl;
				word.operator = ("good!!");
				std::cout << word << std::endl;
				word += " job!";
				std::cout << word << std::endl;
				word.operator+= ("god");
				std::cout << word << std::endl;

	// input output streams
				int x;
				std::cin >> x;
				std::cout << x;
				cin.operator>>(x);
				cout.operator<<(x);
				cout.operator<<(x).operator<<('\n');
		//기본적으로 cin으로 입력받을떄는 white space를 입력의 구분으로 본다.
				std::string line;
				std::cin >> line;
				std::cout << line << std::cout.end;;
			//공백까지 포함해서 받으려면 getline
				getline(std::cin, line);
				std::cout << line;
		//#include <fstream>
				//쓰기 ofstream
				std::string filename = "C:/파일이름";
				std::ofstream out(filename);
				//읽어오기 ifstream
				std::ifstream in(filename);
				


				string word[256];
				std::cout << "워드입력 ";






















}