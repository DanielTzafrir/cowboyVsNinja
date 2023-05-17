#include "Team2.hpp"
#include <limits>

namespace ariel {

	Team2::Team2(Character* leader) : Team(leader) {}
	
	void Team2::attack(Team* enemyTeam) {
		if(enemyTeam == nullptr) { throw invalid_argument("Sent as argument null pointer"); }
		// If the leader is dead:
		if(!getLeader()->isAlive()) { 
			int closestFighterIdx = getClosestChar();
			if (closestFighterIdx == -1) { 
				return;
			}
			setLeader(getFighter(closestFighterIdx));
		}
		// Choose the victim
		int victimIdx = enemyTeam->chooseVictim(getLeader());
		if (victimIdx == -1) { 
			return;
		}
		// Attack the victim
		for (int i = 0; i < getVecSize(); i++) {
			if (!enemyTeam->getFighter(victimIdx)->isAlive()) {
				victimIdx = enemyTeam->chooseVictim(getLeader());
				if (victimIdx == -1) { 
					return;
				}
			}
			// If the attacker is a cowboy and alive
			if (getFighter(i)->getIsCowboy() && getFighter(i)->isAlive()) {
				if (getFighter(i)->hasboolets()) { 
					getFighter(i)->shoot(enemyTeam->getFighter(victimIdx));
				}
				else {
					getFighter(i)->reload();
				}
			}
			// If the attacker is a ninja and alive
			if (!getFighter(i)->getIsCowboy() && getFighter(i)->isAlive()) {
				if (getFighter(i)->distance(enemyTeam->getFighter(victimIdx)) < 1) {
					getFighter(i)->slash(enemyTeam->getFighter(victimIdx));	
				}
				else {
					getFighter(i)->move(enemyTeam->getFighter(victimIdx));
				}
				
			}
		}
	}
	// This function return the idx of the closest alive character to the leader of the SAME team
	int Team2::getClosestChar() {
		double closestFighterDist = numeric_limits<double>::max();
		int closestFighterIdx = -1;
		for (int i = 1; i < getVecSize(); i++) {
			// Check if: 1)The character is alive. 2)The distance between the character and the leader is less then the previous characters that got checked. 3)The character is not the leader
			if(getFighter(i)->isAlive() && getFighter(i)->distance(getLeader()) <  closestFighterDist && getFighter(i) != getLeader()) {
				closestFighterIdx = i;
				closestFighterDist = getFighter(i)->distance(getLeader());
			}
		}
		return closestFighterIdx;
	}
	
	// This function return the idx of the closest character to the leader of the OTHER team
    	int Team2::chooseVictim(Character* leader) {
    		double closestVictimDist = numeric_limits<double>::max();
		int victimIdx = -1;
		for (int i = 0; i < getVecSize(); i++) {
			if (getFighter(i)->isAlive() && leader->distance(getFighter(i)) < closestVictimDist) {
				victimIdx = i;
				closestVictimDist = leader->distance(getFighter(i));
			}
		}
		return victimIdx;
    	}
	
	void Team2::print() {
		for (int i = 0; i < getVecSize(); i++) {
			cout << getFighter(i)->print() << endl;
		}
	}
}
