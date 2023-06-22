#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <exception>
#include <set>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <iterator>
#include <fstream>
#include <random>
#include <filesystem>
#include <iomanip>
std::function<double(double)> derivative(std::function<double(double)>f, double h)
{
	return [f, h](double x) {return (f(x + h) - f(x)) / h; };
}
std::function<double(double)> doublefunc(std::function<double(double)>f, 
	std::function<double(double)>g) 
{
	return [f, g](double x) {std::cout << f(g(x)); return f(g(x)); };
};
int main() {
	//for_each�� ��ȯ���� ���� �Լ��� ��쿡, �� ��Ҹ� ��ȸ�ϸ� ��°����� �Ҷ�
	//transform�� ��ȯ������ ���� ���ͳ�, ������ġ�� �������� ������ ���� �����ϴ°�
	//�׷��� transform�� returnŸ���� �ִ� �����Լ�������

	// ����Ÿ�� ������
		// [](int x)->int{return x*12;};
	//����Ÿ�� ������
		// [](int x){std::cout << x << std::endl;}
	std::cout << [](int x, int y) -> int { return x + y; }(3, 2);
	std::vector<int> a(10);
	std::iota(std::begin(a), std::end(a), 2);
	std::transform(std::begin(a), std::end(a), std::begin(a), [](int y)->int {
		std::cout << 123 << std::endl;
		return y * 123; });
	std::for_each(std::begin(a), std::end(a), [](int y) {std::cout << y << "������" << std::endl; });

	for (int x : a) {
		std::cout << x << std::endl;
	}

	std::vector<int> vec{ 1,2,5,22,7,-5,2 };
	int sum = 0;
	std::for_each(std::begin(vec), std::end(vec), [&sum](int x) {std::cout << sum << std::endl;
	sum += x; });
	std::cout << sum << std::endl;

	int xx = 1, yy = 2;
	auto print0 = [=] { std::cout << xx << " , " << yy << std::endl; };
	auto print1 = [=]() mutable { std::cout << ++xx << " , " << ++yy
		<< std::endl; };
	auto print2 = [&] { std::cout << ++xx << " , " << yy++ << std::endl; };
	auto print3 = [=, &yy] {std::cout << xx << " , " << yy++ << std::endl; };
	print2();

	std::cout << xx << ',' << yy << std::endl;

	auto fn1 = derivative([](double x)->double {return x * x + 2 * x + 1; }, 0.001);
	std::cout << fn1(2) << std::endl;
	auto fn2 = doublefunc([](double x)->double {return 2 * x;
		}, [](double x)->double {return x * x * 2 + 2; });
	fn2(-1);
}
#include <functional>
#include <exception>

�̺��Լ�, �ռ��Լ�
//for_each�¹�ȯ���̾����Լ��ϰ�쿡, ����Ҹ���ȸ�ϸ���°������Ҷ�
//transform����ȯ�����ο������ͳ�, ������ġ���������غ����ǰ��������ϴ°�
//�׷���transform��returnŸ�����ִ¶����Լ�������

// ����Ÿ��������
// [](int x)->int{return x*12;};
//����Ÿ�Ծ�����
// [](int x){std::cout << x << std::endl;}