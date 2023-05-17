#pragma once

#include <iostream>
#include <string>
#include "Character.hpp"

using namespace std;

namespace ariel {

class Ninja : public Character{
public:
	Ninja(string name, Point location, int hitPoints, int speed);
	Ninja(const Ninja& other)=delete;
	Ninja(Ninja&& other)=delete;
	Ninja& operator=(const Ninja& other)=delete;
	Ninja& operator=(Ninja&& other)=delete;
	void move(Character* enemy) override;
	void slash(Character* enemy) override;
	string print() override;
	int getSpeed() override;
	~Ninja() override {}
private:
	int speed_;
};
}
