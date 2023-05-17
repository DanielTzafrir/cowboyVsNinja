#include "doctest.h"

#include "sources/Character.hpp"
#include "sources/OldNinja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
//#include <random>
//#include <chrono>

using namespace ariel;

TEST_SUITE("Point class tests") {
	Point p1{1, 1};
    	Point p2{2, 3};
    	
    	TEST_CASE("Distance method") {
	    	CHECK_EQ(p1.distance(p2), p2.distance(p1));
		CHECK_EQ(p1.distance(p1), 0);
    	}   	   	
}

TEST_SUITE("Classes initialization") {
	TEST_CASE("Cowboy initialization") {
		Cowboy cowboy{"Bob", Point{5, 8}};
		CHECK(cowboy.hasboolets());
		CHECK_EQ(cowboy.getName(), "Bob");
		CHECK_EQ(cowboy.getLocation().distance(Point{5, 8}), 0);
		CHECK_NE(cowboy.getLocation().distance(Point{9, 3}), 0);

		CHECK(cowboy.isAlive());
    	}
    
    	TEST_CASE("YoungNinja initialization") {
		YoungNinja ninja{"Bob", Point{5, 8}};
		CHECK_EQ(ninja.getName(), "Bob");
		CHECK_EQ(ninja.getLocation().distance(Point{5, 8}), 0);
		CHECK_NE(ninja.getLocation().distance(Point{9, 3}), 0);

		CHECK(ninja.isAlive());
	}
	
	TEST_CASE("OldNinja initialization") {
		OldNinja old_ninja{"Bob", Point(5, 8)};
		CHECK_EQ(old_ninja.getName(), "Bob");
		CHECK_EQ(old_ninja.getLocation().distance(Point{5, 8}), 0);
		CHECK_NE(old_ninja.getLocation().distance(Point{9, 3}), 0);

		CHECK(old_ninja.isAlive());
	}

	TEST_CASE("TrainedNinja initialization") {
		TrainedNinja trained_ninja{"Bob", Point{5, 8}};
		CHECK_EQ(trained_ninja.getName(), "Bob");
		CHECK_EQ(trained_ninja.getLocation().distance(Point{5, 8}), 0);
		CHECK_NE(trained_ninja.getLocation().distance(Point{9, 3}), 0);

		CHECK(trained_ninja.isAlive());
	}
}

TEST_CASE("Team functions"){
	Point a(1.3,4.5), b(2.7,3.2), c(5.1,2.9);

	// Create characters
	Cowboy* cowboy1 = new Cowboy("John", a);
	TrainedNinja* ninja1 = new TrainedNinja("Mike", b);
	OldNinja* ninja2 = new OldNinja("Tom", c);

	// Create a team
	Team teamA(cowboy1);

	// Add characters to team A
	CHECK_NOTHROW(teamA.add(ninja1));
	CHECK_NOTHROW(teamA.add(ninja2));

	// Create characters for team B
	YoungNinja* ninja3 = new YoungNinja("Steve", c);
	Cowboy* cowboy5 = new Cowboy("Mark", b);

	// Create another team
	Team teamB(ninja3);
	
	// Add character to team B
	CHECK_NOTHROW(teamB.add(cowboy5));
	
	// Check how many alive in the teams
	CHECK_EQ(teamA.stillAlive(), 3);
	CHECK_EQ(teamB.stillAlive(), 2);
	
	// Team A attacks Team B
	CHECK_NOTHROW(teamA.attack(&teamB));
	
	// Check who is the leader
	CHECK_EQ(teamA.getLeader(), cowboy1);
	CHECK_EQ(teamB.getLeader(), ninja3);
}
