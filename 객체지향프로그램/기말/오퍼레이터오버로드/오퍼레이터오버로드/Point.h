#pragma once
#ifndef POINT_H_
#define POINT_H_
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <random>
class Point {
public:
	double x;
	double y;
	Point() {};
	Point(double x, double y) :x(x), y(y) {};
	Point operator-(const Point& xx) {
		Point result;
		result.x = x - xx.x;
		result.y = y - xx.y;
		return result;
	}

};

#endif