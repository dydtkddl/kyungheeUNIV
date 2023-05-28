/*클래스 개념
override 
virtual
const함수
public 
private
protected
const std::string& variable // 배열가져올때는 실체값으로 들고오는게좋음
#ifndef
#define
#include
#endif
#pragma once
*/
/*virtual table 
virtual선언시 virtual table pointer 까지 그 객체에 포함되어서
인스턴스 크기가 증가함*/
#include <iostream>
#pragma pack(push, 1)
class NoVTable {
	int data;
public:
	void set(int d) { data = d; };
	int get() { return data; }
};
class HasVTable {
	int data;
public:
	virtual void set(int d) { data = d; };
	virtual int get() { return data; };
};
#pragma pack(pop)
int main() {
	NoVTable no;
	no.set(123);
	HasVTable hno;
	hno.set(456);
	std::cout << "no_table_size : " << sizeof(no) << std::endl;
	std::cout << "has_table_size : " << sizeof(hno) << std::endl;

}
