#pragma once

#include <iostream>
#include <string>
#include "Ninja.hpp"

using namespace std;

namespace ariel {

class YoungNinja : public Ninja{
public:
	static const int kYoungNinjaHitPoints = 100;
    	static const int kYoungNinjaSpeed = 14;
    	
	YoungNinja(const string& name, const Point& location) : Ninja(name, location, kYoungNinjaHitPoints, kYoungNinjaSpeed) {}
};
}
