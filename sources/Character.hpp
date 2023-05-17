#pragma once

#include <iostream>
#include <string>
#include "Point.hpp"

using namespace std;

namespace ariel {

class Character {
public:
	Character(string name, Point location, int hitPoints, bool isCowboy);
	Character(const Character& other)=delete;
	Character(Character&& other)=delete;
	Character& operator=(const Character& other)=delete;
	Character& operator=(Character&& other)=delete;
	bool isAlive();
	double distance(Character *another);
	void hit(int points);
	string getName();
	Point getLocation();
	void setLocation(Point newLocation);
	int getHitPoints();
	bool getIsCowboy();
	bool getIsInTeam();
	void setIsInTeam(bool newBool);
	virtual string print() = 0;
	virtual void shoot(Character* enemy);
	virtual bool hasboolets();
	virtual void reload();
	virtual void move(Character* enemy);
	virtual void slash(Character* enemy);
	virtual int getSpeed();
	virtual ~Character() {}
    
private:
	Point location_;
	int hitPoints_;
	string name_;
	bool isCowboy_;
	bool isInTeam_;
};
}
