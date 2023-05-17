#pragma once

#include <iostream>
#include <string>
#include "Ninja.hpp"

using namespace std;

namespace ariel {

class TrainedNinja : public Ninja{
public:
	static const int kTrainedNinjaHitPoints = 120;
    	static const int kTrainedNinjaSpeed = 12;
    	
	TrainedNinja(const string& name, const Point& location) : Ninja(name, location, kTrainedNinjaHitPoints, kTrainedNinjaSpeed) {}
};
}
