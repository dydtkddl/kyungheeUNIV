#include <iostream>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
template<typename T>
void print(T a) {
	std::cout << a << std::endl;
}
template<typename T>
void print(std::vector<T> a) {
	for (int i = 0; i < a.size(); i++) {
		std::cout << a[i] << ", ";
	}
	std::cout << std::endl;
}
int main() {
	std::ifstream ifs;
	std::ofstream ofs;
	ofs.open("1234.bin", std::ios::binary);
	ifs.open("1234.bin", std::ios::binary);
	if (ofs.good()) {
		std::string a = "���� �ȿ���Դϴ�!";
		size_t a_s = a.size();
		ofs.write((const char*)&a_s, sizeof(size_t));
		ofs.write(a.c_str(), a_s);
		print("�Է³�");
		ofs.close();
	}
	if (ifs.good()) {
		std::string new_str;
		size_t size;
		ifs.read((char*)&size, sizeof(size_t));
		new_str.resize(size);

		ifs.read(&new_str[0], size);
		print(new_str);
		ifs.close();
	}
}
/*�Ʊ׷��ϱ� int�� �ڷᰡ ����ִ� x�� �ּҿ� ���� x �ڷ����� ����� �Ѱ��ִ� ���� �޸𸮺�Ͽ� ���� ��Ÿ�����͸� write�� �Ѱ��ֱ� ���ѰŰ�
write�� �װ� ���� x�� �ּҿ� �ִ� ���� ���̳ʸ� �������� �ٲ㼭 �����Ѵٴ°���?

ChatGPT
��, �½��ϴ�. ���� x�� �ּҸ� char* Ÿ������ ��ȯ�ϰ�, sizeof(int)�� ���� int �ڷ����� ũ�⸦ ��� �̸� write �Լ��� ���������ν� �޸� ��Ͽ� ���� ��Ÿ�����͸� �����մϴ�.

write �Լ��� �־��� �޸� ����� ���� �ּҿ� ũ�⸦ �������, �ش� �޸� ��Ͽ� �ִ� ���� ���̳ʸ�(binary) �������� ���Ͽ� �����մϴ�. �� �������� write �Լ��� ���� x�� �ּҷκ��� �����Ͽ� sizeof(int) ����Ʈ��ŭ�� �����͸� ���Ͽ� ���� �˴ϴ�.

��, write �Լ��� ���� x�� �ּҿ� �ִ� ���� ���̳ʸ� �������� ��ȯ�Ͽ� �޸� ��Ͽ� �����ϴ� ������ �����մϴ�. �̷��� ����� �����ʹ� ����(binary) �������� ���Ͽ� ����Ǹ�, ���߿� read �Լ��� ����Ͽ� ���Ͽ��� ���� ���� ������ ������ ���� ������ ���� �����մϴ�.*/