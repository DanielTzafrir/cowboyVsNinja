#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace ariel {

class Point {
public:
	Point(double xPar, double yPar);
	double distance(Point point);
	string print();
	static Point moveTowards(Point src, Point dst, double dist);
	double getX();
	double getY();
    
private:
	double x_,y_;
};
}
