#include <queue>
#include <iostream>
template<typename T>
struct Cmp {
	bool operator()(T x, T y) {
		return x > y;
	}
};
int main() {
	std::priority_queue<int> a;
	a.push(1);
	a.push(12);
	a.push(13);
	a.push(14);
	a.push(15111);
	a.push(166);
	while (!a.empty()) {
		std::cout << a.top() << std::endl;
		a.pop();
	}
	std::priority_queue<int, std::vector<int>, Cmp<int>> q;
	q.push(123);
	q.push(13);
	q.push(1);
	q.push(3);
	q.push(23);
	q.push(1243);
	q.push(12553);
	while (!q.empty()) {
		std::cout << q.top() << std::endl;
		q.pop();
	}
	

	

}