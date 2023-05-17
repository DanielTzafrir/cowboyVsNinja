#include "Cowboy.hpp"
#include <cmath>
#include <sstream>

namespace ariel {

	Cowboy::Cowboy(string name, Point location) : Character(name, location, 110, true), bullets_(6) {}
	
	void Cowboy::shoot(Character* enemy) {
		if(!isAlive()) {
			throw runtime_error("The cowboy is dead");
		}
		if(enemy == this) {
			throw runtime_error("Can't make a self damage");
		}
		if(bullets_ > 0) {
			if(enemy->isAlive()) {
				enemy->hit(10);
				bullets_ -= 1;
			}
			else { throw runtime_error("Can't shoot a dead man"); }
		}
	}
	
	bool Cowboy::hasboolets() { return bullets_ > 0; }
	
	void Cowboy::reload() { 
		if(!isAlive()) {
			throw runtime_error("Dead man can't reload");
		}
		bullets_ = 6; 
	}
	
	string Cowboy::print() {
		stringstream ss;
		ss << "C \n";
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
	
} 
