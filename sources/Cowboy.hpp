#pragma once

#include <iostream>
#include <string>
#include "Character.hpp"

using namespace std;

namespace ariel {

class Cowboy : public Character{
public:
	Cowboy(string name, Point location);
	void shoot(Character* enemy) override;
	bool hasboolets() override;
	void reload() override;
	string print() override;
	
private:
	int bullets_;
};
}
