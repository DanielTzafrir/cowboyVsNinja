#pragma once

#include "Team.hpp" 

namespace ariel {

class SmartTeam : public Team {
public:
	SmartTeam(Character* leader); 
	void attack(Team* enemyTeam) override;
	int getClosestChar() override;
	int chooseVictim(Character* leader) override;
	void print() override;
};
}  // namespace ariel
