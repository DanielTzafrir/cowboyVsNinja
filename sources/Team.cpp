#include "Team.hpp"
#include <limits>

namespace ariel {

	Team::Team(Character* leader) : fighters_(), vecSize_(0), numOfFighters_(1) { 
		if (leader->getIsInTeam()) { throw runtime_error("already in a team"); }
		leader_ = leader;
		fighters_.push_back(leader_);
		leader->setIsInTeam(true);
		vecSize_++;
	}
	
	void Team::add(Character* fighter) {
		if (fighter->getIsInTeam()) { throw runtime_error("already in a team"); } 
		if (numOfFighters_ < 10) {
			fighters_.push_back(fighter);
			numOfFighters_++;
			fighter->setIsInTeam(true);
			vecSize_++;	
		}
		else { throw runtime_error("There is no room for another member, have 10 members"); } // Should throw an error
	}
	
	void Team::attack(Team* enemyTeam) {
		if (enemyTeam == nullptr) { throw invalid_argument("Sent as argument null pointer"); }
		if (enemyTeam->stillAlive() <= 0) { throw runtime_error("No one is alive on the enemy team. cant attack them."); }
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
		}
		for (int i = 0; i < getVecSize(); i++) {
			if (!enemyTeam->getFighter(victimIdx)->isAlive()) {
				victimIdx = enemyTeam->chooseVictim(getLeader());
				if (victimIdx == -1) { 
					return;
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
	int Team::getClosestChar() {
		double closestFighterDist = numeric_limits<double>::max();
		int closestFighterIdx = -1;
		for (int i = 1; i < getVecSize(); i++) {
			// Check if: 1)The character is a cowboy 2)The character is alive. 3)The distance between the character and the leader is less then the previous characters that got checked. 4)The character is not the leader
			if(getFighter(i)->getIsCowboy() && getFighter(i)->isAlive() && getFighter(i)->distance(getLeader()) <  closestFighterDist && getFighter(i) != getLeader()) {
				closestFighterIdx = i;
				closestFighterDist = getFighter(i)->distance(getLeader());
			}
		}
		for (int i = 1; i < getVecSize(); i++) {
			// Check if: 1)The character is a ninja 2)The character is alive. 3)The distance between the character and the leader is less then the previous characters that got checked. 4)The character is not the leader
			if(!getFighter(i)->getIsCowboy() && getFighter(i)->isAlive() && getFighter(i)->distance(getLeader()) <  closestFighterDist && getFighter(i) != getLeader()) {
				closestFighterIdx = i;
				closestFighterDist = getFighter(i)->distance(getLeader());
			}
		}
		return closestFighterIdx;
	}
	
	// This function return the idx of the closest character to the leader of the OTHER team
    	int Team::chooseVictim(Character* leader) {
    		double closestVictimDist = numeric_limits<double>::max();
		int victimIdx = -1;
		for (int i = 0; i < getVecSize(); i++) {
			if (getFighter(i)->getIsCowboy() && getFighter(i)->isAlive() && leader->distance(getFighter(i)) < closestVictimDist) {
				victimIdx = i;
				closestVictimDist = leader->distance(getFighter(i));
			}
		}
		for (int i = 0; i < getVecSize(); i++) {
			if (!getFighter(i)->getIsCowboy() && getFighter(i)->isAlive() && leader->distance(getFighter(i)) < closestVictimDist) {
				victimIdx = i;
				closestVictimDist = leader->distance(getFighter(i));
			}
		}
		return victimIdx;
    	}
	
	int Team::stillAlive() {
		int numAlive = 0;
		for (int i = 0; i < getVecSize(); i++) {
			if (getFighter(i)->getIsCowboy() && getFighter(i)->isAlive()) { numAlive++; }
		}
		for (int i = 0; i < getVecSize(); i++) {
			if (!getFighter(i)->getIsCowboy() && getFighter(i)->isAlive()) { numAlive++; }
		}
		return numAlive;
	}
	
	void Team::print() {
		for (int i = 0; i < getVecSize(); i++) {
			if (getFighter(i)->getIsCowboy()) {
				cout << getFighter(i)->print() << endl;
			}
		}
		for (int i = 0; i < getVecSize(); i++) {
			if (!getFighter(i)->getIsCowboy()) {
				cout << getFighter(i)->print() << endl;
			}
		}
	}
	
	Character* Team::getLeader() { return leader_; }
	
	void Team::setLeader(Character* newLeader) { leader_ = newLeader; }
	
	Character* Team::getFighter(int index) const {
        	if (index >= 0 && index < fighters_.size()) {
            		return fighters_[static_cast<std::vector<Character*>::size_type>(index)];
        	}
        	else {
            		return nullptr;  // Return nullptr if index is out of bounds
        	}
    	}
	
	int Team::getVecSize() { return vecSize_; }
	
	Team::~Team() {
    		for (Character* fighter : fighters_) {
        		delete fighter;
    		}
    		
    		fighters_.clear();
	}
	
	int Team::getNumOfFighters() { return numOfFighters_; }
							
	void Team::setNumOfFighters(int newNumOfFighters) { numOfFighters_ = newNumOfFighters; }
} 
