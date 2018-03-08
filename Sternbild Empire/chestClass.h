#pragma once

#include <string>

using namespace std;

class chestClass
{
public:
	chestClass();
	~chestClass();
	chestClass(int, int, int);

	void updatePlayerStats(int, int, int, string, string);
	int newHealth();
	int newStrength();
	int newSpeed();
	string newSword();
	string newArmour();

	string potionDecision(string);
	string inventoryDecision(string);

	void start(string);

	int playerHealth;
	int playerStrength;
	int playerSpeed;
	string playerSwordType;
	string playerArmourType;
};

