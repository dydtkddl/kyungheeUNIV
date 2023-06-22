#pragma once
#ifndef RATIONAL_H_
#define RATIONAL_H_
class Rational {
	int numerator;
	int denomator;
	static int count;
public:
	Rational(int x, int y) : numerator(x), denomator(y){
		if (count == 0) {
			count = 1;
		}
		else {
			count += 1;
		}
	};
	~Rational() {
		count -= 1;
	}
	
};

#endif