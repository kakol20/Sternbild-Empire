#include "stdafx.h"
#include "boss.h"
#include <string>
#include <ctime>
#include <iostream>
#include <random>
#include <algorithm>
#include <Windows.h>

using namespace std;

boss::boss()
{
}


boss::~boss()
{
}

boss::boss(string a, int b, int c) {
	name = a;
	playerHealth = b;
	playerStrength = c; // sets local variables
}

void boss::updatePlayerStats(int a, int b) { // updates made in main.cpp
	playerHealth = a;
	playerStrength = b;
}

void boss::fight() {
	srand(time(0));
	int roll = rand() % playerStrength + 1; // generates a number between 1 and the player's strength
	cout << "Rolling: "; 

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 0x0C);

	cout << std::to_string(roll) << endl;

	SetConsoleTextAttribute(hConsole, 0x0F);

	if (roll >= strength) { // if the number is greater than the boss' strength then they win
		cout << "You have won against the " + name + " boss!" << endl;
	}
	else {
		playerHealth--;
		cout << "You have lost against the " + name + " boss, and you lose 1HP" << endl;

		if (playerHealth > 0) {
			cout << "Do you want to continue figthing or quit? [fight] or [quit] ";
			string input;
			cin >> input;

			input = decision(input);
			if (input == "fight") {
				cout << " " << endl;
				fight();
			}
			else if (input == "quit") {
				playerHealth = -1; // sets player health to < 0 so the gameOver() function in main.cpp knows that the player decided to quit
			}
		}
	}
}

string boss::decision(string a) {
	transform(a.begin(), a.end(), a.begin(), ::tolower);

	if (a == "fight" || a == "quit") { // checks if the input was valid
		return a;
	}
	else {
		cout << "Invalid input, please type it again. [fight] or [quit]" << endl;
		string input;
		cin >> input;
		return decision(input);
	}
}

int boss::updatePlayerHealth() {
	return playerHealth;
}

void boss::start() {
	srand(time(0));
	strength = rand() % 6 + 10; // generates a number between 10 and 16
	cout << "There is a " + name + " boss, and it's blocking the way into the town. It has " + std::to_string(strength) + " strength." << endl << endl;

	fight();
}