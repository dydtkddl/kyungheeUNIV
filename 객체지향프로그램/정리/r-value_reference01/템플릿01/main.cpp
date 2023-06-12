#include <iostream>
int g(int& n) {
	return 10 * n;
}
int h(const int& n) {
	return 10 * n;
}
int r(int&& x) {
	x += 13;
	return x;
}
int main() {

	int x = 1;
	int y = 2;
	//x + 2 = y;  error ! 왜냐하면 왼쪽에는 변수가 와야하니까
	/*assignment operator 의
	왼쪽에 올 수 있는 것들을 l-value 
	오른쪽에 올 수 있는 것들을 r-value
	*/
	//int& r = x + 1; error !
	// // x+1이라는 객체가 저장되어있어도
	// x+1이라는 것 자체를 수정할 수는 없으니까
	//수정불가라는 명시 const기호가 있지 않으면
	//수정이 불가능한데 수정에 대한 여지를 남겨두기에
	//문법오류가난다.
	const int& cr = x + 3; 
	// 메모리상에 x + 3이라는 객체가 어찌됬든 저장되어있을텐데
	//x + 3이라는 것 자체를 수정할수는 없으니까 const로 받는다
	
	
	// std::cout << g(x + 2) << std::endl; illegal
	std::cout << h(x + 2) << std::endl; //legal

	/*그러나 이런 const int& a 와 같은 방식으로는
	r-value를 받을 수는 있지만, 그것을 가지고 수정을 적용하기는 어렵다
	변수를 혼합해서 수식을 r-value로써 넘기더라도
	이로인해 생긴 값을 reference로 가지게 하는 변수가 있다면 어떨까?
	
	그것이 r-value reference이다.
	메모리의 효율성을 높이기 위해서 쓴다.
	
	r-value reference같은 방법이 없다면
	수식으로 넘겨받아 계산된 값을 스코프 내에서 
	수정할 수 없으므로, 새로운
	변수를 하나 더 만들어서 거기에 녹여내야한다
	int g(const int& a){
		int n;
		n = a + 13;
		return n;
	}
	이런식으로 한번 값을 건네받는 변수가 필요하다.

	하지만 r-value refernece가 있다면
	int g(int&& r){
		r = r + 13;
		return r;
	}
	과 같은식으로 한 변수로 모든 처리가 가능하다
	*/
	std::cout << r(y * 13) << std::endl;
	// 즉 이와같이 r-value를 쓰면
	/* 인자로써 변수로 만들어진 수식으로써의 인자를
	전달 할 수 있고(r-value)
	또한 그렇게 전달된 r-value인자의 값을 담은 변수를
	함수내에서 바로 수정이 가능하다.

	함수내에서 초반 수식 처리를 따로 하지 않아도 되먀
	새로운 변수를 만들지 않아도 된다는 장점이있다
	*/
}