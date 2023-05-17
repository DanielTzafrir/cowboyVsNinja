#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" 
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"
using namespace ariel;


int main() {
	Point a(32.3,44), b(1.3,3.5), c(5.6, 3.4), d(12.5,56.5);

	Cowboy* tom = new Cowboy("Tom", a);
	OldNinja* Mi = new OldNinja("Mi", b);
	YoungNinja* Yuo = new YoungNinja("Yuo", c);
	TrainedNinja* Phang = new TrainedNinja("Phang", d);
	
	tom->shoot(Mi);
	cout << tom->print() <<endl;

	Mi->move(tom);
	Mi->slash(tom);

	Team team_A(tom); 
	team_A.add(new YoungNinja("Yogi", Point(64,57)));

	Team2 team_B(Mi);
	team_B.add(new TrainedNinja("Hikari", Point(12,81)));
	
	SmartTeam team_C(Yuo);
	team_C.add(Phang);
	
	int i = 1;
	
	while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
	team_A.attack(&team_B);
	team_B.attack(&team_A);
	cout << "Team A: " << endl;
	team_A.print();
	cout << "Team B: " << endl;
	team_B.print();
	cout << "Round " << i << " is finished" << endl;
	cout << "-----------------------------" << endl;
	i++;
	}
	
	cout << "The fight between Team A and B is over" << endl;
	
	i = 1;
	
	while(team_C.stillAlive() > 0 && team_B.stillAlive() > 0){
	team_A.attack(&team_B);
	team_B.attack(&team_C);
	cout << "Team c: " << endl;
	team_C.print();
	cout << "Team B: " << endl;
	team_B.print();
	cout << "Round " << i << " is finished" << endl;
	cout << "-----------------------------" << endl;
	i++;
	}
	
	cout << "The fight between Team C and B is over" << endl;
	
	if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
	else cout << "winner is team_B" << endl;

	return 0; 

}
