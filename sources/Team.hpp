#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

using namespace std;

namespace ariel {

class Team {
public:
	Team(Character* leader);
	Team(const Team& other) = delete;  // Delete copy constructor
    	Team& operator=(const Team& other) = delete;  // Delete copy assignment operator
    	Team(Team&& other) = delete;  // Delete move constructor
    	Team& operator=(Team&& other) = delete;  // Delete move assignment operator
	void add(Character* fighter);
	virtual void attack(Team* enemyTeam);
	virtual int getClosestChar();
	virtual int chooseVictim(Character* leader);
	int stillAlive();
	virtual void print();
	Character* getLeader();
	void setLeader(Character* newLeader);
	Character* getFighter(int index) const;
	int getVecSize();
	int getNumOfFighters();
	void setNumOfFighters(int newNumOfFighters);
	virtual ~Team();
private:
	Character* leader_;
	vector<Character*> fighters_;
	int vecSize_;
	int numOfFighters_;
};

}
