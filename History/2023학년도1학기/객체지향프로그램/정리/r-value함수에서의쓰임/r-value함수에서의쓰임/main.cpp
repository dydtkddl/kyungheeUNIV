#include <iostream>
class Ex {
public:
	int x;

	Ex() : x(0) {
		std::cout << "default_constructor" << std::endl;
	};
	Ex(const Ex& e) :x(e.x) {
		std::cout << "copy_constructor" << std::endl;
	};
	Ex(Ex&& e) : x(e.x) {
		std::cout << "move_constructor" << std::endl;
	}
};
//카피되는 조건과 경우
//그냥 무브되는 조건과 경우를 잘 알고 있어야한다.
// 카피되는 경우
// 1. 
// return 타입이 reference&인 함수가 아니며,r-value가 아닌 변수를 반환할 떄,
//  함수내의 값을 전달해서 새로 만든 변수메모리에 할당해서
// 반환한다
// 2.
// 인자의 타입이 reference변수가 아닐때, 해당 인자로 전달된 값을 함수의 파라미터가
// 메모리에 저장하고, 복사. 즉, 같은 값을 가지는 하나의 변수를 더 만든다는 것.

//카피되지 않는 경우.
//1. return 타입이 reference&로 정의되어 있는 경우. 함수내에서 처리한 값을 갖고있는 함수내 변수를
// 별칭만 바꿔서 그대로 전달한다.
//2. 인자의 타입이 reference&로 정의되어있는 경우. 함수의 파라미터에 값을 넣어 새로 변수를
//copy생성하지 않고, 전달된 변수 실체값을 파라미터의 기호로 별명만 바꿔서 직접사용

//카피되지않으며 수정불가한 경우 const int& x;
//1. 인자의 타입이 reference와 const둘다 적용되어있을때.
// 이경우는 파라미터의 이름을 별칭으로 갖고 같은 메모리에 들어있는 실체값을 공유하지만
// 이를 수정할 수 없게 const타입의 별칭으로 받는다.

//무브되는 경우
// 1. 파라미터가 &&로 받아질때
// 수정할 수 있는 r-value 인자.
// 

Ex Fn1(const Ex& e) { 
	return e; // 이부분에서 copy_constructor가 호출
}
Ex Fn2(Ex e ){ // Ex e를 인자로 받는 부분에서 copy_constructor가 호출 
	e.x = 12;
	return e ;// 이부분에서 move_constructor를 정의했기떄문에
	// 그대로 받는 상황에서 move_constructor를 받는다.
	// 인자(copy) -> 함수내 처리 -> 다시(copy)반환
	// 인자(copy) -> 함수내 처리 -> 그 처리된 값을 그대로(move)반환

	//만약 무브컨스트럭터가 정의되어있지 않으면
	//이경우 카피컨스트럭터가 호출됨

	//r-value reference를 인자로 갖는 무브컨스트럭터가 정의되어있으면
	// 보다 메모리 효율적인 무브컨스트럭터가 사용됌.

	//여기서 다시..! r-vaue reference &&를 이용한다는 것은
	// 수식형태를 받을수도 있다는 것이고,
	//그러면서도 그 값을 변경할수도 있다는 것.
}
int main() {
	Ex e1;
	Fn1(e1);
	std::cout << std::endl;
	Fn2(e1);
}