/*             Object-Oriented Programming, Midterm exam (2023-1, CSE103-00)                       */
// Write your answers in Korean or English(답안은 한국어 또는 영어로 작성하시오).

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>


void Print(std::vector<int> v) {
	for (auto x : v)
		std::cout << x << ", ";
	std::cout << std::endl;
}
int Fn1(int alphabet) {
	if (('A' <= alphabet) && (alphabet <= 'Z'))
		return true;
	else {
		return false;
	}
};
void Fn2(double n1, double n2, double& max) {
	max = (n1 >= n2) ? n1 : n2;
};
int Fn3(int st, int fi) {
	int count = 0;
		for (int i = st; i <= fi; ++i) {
			int 나누어떨어지는수=0;
			for (int j = 1; j <= i; ++j) {
				if ((i % j) == 0)
					나누어떨어지는수 += 1;
			}
			if (나누어떨어지는수 ==2) {
				count += 1;
			}
			
		}
	return count;
};
void Fn4(int n1, int n2, int* num) {
	if ((n1 <= 0) or (n2 <= 0)) {
		*num = 0;
		return;
	}
	int min = (n1 <= n2) ? n1 : n2;
	for (int i = 1; i <= n1; ++i) {
		if (((n1 % i) == 0) && ((n2 % i) == 0))
			*num += 1;
	}
};
void Fn5(std::vector<int> v1, std::vector<int>& v2) {
	int index = 0;
	v2.resize(v1.size());
	for (int data : v1) {
		v2[index] = data * data;
		index += 1;

	};
};
std::vector<int> Fn6(const int n) {
	std::vector<int> v(n);
	//사이즈 n 벡터
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			v[0]=rand()%n;
		}
		else {
			int duplicated = 1;
			int input = rand()%n;
			while (duplicated != 0) {
				duplicated = 0;
				for (int j = 0; j < i; ++j) {
					if (v[j] == input) {
						duplicated += 1;
					}
				}
				if (duplicated != 0) {
					input = rand() % n;
				}
			}
			v[i] = input;
		};
	}
	return v;
};
void Fn7(int a) {
	if (a >=2)
		Fn7(a / 2);
	std::cout << a % 2;
};
int main() {
	// 전역 변수 사용 금지(Do not use global variables.)
	srand(static_cast<unsigned>(time(0)));

	std::cout << "\n### 1 ###" << std::endl;
	// 1(2). 아래 코드에서 인수가 영어 대문자이면 true, 아니면 false를 반환하도록 Fn1 함수를 정의하라.(표준함수 사용 금지)
	// (Define the Fn1 function that returns true if the argument is an English uppercase letter or false otherwise. - Do not use standard functions.)
	std::cout << Fn1('A') << ", " << Fn1('b') << ", " << Fn1('8') << std::endl;		// 출력: 1, 0, 0

	std::cout << "\n### 2 ###" << std::endl;
	// 2(2). 아래 코드에서 두 인수의 큰 값을 출력하도록 Fn2 함수를 정의하라.
	// (Define the Fn2 function to print the larger value of two arguments in the following codes.)
	double max1 = 0, max2 = 0;
	Fn2(2.5, 3.5, max1); 	Fn2(1.5, -3.5, max2);
	std::cout << max1 << ", " << max2 << std::endl;	// 출력: 3.5 , 1.5

	std::cout << "\n### 3 ###" << std::endl;
	// 3(3). 아래 코드에서 n1에서 n2까지의 소수의 개수를 반환하는 Fn3 함수를 정의하라.
	// (Define the Fn3 function that returns the number of prime numbers from n1 to n2 in the following codes.)
	std::cout << Fn3(1, 10) << ", " << Fn3(-10, 100) << std::endl;	// 출력: 4, 25

	std::cout << "\n### 4 ###" << std::endl;
	// 4(3). 아래의 코드에서 앞의 두 인수의 공약수 개수를 출력하도록 Fn4 함수를 정의하라.
	// (Define the Fn4 function to print the number of common divisors of the former two arguments.)
	int num1 = 0, num2 = 0, num3 = 0;
	Fn4(18, 32, &num1); 	Fn4(12, 24, &num2); 	Fn4(8, -10, &num3);
	std::cout << num1 << ", " << num2 << ", " << num3 << ", " << std::endl;;			// 출력: 2, 6, 0


	std::cout << "\n### 5 ###" << std::endl;
	// 5(3). 아래 코드에서 v1의 요소의 제곱으로 v2가 할당되는 Fn5 함수를 정의하라.
	// (Define the Fn5 function, where elements of the argument vector (v2) are assigned to the square of the first argument vector (v1) in the following codes.) 
	const std::vector<int> v1{ 1, 2, 7 };
	std::vector<int> v2(5);
	Fn5(v1, v2);
	Print(v1);	// 출력: 1, 2, 7,
	Print(v2);	// 출력: 1, 4, 49,

	std::cout << "\n### 6 ###" << std::endl;
	// 6(4). 아래의 코드에서 std::vector<int> Fn6(const int n) 함수를 정의하라. Fn6는 중복되지 않는 [0, n)의 임의의 정수를 요소로 가지는 크기가 n인 벡터를 반환한다. 
	// (Define std::vector<int> Fn6(const int n) in the following codes. Fn6 returns a vector of n size with elements of non-duplicate random integers ranging [0,n).)
	std::vector<int> s;


	s = Fn6(5);		Print(s);			// 예) 1, 3, 2, 4, 0,
	s = Fn6(20);	Print(s);			// 예) 6, 16, 2, 1, 5, 14, 10, 17, 11, 3, 4, 7, 15, 19, 9, 18, 8, 0, 13, 12,

	std::cout << "\n### 7 ###" << std::endl;
	// 7(3). 아래 코드에서 인수를 이진수로 출력하는 Fn7 함수를 recursive call을 이용하여 정의하라.(가능한 효율적이고 간단하게 작성, 음수는 고려하지 않음)
	// (Define the Fn7 function that prints the argument in binary using recursive call. - The function should be written as efficiently and simply as possible. Do not consider negative numbers)
	// Hint. 10 -> 10%2 = 0, 10/2 = 5 -> 5%2 = 1, 5/2 = 2 -> 2%2 = 0, 2/2 = 1 -> 1%2 = 1, 1/2 = 0
	//                    0                    1                   0                   1 (reverse order)       
	Fn7(0xFA);			// 출력: 11111010
	std::cout << std::endl;
	Fn7(0x37);			// 출력: 110111
	
};