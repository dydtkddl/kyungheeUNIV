// Pointers to Objects and Objects Arrays(1)
// Pointers to Objects

// 객체를 가리키는 포인터를 생성하고 활용할 수 있다.
// 그 포인터에 동적할당을 해줄 수 있다.
#include <iostream>
#include <string>
#include <vector>
class Account {
public:
	std::string name;
	int id;
	int money;
	Account(std::string name, int id, int money) :name(name), id(id), money(money) {}
};
void PrintAccountInfo(Account A) {
	std::cout << A.name << ", " << A.id << ", " << A.money << std::endl;
}
int main(){
	Account acct("안용상", 12, 30000);
	Account* acct_ptr;
	acct_ptr = &acct;
	PrintAccountInfo(acct);
	PrintAccountInfo(*acct_ptr);
	acct_ptr = new Account("강아지", 14, 2000);//동적할당
	// new로 동적할당할때, 그 할당하는 객체의 주소를 반환해서 넘겨준다.
	PrintAccountInfo(*acct_ptr);
	delete acct_ptr;
	// 아래 코드는 컴파일오류 남.
	// PrintAccountInfo(*acct_ptr);
		// 그 이유는??
		// delete acct_ptr을 해줬으므로, acct_ptr이 가리키는 주소에
		// 이제 더이상 동적할당해준 값들이 존재하지 않음.
		// 따라서 그 주소는 이제 더이상 이 프로세스가 접근할 수 있는 주소가 아니게됌.
		// 따라서, acct_ptr은 여전히 이전에 가리켰던 그 주소를 가지고 있지만,
		// 그 주소의 값에 접근하는 순간, 접근권한에 걸려서 컴파일 오류가 나게됌.
}