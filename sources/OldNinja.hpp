#pragma once

#include <iostream>
#include <string>
#include "Ninja.hpp"

using namespace std;

namespace ariel {

class OldNinja : public Ninja{
	
public:
	static const int kOldNinjaHitPoints = 150;
    	static const int kOldNinjaSpeed = 8;
    	
    	OldNinja(const string& name, const Point& location) : Ninja(name, location, kOldNinjaHitPoints, kOldNinjaSpeed) {}
};
}
