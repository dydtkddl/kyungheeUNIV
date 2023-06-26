////어레이01 : An example array program
//#include <iostream>
//int main() {
//	int prime[5];
//	prime[0] = 12;
//	prime[1] = 1;
//	prime[2] = 3;
//	prime[3] = 4;
//	prime[4] = 144;
//	std::cout << prime[0] << std::endl;
//	std::cout << "sum" << prime[0] + prime[1] + prime[2] + prime[3] + prime[4] << std::endl;
//	return 0;
//}

////어레이02 : Array Data Types
//#include <iostream>
//int main() {
//	double arr[3];
//	arr[0] = 2.0;
//	arr[1] = 3.0;
//	arr[2] = 3.1445;
//	std::cout << "The Average is " << arr[0] + arr[1] + arr[2] << std::endl;
//}

////어레이03 : 구조체 배열
//#include <iostream>
//struct Rectangle {
//	int width; 
//	int height;
//	/*아래와 같이 기본생성자를 default로 지정해주지 않으면
//	* Rectangle A[4]와 같은 인스턴스 배열을 생성시 생성자가 참고할 기본생성정보가
//	* 없어서 생성하지 못하고 오류가 나게되는 상황이 생긴다.
//	Rectangle(int width, int height) :width(width), height(height) {
//	}*/
//	Rectangle(int width=123, int height=333) :width(width), height(height) {
//	}
//};
//void PrintRectangle(const Rectangle& A) {
//	std::cout << "너비 : " << A.width << std::endl;
//	std::cout << "높이 : " << A.height << std::endl;
//
//}
//int main() {
//	int n;
//	std::cin >> n;
//	Rectangle* A = new Rectangle[n];
//	for (int i = 0; i < n; i++) {
//		PrintRectangle(A[i]);
//	}
//	delete[] A;
//
//}


////어레이 04 : Fixed array declarations
//// 고정배열을 선언할 떄 배열의 길이는 컴파일 타임 상수여야한다
////.(컴파일타임에 고정배열의 길이를 알아야하니까)
//#include <iostream>
//int main() {
//	//리터럴 상수 사용. (using a literal constant)
//	int arr[5];
//
//	//매크로 기호상수 사용
//	//using a macro symbolic constant
//	#define MAX_ARRAY_LENGTH 5
//	int arr2[MAX_ARRAY_LENGTH]; 
//
//	//기호 상수 사용
//	//using a symbolic constant
//	const int arrayLength = 5;
//	int arr3[arrayLength];
//
//	//비상수 또는 런타임 상수는 사용할 수 없다.
//	//using a non-const variable;
//	//비 상수 변수 사용.
//	int length = 12;
//	int arr4[length];
//
//	// using a runtime const variable
//	//런타임변수 사용
//	int temp = 5;
//	const int length = temp;
//	int array[length];
//
///*개념정리
//리터럴 상수 정수. 키보드 숫자를 쳐서 바로 입력하는 상수
//매크로 기호상수. #define LENGTH 102 와 같이 선언하는 상수
//기호 상수. const int a = 12; 와 같이 컴파일 단계에서 cinst선언과 함꼐 정수를 입력받는 상수
//
//비 상수 변수. int length =12;와 같이 const선언 없이 변수에 정수를 입력받는 형태
//런타임 상수 변수. int temp = 12; const int length = temp; 와 같이 const상수 선언되었지만
//				런타임시간에 변수의 값을 넘겨받아 런타임상수변수.
//*/
//	/*그러니까 가능한 경우는
//	매크로로 상수를 지정하거나
//	const 자료형 변수이름 = 정수 로 상수변수에 컴파일시간에 할당하거나
//	리터럴 상수를 사용해야함.*/
//}

