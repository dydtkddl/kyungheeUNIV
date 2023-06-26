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
		std::string a = "나는 안용상입니다!";
		size_t a_s = a.size();
		ofs.write((const char*)&a_s, sizeof(size_t));
		ofs.write(a.c_str(), a_s);
		print("입력끝");
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
/*아그러니까 int형 자료가 들어있는 x의 주소와 원래 x 자료형의 사이즈를 넘겨주는 것이 메모리블록에 대한 메타데이터를 write에 넘겨주기 위한거고
write는 그걸 토대로 x의 주소에 있는 값을 바이너리 형식으로 바꿔서 저장한다는거지?

ChatGPT
네, 맞습니다. 변수 x의 주소를 char* 타입으로 변환하고, sizeof(int)를 통해 int 자료형의 크기를 얻어 이를 write 함수에 전달함으로써 메모리 블록에 대한 메타데이터를 전달합니다.

write 함수는 주어진 메모리 블록의 시작 주소와 크기를 기반으로, 해당 메모리 블록에 있는 값을 바이너리(binary) 형식으로 파일에 저장합니다. 이 과정에서 write 함수는 변수 x의 주소로부터 시작하여 sizeof(int) 바이트만큼의 데이터를 파일에 쓰게 됩니다.

즉, write 함수는 변수 x의 주소에 있는 값을 바이너리 형식으로 변환하여 메모리 블록에 저장하는 역할을 수행합니다. 이렇게 저장된 데이터는 이진(binary) 형식으로 파일에 저장되며, 나중에 read 함수를 사용하여 파일에서 읽을 때도 동일한 과정을 거쳐 변수에 값을 복원합니다.*/