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
	std::ofstream fout("�ȿ��.txt");
	if (fout.fail()) {
		std::cerr << "����";
		exit(100);
	}
	fout << "�ȳ糪�� �ȿ����. !\n������";
	fout.close();
	std::ifstream fin("�ȿ��.txt");
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
	std::ofstream vecout("���;ƿ�.txt");
	if (vecout.good()) {
		for (int i = 0; i < vec.size(); i++) {
			vecout << vec[i] << " ";
		};
		vecout.close();
	}
		std::ifstream vecin("���;ƿ�.txt");
		std::vector<int> newvec;
		if (vecin.fail()) {
			std::cerr << "����";
			exit(100);
		}
		int v;
		while (vecin>>v) {
			newvec.push_back(v);
		};
		vecin.close();
		print(newvec);
	}

