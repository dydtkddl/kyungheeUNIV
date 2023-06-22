//이터레이터
	//1) 역으로 프린트하는거
	//2) 피라미드 형식으로 프린트하는거
//리스트
//맵
//세트
//프라이어리티 큐
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <list>
#include <string>
#include <iterator>
template <typename T>
void reverse_print(const std::vector<T>& a) {
	auto begin = std::begin(a);
	auto end = std::end(a);
	for (auto x = end-1; x!=begin; --x) {
		std::cout << *x << std::endl;
	}

}
template<typename T>
struct Cmp{

	bool operator()(T x, T y) const{ return x > y; }
};
int main() {
	//리스트
	std::list<int> list{ 0,1,2,3,3,4,5,5,5,6,6,7 };
	for (auto l : list) {
		std::cout << l << std::endl;
	}
	list.pop_back();
	list.pop_front();
	list.push_back(12335);
	std::list<int>::iterator a;
	for (std::list<int>::iterator iter = std::begin(list); iter != std::end(list); iter++) {
		std::cout << *iter << std::endl;
	}
	//벡터
	std::vector<int> vec{ 0,1,2,3,4,5,5,6 };
	vec.push_back(123);
	for (auto a : vec) {
		std::cout << a << std::endl;
	}
	for (std::vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
		std::cout << *iter << std::endl;
	}
	reverse_print(vec);
	//세트
	std::set<int> set{ 0,0,0,0,0,0,134,31230,414 };
	for (auto a : set) {
		std::cout << a << std::endl;
	}
	for (std::set<int>::iterator iter = set.begin(); iter != std::end(set); iter++) {
		std::cout << *iter << std::endl;
	}
	std::set<int, Cmp<int>> set2{ 12312,3,4,5,5,4,6,5,7,23,23,1,11,1, };
	for (auto a : set2) {
		std::cout << a << std::endl;
	}
	for (std::set<int>::iterator iter = set2.begin(); iter != std::end(set2); iter++) {
		std::cout << *iter << std::endl;
	}
	//프라이어리티큐
	std::priority_queue<int> pr;
	pr.push(2);
	pr.push(3);
	pr.push(4);
	pr.push(6);
	pr.push(1);
	while (!pr.empty()) {
		std::cout << pr.top() << std::endl;
		pr.pop();
	}
	std::priority_queue<int, std::vector<int>, Cmp<int>> q;
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(6);
	q.push(1);
	while (!q.empty()) {
		std::cout << q.top() << std::endl;
		q.pop();
	}



}