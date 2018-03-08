#include "stdafx.h"
#include "monster.h"
#include <algorithm>
#include <iostream>
#include <ctime>
#include <random>
#include <string>
#include <Windows.h>

using namespace std;

monster::monster()
{
}

monster::monster(string a, int b, int c, int d, int e, int f) {
	name = a;
	strength = b;
	speed = c;

	playerHealth = d;
	playerSpeed = e;
	playerStrength = f; // sets local variables
}

monster::~monster(void)
{
}

void monster::start() {
	cout << "There is a " + name + ", it has " + std::to_string(strength) + " strength and " + std::to_string(speed) + " speed" << endl; // sets all letters to lower case

	if (name == "alpha wolf") { // checks monster's name
		cout << "You see that there is a health potion behind it" << endl;
	}

	cout << "Do you want to [fight] or [run]? ";
	string decision;
	cin >> decision;

	decision = fightRun(decision);
	if (decision == "fight") { // checks input
		cout << " " << endl;
		fight();
	}
	else if (decision == "run") {
		cout << " " << endl;
		run();
	}
}

void monster::changeStats(int a, int b) { // changes the monster's stats
	strength = a;
	speed = b;
}

void monster::updatePlayerStats(int a, int b, int c) { // updates the player#s stats
	playerHealth = a;
	playerSpeed = b;
	playerStrength = c;
}

int monster::newHealth() { // returns the player's new health value
	return playerHealth;
}

string monster::fightRun(string a) {
	transform(a.begin(), a.end(), a.begin(), ::tolower);

	if (a == "fight" || a == "run") {
		return a;
	}
	else {
		cout << "Invalid input, please type it again. [fight] or [run] ";
		string decision;
		cin >> decision;
		return fightRun(decision); // calls itself
	}
}

void monster::fight() {
	srand(time(0));
	int roll = rand() % playerStrength + 1; // randomises a number between 1 and the player's strength value
	cout << "Rolling: "; 

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 0x0C); // sets text colour to red

	cout << std::to_string(roll) << endl;

	SetConsoleTextAttribute(hConsole, 0x0F); // set text colour back to white

	if (roll >= strength) { // if the number is greater than the monster's strength then they win
		cout << "You have won against the " + name + "." << endl;

		if (name == "alpha wolf") {
			cout << " " << endl;
			cout << "You get the health potion and you drink it" << endl;
			cout << "It gives you 10 health" << endl;
			playerHealth = playerHealth + 10;
		}
	}
	else {
		playerHealth--;
		cout << "You have lost against the " + name + " and you lose 1HP." << endl;

		if (playerHealth > 0) {
			cout << "Do you want to continue fighting " + name + "? [fight] or [run] ";
			string decision;
			cin >> decision;

			if (fightRun(decision) == "fight") {
				cout << " " << endl;
				fight();
			}
			else if (fightRun(decision) == "run") {
				cout << " " << endl;
				run();
			}
		}
	}
}

void monster::run() {
	srand(time(0));
	int roll = rand() % playerSpeed + 1;
	cout << "Rolling: ";

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 0x0C); // sets text colour to red

	cout << std::to_string(roll) << endl; // generates random number between 1 and the player's strength

	SetConsoleTextAttribute(hConsole, 0x0F); // set text colour back to white

	if (roll >= speed) { // if the roll is greater than the monster's speed they win
		cout << "You have successfully ran from the " + name + "." << endl;
	}
	else {
		cout << "You have successfully ran from the " + name + ", but you lost 2HP." << endl;
		playerHealth = playerHealth - 2;
	}
}