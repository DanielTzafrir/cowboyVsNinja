#include "Point.hpp"
#include <cmath>
#include <sstream>

namespace ariel {

	Point::Point(double x, double y) : x_(x), y_(y) {}

	double Point::distance(Point p) {
	    double dx = x_ - p.getX();
	    double dy = y_ - p.getY();
	    return sqrt(dx*dx + dy*dy);
	}

	string Point::print() {
	    stringstream ss;
	    ss << "(" << x_ << ", " << y_ << ")\n";
	    return ss.str();
	}

	double Point::getX() {
	    return x_;
	}

	double Point::getY() {
	    return y_;
	}

	// Friend function definition
	Point Point::moveTowards(Point src, Point dst, double dist) {
		if (dist < 0) { throw invalid_argument("Distance cannot be negative"); }
		double dx = dst.x_ - src.x_;
		double dy = dst.y_ - src.y_;
		double currentDistance = sqrt(dx*dx + dy*dy);

		if (currentDistance <= dist) {
			return dst;
		} else {
			double ratio = dist / currentDistance;
			double newX = src.x_ + dx * ratio;
			double newY = src.y_ + dy * ratio;
			return Point(newX, newY);
		}
	}
} 
