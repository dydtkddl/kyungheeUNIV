/*Ŭ���� ����
override 
virtual
const�Լ�
public 
private
protected
const std::string& variable // �迭�����ö��� ��ü������ �����°�����
#ifndef
#define
#include
#endif
#pragma once
*/
/*virtual table 
virtual����� virtual table pointer ���� �� ��ü�� ���ԵǾ
�ν��Ͻ� ũ�Ⱑ ������*/
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
