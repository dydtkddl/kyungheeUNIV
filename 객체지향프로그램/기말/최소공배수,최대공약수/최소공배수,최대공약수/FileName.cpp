#include <iostream>
#include <string>
#include <vector>
int gcd1(int m, int n) {
	if (n > m) {
		int temp;
		temp = n;
		n = m;
		m = temp;
	};
	bool flag = true;
	int gcd = 1;
	while (flag) {
		for (int i = 2; i < n + 1; i++) {
			flag = true;
			if ((m % i == 0) and (n % i == 0)) {
				gcd *= i;
				n /= i;
				m /= i;
				break;
			}
			flag = false;
		}

	}
	return gcd;
}
int gcd2(int m, int n) {
	if (n==0){
		return m;
	}
	else {
		return gcd2(n, m % n);
	}
}
int lcm1(int m, int n) {
	return m * n / gcd1(m, n);
}
int lcm2(int m, int n) {
	return m * n / gcd2(m, n);
}
int main() {
	std::cout << gcd1(120, 48) << std::endl;
	std::cout << gcd2(120, 48) << std::endl;
	std::cout << lcm1(120, 48) << std::endl;
	std::cout << lcm2(120, 48) << std::endl;


}