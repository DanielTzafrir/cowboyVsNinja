#include "Ninja.hpp"
#include <cmath>
#include <sstream>

namespace ariel {

	Ninja::Ninja(string name, Point location, int hitPoints, int speed) : Character(name, location, hitPoints, false), speed_(speed) {}
	/*
	// Copy constructor
	Ninja::Ninja(const Ninja& other) : Character(other), speed_(other.speed_) {}
	
	// Move constructor
    	Ninja::Ninja(Ninja&& other) : Character(move(other)), speed_(other.speed_) {}
        */
	void Ninja::move(Character* enemy) {
		setLocation(Point::moveTowards(getLocation(), enemy->getLocation(), speed_));
	}
	
	void Ninja::slash(Character* enemy) {
		if(!isAlive()) {
			throw runtime_error("the ninja is dead");	
		}
		if(enemy == this) {
			throw runtime_error("Can't make a self damage");
		}
		if(getLocation().distance(enemy->getLocation()) <= 1) {
			if(enemy->isAlive()) {
				enemy->hit(40);
			}
			else { throw runtime_error("can't slash a dead man"); }
		}
	}
	
	string Ninja::print() {
		stringstream ss;
		ss << "N \n";
		if(isAlive()) {
			ss << "Character Name: " << getName() << "\n";
			ss << "Hit points: " << getHitPoints() << "\n";
		}
		else {
			ss << "Character Name: (" << getName() << ")\n";
		}
		ss << "Location: " << getLocation().print();
		return ss.str();
	}
	
	int Ninja::getSpeed() { return speed_; }
} 
