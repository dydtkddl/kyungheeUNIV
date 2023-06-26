/*동적으로 배열 할당하기
동적으로 런타임 동안 배열길이를 선택할 수 있다.
new[] delete[]*/
#include <iostream>
int main() {
	std::cout << "Enter Positive Integer : ";
	int length;
	std::cin >> length;
	int* array = new int[length]; // garbage value 로 설정.
	std::cout << "i just allocated an array of integers of length" << length << '/n';
	array[0] = 5;
	std::cout << "the first element of array is " << *array << std::endl;
	for (int i = 0; i < length; i++) {
		std::cout << array[i] << std::endl;
	}
	std::cout << sizeof(array) << std::endl;
	int* array2 = new int[length]();
	for (int i = 0; i < length; i++) {
		std::cout << array2[i] << std::endl;
	}
	std::cout << sizeof(array2) << std::endl;
	delete[] array;
	delete[] array2;

	int* array3 = new int[]; // 오류..
	return 0;
}