#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
void print(std::string a);
void print(int a);

int main() {
	/*string
	1. find
		1) ���ڿ� ã��
		2) n��° �ε������� ã��
	2. size
		������ ��ȯ�ޱ�
	3. at, []
		�ε��� �����ϱ�
		at�� �ƿ������� üũ
		[]�� üũ x
	4. resize
		���ڿ� ���̸� ����
		��ġ�� ����
		�׷����ʰ� �γ������� ��
	5. length
		���ڿ� ����
	6. empty
		���ڿ����� üũ
	7. += append
		�߰�
		*/
	std::string name = "�ȿ��";
	print(name);
	print(name.find("��"));
	print(name[2]);
	print(name.at(1));
	print(name.length());
	print(name.size());
	name.append("�Դϴ�");
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
		print("�ٽ��Է����ּ���");
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	};
	std::string line;
	std::cout << "1223" << std::endl;
	std::cin.ignore();

	getline(std::cin, line);
	print(line);
	std::ifstream fin;
	fin.open("�ȳ�.txt");

	std::ofstream fout;
	fout.open("�ȳ�.txt");

	//
};
void print(std::string a) {
	std::cout << a << std::endl;
}
void print(int a) {
	std::cout << a << std::endl;
}