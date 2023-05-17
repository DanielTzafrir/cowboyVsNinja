#include "Character.hpp"
#include <cmath>
#include <sstream>

namespace ariel {

	Character::Character(string name, Point location, int hitPoints, bool isCowboy) : name_(name), location_(location), hitPoints_(hitPoints), isCowboy_(isCowboy), isInTeam_(false) {}
	
	void Character::shoot(Character* enemy) {}
	
	bool Character::hasboolets() { return true; }
	
	void Character::reload() {}
	
	void Character::move(Character* enemy) {}
	
	void Character::slash(Character* enemy) {}
	
	int Character::getSpeed() { return -1; }
	
	bool Character::isAlive() { return hitPoints_ > 0; }
	
	double Character::distance(Character* other) { 
		return location_.distance(other->getLocation());
	}
	
	void Character::hit(int points) { 
		if(points < 0) {
			throw invalid_argument("can't get a negative number");
		}
		hitPoints_ -= points; 
	} //what if he is dead?
	
	string Character::getName() { return name_; }
	
	Point Character::getLocation() { return location_; }
	
	void Character::setLocation(Point newLocation) { location_ = newLocation; }
	
	int Character::getHitPoints() { return hitPoints_; }
	
	bool Character::getIsCowboy() { return isCowboy_; }
	
	bool Character::getIsInTeam() { return isInTeam_; }
	
	void Character::setIsInTeam(bool newBool) { isInTeam_ = newBool; }

} 
