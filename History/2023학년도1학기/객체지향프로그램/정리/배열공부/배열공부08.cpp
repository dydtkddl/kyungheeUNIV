/*포인터와 const
지금까지 본 모든 포인터는 상수가 아닌 값을 가리티는 비 상수 포인터이다.
*/
#include <iostream>
int main() {
	int value = 5;
	int* ptr = &value;
	int* ptr2 = new int{ 15 };
	int* ptr3 = new int(14);
	int* arr = new int[15];
	delete[] arr;
	arr = 0;

	const int value_const = 5;
	//int ptr_const = &value_const; 컴파일 되지 않음 왜냐하면, 상수변수는 값을 변경할 수 없는데
	//만약 상수가 아닌 포인터가 상수를 가리킨 다음에 역참조해서 값을 바꿀 수 있다면
	//const의도를 위반하므로.
	const int* ptr_const = &value_const;//이렇게 포인터 또한 상수 int를 가리킨다고 const를 붙혀줘야함
	

	int v1 = 5;
	const int* v1ptr = &v1; // 포인터로는 역참조해서 바꾸지못하게 하고싶은데, 값을 정참조할떈 
	//할수 있게할떄

	v1 = 6;
	std::cout << *v1ptr << std::endl; // 6
	v1ptr = ptr_const;
	std::cout << *v1ptr << std::endl;
	//*v1ptr = 6; v1ptr이 비록 일반 int를 가리키지만, v1ptr은 가리키는 대상을 const하다고
	//여기므로 포인터를 역참조해서 바꾸는 것은 불가능

	//포인터 자체를 상수로 만들 수 있다.
	int v2 = 4;
	int* const ptr_v2 = &v2;
	//상수포인터는 늘 같은 위치를 가리킨다.
	v2 = 56;
	std::cout << ptr_v2 << ' ' << *ptr_v2 << std::endl;


	/*정리하자면
	const int a = 123;을 하면 상수정수가 선언
	const int *ptr_a = &a;하면 상수정수를 가리키는 포인터를 선언. 포인터 주소는 바꿔도됌
	int* const ptr = &a;를 하면 a의 주소를 가리키는 상수포인터. 안에있는 값은 바꿔도 됌*/
	// const int* const ptr = &a 를 하면 상수 정수를 가리키는 상수 포인터.
}