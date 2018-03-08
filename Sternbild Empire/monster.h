#pragma once
#include <string>

using namespace std;

class monster
{
public:
	monster();
	monster(string, int, int, int, int, int);
	~monster(void);

	string name;
	int speed;
	int strength;

	string playerPosition;
	int playerHealth;
	int playerSpeed;
	int playerStrength;

	void start();
	void changeStats(int, int);
	void updatePlayerStats(int, int, int);
	int newHealth();

	string fightRun(string);
	void fight();
	void run();
};