#pragma once

#include "Team.hpp" 

namespace ariel {

class Team2 : public Team {
public:
    Team2(Character* leader); 
    void attack(Team* enemyTeam) override;
    int getClosestChar() override;
    int chooseVictim(Character* leader) override;
    void print() override;
    //~Team2();
};

}  // namespace ariel
