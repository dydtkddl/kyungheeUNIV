//배열공부 05
/*포인터와 배열
C++에서 포인터와 배열은 밀접한 관계가 있다*/
#include <iostream>
//void printSize(int* array)
//{
//	// array is treated as a pointer here
//	std::cout << sizeof(array) << '\n'; // prints the size of a pointer, not the size of the array!
//}
void printSize(int array[])
{
	// array is treated as a pointer here, not a fixed array
	std::cout << sizeof(array) << '\n'; // prints the size of a pointer, not the size of the array!
}
int main() {
	int array[5]{ 1,2,3,4,5 };
	//위의 array는 정수 5개의 배열이지만, 컴파일러에는 배열이 int[5]의 변수다.
	//긱긱 array[0]. array[1], array[4]의 값을 가진다. 그러나 배열자체는 어떤 값을 가질까?
	
	std::cout << array << std::endl; //배열은 마치 포인터처럼 배열의 첫번째 요소의 주소를 가진다.
	//배열변수가 보유한 주소는 배열 첫번쨰 요소의 주소이다.

	//C++에서 배열과 포인터가 같다고 생각하는 것은 일반적인 오류다.
	/* 두 요소모두 배열의 첫번째 요소를 가리키고 있지만, 형식정보가 다르다
	array는 int[5]의 타입이고, 배열에 대한 포인터는 int*의 타입이다. */
	std::cout << *array << std::endl;

	/*포인터와 배열은 다르다*/
	std::cout << "어레이의 사이즈 : " << sizeof(array) << std::endl;
	int* ptr = array;
	std::cout << "포인터의 사이즈 : " << sizeof(ptr) << std::endl;
	/*고정배열은 배열이 가리키는 길이정보를 포함하지만, 배열에 대한 포인터로
	그 고정배열의 시작주소를 할당한 포인터는 이를 모른다. 그저 포인터일 뿐*/
	printSize(array); // 함수의 파라미터로 array배열을 넘겨줄때, 인자를 int* arr로 받으나 int arr[]로 받으나
	// 첫요소에 대한 포인터를 받는 다는 것은 같다.
	//그리고 이경우 배열자체를 넘겼음에도, 길이정보를 모르는 ptr만 넘겨진다.
	//이것은 문제가될수있다.
	//또한 함수로 전달될 때, 배열이 포인터로 변환되므러, 함수에서 배열을 변경하면 실제 배열을 변경하는 것과 같다.
	
	std::cout << &array[1] << '\n'; // print memory address of array element 1
	std::cout << array + 1 << '\n'; // print memory address of array pointer + 1 

	std::cout << array[1] << '\n'; // prints 7
	std::cout << *(array + 1) << '\n'; // prints 7 (note the parenthesis required here)


	char c = 'Q';
	std::cout << &c;
	/*이 경우, 프로그래머는 변수 c의 주소를 출력하려고 한다. 그러나 &c는 char* 타입을 가지고 있으므로 std:cout는 이것을 문자열로 출력하려고 한다. 다음과 같이 출력된다.

Q╠╠╠╠╜╡4; ¿ ■ A
왜 그럴까? &c를 문자열이라고 가정한다. 그래서 'Q'를 출력한 다음 쓰레기값을 출력한다. 널 종결자를 가진 어떤 메모리를 만날때까지 출력하는 것이다. 변수 c 다음 메모리 내용에 따라 달라질 수 있다.*/
	return 0;
}