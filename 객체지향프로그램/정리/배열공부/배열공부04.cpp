//배열공부 04
// 포인터에 대해서 알아보겠다

/*변수는 값을 보유하고 있는 메모리 조각의 "이름"이다.
프로그램이 변수를 인스턴스화 할때 사용 가능한 메모리의 주소가 변수에 자동으로 
할당되고 변수에 할당된 값은 이 메모리 주소에 저장된다*/
#include <iostream>
#include <typeinfo>
int main() {
	int x; // 이때는 프로그램이 사용가능한 메모리의 주소를 변수에 자동으로 할당한다.
	//그러나 아직 할당된 값이 없으므로 , 초기화 오류가난다.
	//std::cout << x; <- 초기화 오류남
	x = 123;
	std::cout << x << std::endl;
	/*이때 &를 통해서 주소를 확인 할 수있다*/
	std::cout << &x << std::endl;
	//00000030E2B0F974

	/*그리고 이때 그 포인터, 즉 주소값을 또 변수에 담을 수도 있는데 아래와같이 변수로 담을 수 있다*/
	int* ptr_x = &x;//인트형 값을 가지는 x변수의 주소의 주소값을 ptr_x에 담는다 라는뜻
	std::cout << ptr_x << std::endl;
	//000000A7AD79F7D4

	/*그리고 주소값을 담은 포인터변수에서 다시 값을 가져올 수 있다.
	이를 역참조라고하고 역참조 연산자 *를 사용한다*/
	std::cout << *ptr_x << std::endl;
	//123

	/*포인터 변수는 일반 변수처럼 선언된다. 다만 자료형과 변수 이름사이에 별표가 붙을뿐*/
	bool* boolptr;
	int* intptr;
	float* floatptr;
	double* doubleptr;
	long long int* llintptr;
	unsigned int* unsignedptr;
	//이렇게 다양하게 생성가능

	/*포인터 변수를 선언하는 경우, 별표가 각 변수에 포함되어 있어야한다*/
	int* ptr1, ptr2;//이렇게 하면 ptr2는 그냥 int로 선언
	int* ptr3; int* ptr4;// 이렇게해야 ptr3와 ptr4가 둘다 int형 포인터로 선언


	/*포인터에 값 할당, 값변경, 값 접근*/
	int value = 5;
	int* ptr = &value;
	int* ptr5;
	ptr5 = &value;
	*ptr5 = 123;

	/*주소연산자 &는 피연산자의 주소를 리터럴로 반환하지 않는다
	대신 피연산자의 주소가 들어있는 포인터를 반환한다.*/
	//#include <typeinfo>를 이용
	int newx = 4;
	std::cout << typeid(&newx).name() << std::endl;;
	//int* ptr__64

	/*dereferencing 역참조*/
	int a = 123;
	int* ptr_a = &a;//a의 int *포인터를 반환해서 ptr_a인트형포인터변수에 전달한다.
	std::cout << ptr_a << std::endl << *ptr_a << std::endl;

	/*응용프로그램이 운영체제에 의해 할당되지 않은 메모리 위치에 접근하려고 하면
	운영체제가 응용프로그램을 종료한다*/
	/*포인터는 배열이나 구조체 클래스 벡터같은 자료형에서 유용하다
	왜냐하면 그것을 가리키는 포인터를 참조함으로써
	큰 용량의 그런 자료형을 가져다 끌어올수있으니까	*/


	/*널포인터
	일반 변수와 마찬가지로 포인터는 인스턴스화 될 떄 초기화되지 않는다.
	값이 할당되지 않으면 포인터는 기본적으로 어떤 가비지주소를 가리킨다.
	*/
	//int* garbageptr;
	//std::cout << garbageptr << std::endl;
	/*하지만 이는 컴파일 오류가 난다. garbage 포인터가 가리키는 garbage주소에
	존재하는 어떤 값은 이 프로세스가 가진 주소가 아니기 때문이다.*/
	/*포인터는 메모리 주소외에도 null값을 가질 수 있다.
	널은 포인터가 아무것도 가리키고 있지 않다는 것을 의미한다.
	*/
	float* ptrflt{ 0 };// ptr is now a null pointer
	float* ptrflt2; // ptr is uninitialized
	ptrflt2 = 0; // ptr is now a null pointer

	//널포인터는 불린값으로 0이 반환된다.
	bool bollptrflt= ptrflt;
	std::cout << bollptrflt << std::endl;
	if (bollptrflt)
		std::cout << "ptr is pointing to a int value.";
	else
		std::cout << "ptr is a null pointer.";
	//따라서 다른값을 지정하지 않을때는 포인터를 null값으로 초기화하자.

}