////어레이 05 initializing fixed arrays
////고정배열을 초기화 하는방법
//#include <iostream>
//int main() {
//	//1. 일일이 요소하나하나 초기화하는 코드를 짠다.
//	int arr[4];
//	arr[0] = 12;
//	arr[1] = 124;
//	arr[2] = 112;
//	arr[3] = 2;
//	//2. 초기화 목록을 사용한다.
//	int arr2[5] = { 1,2,3,4,6 };
//		//저장할 수 있는 목록보다 더 많은 초기화값이 있으면 컴파일러에서 오류
//		int arr3[2] = { 1,2,3 };
//		//더 적으면 나머지는 0으로 할당
//		int arr3[2] = { 1 };
//		//아예 초기화 리스트가 없으면 garbage value만 할당.
//		int arr4[2];
//		// 모든 요소를 초기화하려면?
//		int arr5[12] = {};
//		// c++의 유니폼 초기화?
//		int uniform[12]{ 1,235,5,4,4,2, };
//		// ommited length?? 컴파일러가 자동으로 배열의 길이를 알아서 정해줌
//		int ommited_length[] = {12,3,3,4,1,5}
//		//ex) 예시
//		const int number = 5;
//		/*int temp = 12;
//		* const int a = temp;
//		* int exarr[a]하면 오류난다. 왜냐하면 이것은 런타임상수변수이기 떄문이다.
//		*/
//		int exarr[number] = { 1,2,3 };
//		for (int i = 0; i < number; i++) {
//			std::cout << exarr[i] << std::endl;
//		};
//		return 0;
//}

//어레이 06 
/* 함수에 배열을 전달하는 법.
C++에서는 배열을 전달할 떄 다르게 처리한다
일반 변수가 값으로 전달되면 C++은 인수값을 함수 매개변수로 복사한다.
매개변수는 복사본이라서 맥변수의 값을 변경해도 원래인수의 값은 변경되지 않는다.

그러나 배열이 만약에 크면 배열을 복사하는 것은 매우 비싼 작업일 수 있으므로 C++은 배열이
함수로 전달될 때 배열을 복사하지 않는다.
대신 실제 배열이 전달된다.
이는 배열요소의 값을 직접 변경할 수 있는 부작용이 있다.
*/
//#include <iostream>
//void passValue(int value) {
//	value = 99;
//};
//void passArray(int prime[5]) {
//	prime[0] = 11;
//	prime[1] = 11;
//	prime[2] = 11;
//	prime[3] = 12;
//	prime[4] = 33;
//}
//void passArray_const(const int prime[5]) {
//	prime[0] = 11;
//	prime[1] = 11;
//	prime[2] = 11;
//	prime[3] = 12;
//	prime[4] = 33; // 이렇게 하면 아예 바꿀수가 없음
//}
//void print(int a) {
//	std::cout << a << std::endl;
//}
//void print(const int prime[5]) {
//	for (int i = 0; i < 5; i++) {
//		std::cout << prime[i] << ',';
//	};
//	std::cout << std::endl;
//}
//int main() {
//
//	int value = 133;
//	int arr[5]{ 1,2,3,4,5 };
//	print(value);
//	print(arr);
//	passValue(value);
//	passArray(arr);
//	print(value);
//	print(arr);
//	/*출력
//	133
//	1,2,3,4,5,
//	133
//	11,11,11,12,33, // 값이 바뀜.
//	*/
//}

////어레이 07 어레이의 사이즈
////sizeof and arrays
//#include <iostream>
//void printSize(int arr[]) { // 배열은 함수로 전달될 떄 포인터로 전달된다.
//	// 그리고 이떄 sizeof(arr)은 포인터의 크기를 나타내기 떄문에 , 이 컴퓨터에서는
//	// 포인터크기인 8이 출력된다.
//	std::cout << sizeof(arr) << std::endl;
//}
//int main() {
//	int array[]{ 1,2,3,4,5,61,2,3,5,6,44,2 };
//	std::cout << sizeof(array) << std::endl;
//	printSize(array);
//	return 0;
//}

////어레이 08 배열의 크기를 이용해서 배열의 길이를 알아내는 법.
//#include <iostream>
//int main() {
//#define ARR_LEN 12
//	int arr[ARR_LEN]{ 12,3,4,4,2,4,2,5,1 };
//	std::cout << "배열의 길이는 : " << sizeof(arr) / sizeof(arr[0]);
//}

////어레이 09 .더 큰 인덱스에 값을 할당하려고 하면 오류가 나고 종료.
//#include <iostream>
//int main() {
//	int prime[5];
//	prime[5] = 123;
//	return 0;
//}

