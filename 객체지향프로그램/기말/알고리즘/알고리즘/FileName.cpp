#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>
#include <random>
template<typename T>
void print(const std::vector<T>& a) {
	for (T x : a) {
		std::cout << x << std::endl;
	};
}
template<typename T>
T plus1000(T a) {
	return a + 1000;
}
template<typename T>
T minus1000(T a) {
	return a - 1000;
}
template<class T>
bool is_even(T n) {
	return n % 2;
}
template<typename T>
T Fn() {
	return 10;
}
bool Fn22(const int& a) {
	return (a > 20);
}
int main() {
	// iota + find
	std::vector<int> seq(10);
	std::iota(std::begin(seq), std::end(seq), 2);
	auto iter = std::find(std::begin(seq), std::end(seq), 6020);
	if (iter != std::end(seq)) {
		std::cout << " dsadsa" << std::endl;
	}
	else {
		std::cout << "!##@" << std::endl;
	}

	//copy
	std::vector<int> seq2(seq.size() - 2);
	std::copy(std::begin(seq) + 1, std::end(seq) - 1, std::begin(seq2));
	print(seq2);
	print(seq);

	//transform
	std::vector<int> a{ 12,32,5,2,64 };
	print(a);
	std::transform(std::begin(a), std::end(a), std::begin(a), plus1000<int>);
	print(a);

	//strm
	auto strm = std::ostream_iterator<int>(std::cout, "씼폴!");
	std::copy(std::begin(a), std::end(a), strm);

	//count 
	int c = std::count(std::begin(a), std::end(a), 1032);
	std::cout << c << std::endl;
	//count if
	int cc = std::count_if(std::begin(a), std::end(a), is_even<int>);
	std::cout << cc << std::endl;

	//shuffle
	std::random_device rdev;
	std::mt19937 mt(rdev());
	std::shuffle(std::begin(seq), std::end(seq), mt);
	print(seq);

	//generate
	std::generate(std::begin(seq), std::end(seq), Fn<int>);
	print(seq);

	//accumulate
	int sum = std::accumulate(std::begin(a), std::end(a), 0);
	std::cout << sum << std::endl;
	std::transform(std::begin(a), std::end(a), std::begin(a),minus1000<int>);
	int multi = std::accumulate(a.begin(), std::end(a), 3, std::multiplies<int>());
	std::cout << multi;

	//partition
	auto att = std::partition(std::begin(a), std::end(a), Fn22);
	print(a);
	std::cout << *att << std::endl;

	//merge
	std::vector<int> nums1(10);
	std::iota(nums1.begin(), nums1.end(), 2);
	std::vector<int> nums2(10);
	std::iota(nums2.begin(), nums2.end(), -20);

	std::vector<int> merged(nums1.size() + nums2.size());
	std::merge(std::begin(nums1), std::end(nums1),
		std::begin(nums2), std::end(nums2), std::begin(merged));
	print(merged);

	//remove 
	std::remove(std::begin(merged), std::end(merged), 9);
	print(merged);
	std::cout << "굳" << std::endl;
		//머지 플러스 이레이즈 플러스 리무브
	merged.erase(std::remove_if(std::begin(merged), std::end(merged), is_even<int>), std::end(merged));
	std::cout << "굳" << std::endl;

	print(merged);
	std::cout << "굳" << std::endl;


}