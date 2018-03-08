#pragma once

#include <string>

using namespace std;

class boss
{
public:
	boss();
	~boss();
	boss(string, int, int);

	string name;
	int playerHealth;
	int playerStrength;
	int strength;

	void updatePlayerStats(int, int);
	void fight();
	string decision(string);
	int updatePlayerHealth();

	void start();
};