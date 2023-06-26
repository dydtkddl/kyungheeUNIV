#include <iostream>
#include <fstream>
#include <string>
#include <vector>
void print(std::string a) {
	std::cout << a << std::endl;
}
void print(int a) {
	std::cout << a << std::endl;
}
void print(const std::vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << ", ";
	}
}
int main() {
	std::ofstream fout("안용상.txt");
	if (fout.fail()) {
		std::cerr << "오류";
		exit(100);
	}
	fout << "안녕나는 안용상임. !\nㅋㅋ구";
	fout.close();
	std::ifstream fin("안용상.txt");
	char c;
	while (fin.get(c)) {
		std::cout << c;
	}
	//
	std::vector<int> vec;
	for (int i = 0; i < 10; i++) {
		vec.push_back(i);
	}
	print(vec);
	std::ofstream vecout("벡터아웃.txt");
	if (vecout.good()) {
		for (int i = 0; i < vec.size(); i++) {
			vecout << vec[i] << " ";
		};
		vecout.close();
	}
		std::ifstream vecin("벡터아웃.txt");
		std::vector<int> newvec;
		if (vecin.fail()) {
			std::cerr << "에러";
			exit(100);
		}
		int v;
		while (vecin>>v) {
			newvec.push_back(v);
		};
		vecin.close();
		print(newvec);
	}

