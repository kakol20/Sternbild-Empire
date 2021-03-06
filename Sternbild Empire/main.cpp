// Sternbild Empire
//

#include "stdafx.h"
#include "monster.h"
#include "map.h"
#include "chestClass.h"
#include "boss.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <Windows.h>

using namespace std;

// Time
time_t time(time_t * timer);
time_t gameStart, gameEnd;
int dif;

string temp;

string input;
string name;
int health;
int strength;
int speed;
string swordType = "none";
string armourType = "none";

int discoveredGrids;
string position;

struct player {
	string playerName;
	int score;
} allPlayers[30];
int timesPlayed = 0;
string tempName;
int tempScore;

map mapFunction;

void displayStats();
string checkGameOverInput(string a);
void gameOver();
bool endProgram = false;
int start();

monster wolf("wolf", 6, 12, health, speed, strength);
void wolfFunction();

monster alphaWolf("alpha wolf", 8, 14, health, speed, strength);
void alphaWolfFunction();

monster bandit("bandit", 10, 10, health, speed, strength);
void banditFunction();

monster goblin("goblin", 10, 5, health, speed, strength);
void goblinFunction();

chestClass chest(health, speed, strength);
void chestFunction();

boss banditBoss("bandit", health, strength);
void banditBossFunction();

boss goblinBoss("goblin", health, strength);
void goblinBossFunction();

int main()
{
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hconsole, 0x0E); // changes text colour to yellow

	int delay = 100; // typing animation
	system("cls");
	cout << "W";
	Sleep(delay);
	system("cls");
	cout << "We";
	Sleep(delay);
	system("cls");
	cout << "Wel";
	Sleep(delay);
	system("cls");
	cout << "Welc";
	Sleep(delay);
	system("cls");
	cout << "Welco";
	Sleep(delay);
	system("cls");
	cout << "Welcom";
	Sleep(delay);
	system("cls");
	cout << "Welcome";
	Sleep(delay);
	system("cls");
	cout << "Welcome ";
	Sleep(delay);
	system("cls");
	cout << "Welcome t";
	Sleep(delay);
	system("cls");
	cout << "Welcome to";
	Sleep(delay);
	system("cls");
	cout << "Welcome to ";
	Sleep(delay);
	system("cls");
	cout << "Welcome to S";
	Sleep(delay);
	system("cls");
	cout << "Welcome to St";
	Sleep(delay);
	system("cls");
	cout << "Welcome to Ste";
	Sleep(delay);
	system("cls");
	cout << "Welcome to Ster";
	Sleep(delay);
	system("cls");
	cout << "Welcome to Stern";
	Sleep(delay);
	system("cls");
	cout << "Welcome to Sternb";
	Sleep(delay);
	system("cls");
	cout << "Welcome to Sternbi";
	Sleep(delay);
	system("cls");
	cout << "Welcome to Sternbil";
	Sleep(delay);
	system("cls");
	cout << "Welcome to Sternbild";
	Sleep(delay);
	system("cls");
	cout << "Welcome to Sternbild ";
	Sleep(delay);
	system("cls");
	cout << "Welcome to Sternbild E";
	Sleep(delay);
	system("cls");
	cout << "Welcome to Sternbild Em";
	Sleep(delay);
	system("cls");
	cout << "Welcome to Sternbild Emp";
	Sleep(delay);
	system("cls");
	cout << "Welcome to Sternbild Empi";
	Sleep(delay);
	system("cls");
	cout << "Welcome to Sternbild Empir";
	Sleep(delay);
	system("cls");
	cout << "Welcome to Sternbild Empire";
	Sleep(delay);
	system("cls");
	cout << "Welcome to Sternbild Empire" << endl;
	cout << "By Adrian" << endl << endl;

	cout << "Instructions: " << endl;
	cout << "- Once you have discovered a grid, you can come back to it, but you can't replay it " << endl << endl;

	SetConsoleTextAttribute(hconsole, 0x0F); // sets it back to white

	system("PAUSE");

	return start();
}

void displayStats() {
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hconsole, 0x0B); // changes text colour to cyan

	cout << "Health: " + std::to_string(health) << endl;
	cout << "Strength: " + std::to_string(strength) << endl;
	cout << "Speed: " + std::to_string(speed) << endl;
	cout << "Sword: " + swordType << endl;
	cout << "Armour: " + armourType << endl;

	SetConsoleTextAttribute(hconsole, 0x0F); // sets it back to white
}

string checkGameOverInput(string a) {
	transform(a.begin(), a.end(), a.begin(), ::tolower);

	if (a == "yes" || a == "no") { // checks if the cin is valid
		return a;
	}
	else {
		cout << "Invalid input, please type it again. [yes] or [no] ";
		cin >> a;

		return checkGameOverInput(a);
	}
}

void gameOver() {
	system("cls");

	// Sort and show leaderboard

	time(&gameEnd);

	if (health <= 0) {
		cout << "Game Over! You have died!" << endl << endl;
	}
	else if (health > 0) {
		cout << "Congratulations! You have won!" << endl << endl;
		dif = difftime(gameEnd, gameStart);
		allPlayers[timesPlayed].playerName = name;
		allPlayers[timesPlayed].score = dif;
		timesPlayed++; // adds player to struct if they have won
	}

	if (timesPlayed == 1) {
		temp = allPlayers[0].playerName + ": " + std::to_string(allPlayers[0].score) + "s";
		cout << temp << endl;
	}
	else {
		// Bubble Sort
		for (int i = 0; i < timesPlayed - 1; i++) {
			for (int j = 0; j < timesPlayed - 1; j++) {
				if (allPlayers[j].score > allPlayers[j + 1].score) {
					tempName = allPlayers[j].playerName;
					tempScore = allPlayers[j].score;

					allPlayers[j].playerName = allPlayers[j + 1].playerName;
					allPlayers[j].score = allPlayers[j + 1].score;

					allPlayers[j + 1].playerName = tempName;
					allPlayers[j + 1].score = tempScore;
				}
			}
		}

		for (int i = 0; i < timesPlayed; i++) {
			temp = allPlayers[i].playerName + ": " + std::to_string(allPlayers[i].score) + "s";
			cout << temp << endl;
		}
	}

	cout << " " << endl;
	cout << "Play again? [yes] or [no] " << endl;
	cin >> input;
	input = checkGameOverInput(input);
	if (input == "yes") {
		start();
	}
	else if (input == "no") {
		cout << " " << endl;
		cout << "Thank you for playing!" << endl << endl;

		system("PAUSE");

		endProgram = true;
		start();
	}
}

int start() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 0x0F);

	if (!endProgram) { // checks if the player decides to not play again or not
		discoveredGrids = 0;
		swordType = "none";
		armourType = "none";

		system("cls");

		cout << "What is your name? " << endl;
		cin >> name;
		transform(name.begin(), name.end(), name.begin(), ::toupper); // changes all letters to upper case

		cout << " " << endl;

		time(&gameStart);

		health = 20;
		strength = 10;
		speed = 10;
		position = "C3";

		mapFunction.addDiscoveredList("C3", 0);
		discoveredGrids++;

		cout << "You find yourself lying on the floor, on top of some weird circular drawings." << endl;
		cout << "You are wearing some rags" << endl;
		cout << "You don't know where you are." << endl;
		cout << "You decide to find the nearest town." << endl << endl;

		displayStats();
		cout << " " << endl;

		cout << "There are two bridges, both of which is glowing, one heading [east], and the other heading [west]." << endl;
		cout << "Which direction do you want to go? ";
		cin >> input;

		input = mapFunction.decision(input, 2, "east", "west");

		if (input == "east") {
			cout << "The two bridges lose their glow and they both collapse.";

			mapFunction.animation("east", "B2", "B3", "B4", "C2", "C3", "C4", "D2", "D3", "D4", "E2", "E3", "E4", discoveredGrids); // go to room D3

			position = "D3";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			goblinFunction();
		}
		else if (input == "west") {
			cout << "The two bridges lose their glow and they both collapse.";

			mapFunction.animation("west", "A2", "A3", "A4", "B2", "B3", "B4", "C2", "C3", "C4", "D2", "D3", "D4", discoveredGrids); // go to room B3
			position = "B3";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			wolfFunction();
		}
	}
	return 0;
}
// ----------------------------------------------------------------------------------------------------------------
void wolfFunction() {
	if (position == "B3") { // checks player ppsition
		if (mapFunction.isDiscovered("B3", discoveredGrids) == "?") { // checks if the player has discovered the area if they have, they cannot replay it
			mapFunction.addDiscoveredList("B3", discoveredGrids); // adds to list of discovered areas
			discoveredGrids++;

			wolf.changeStats(6, 12); // change variables inside monster class - each grid has a different set amount of strength and speed values
			wolf.updatePlayerStats(health, speed, strength);  // update the player varibles inside the class
			wolf.start();
			health = wolf.newHealth();  // updates player's health for main.cpp

			cout << " " << endl;
			displayStats(); // display stats and inventory
			cout << " " << endl;
		}

		if (health <= 0) {
			gameOver();
		}

		cout << "There are two roads, one heading [north] and the other heading [west]" << endl;
		cout << "Which direction do you want to go? ";
		cin >> input;

		input = mapFunction.decision(input, 2, "north", "west"); // checks validity of cin
		if (input == "north") {
			mapFunction.animation("north", "A1", "A2", "A3", "A4", "B1", "B2", "B3", "B4", "C1", "C2", "C3", "C4", discoveredGrids); // go to room B2
			position = "B2";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			chestFunction(); // calls the area that the player has decided to go to
		}
		else if (input == "west") {
			mapFunction.animation("west", "  ", "  ", "  ", "A2", "A3", "A4", "B2", "B3", "B4", "C2", "C3", "C4", discoveredGrids); // go to room A3
			position = "A3";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			alphaWolfFunction();
		}
	} // ----------------------------------------------------------------------------------------------------------------
	else if (position == "B1") {
		if (mapFunction.isDiscovered("B1", discoveredGrids) == "?") {
			mapFunction.addDiscoveredList("B1", discoveredGrids);
			discoveredGrids++;

			wolf.changeStats(5, 10);
			wolf.updatePlayerStats(health, speed, strength);
			wolf.start();
			health = wolf.newHealth();

			cout << " " << endl;
			displayStats();
			cout << " " << endl;
		}

		if (health <= 0) {
			gameOver();
		}

		cout << "There are three roads, one heading [east], one heading [south] and the other heading [west]" << endl;
		cout << "Which direction do you want to go? ";
		cin >> input;

		input = mapFunction.decision(input, 3, "east", "south", "west");
		if (input == "east") {
			mapFunction.animation("east", "  ", "A1", "A2", "  ", "B1", "B2", "  ", "C1", "C2", "  ", "D1", "D2", discoveredGrids); // go to room C1
			position = "C1";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			chestFunction();
		}
		else if (input == "south") {
			mapFunction.animation("south", "  ", "A1", "A2", "A3", "  ", "B1", "B2", "B3", "  ", "C1", "C2", "C3", discoveredGrids); // go to room B2
			position = "B2";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			chestFunction();
		}
		else if (input == "west") {
			mapFunction.animation("west", "  ", "  ", "  ", "  ", "A1", "A2", "  ", "B1", "B2", "  ", "C1", "C2", discoveredGrids); // go to room A1
			position = "A1";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			banditFunction();
		}
	} // ----------------------------------------------------------------------------------------------------------------
	else if (position == "C4") {
		if (mapFunction.isDiscovered("C4", discoveredGrids) == "?") {
			mapFunction.addDiscoveredList("C4", discoveredGrids);
			discoveredGrids++;

			wolf.changeStats(7, 9);
			wolf.updatePlayerStats(health, strength, speed);
			wolf.start();
			health = wolf.newHealth();

			cout << " " << endl;
			displayStats();
			cout << " " << endl;
		}

		if (health <= 0) {
			gameOver();
		}

		cout << "There are three roads, one heading [east], one heading [south], and the other heading [west]" << endl;
		cout << "Which direction do you want to go? ";
		cin >> input;

		input = mapFunction.decision(input, 3, "east", "south", "west");
		if (input == "east") {
			mapFunction.animation("west", "B3", "B4", "B5", "C3", "C4", "C5", "D3", "D4", "D5", "E3", "E4", "E5", discoveredGrids); // go to room D4
			position = "D4";

			cout << " " << endl;
			displayStats();
			cout << endl;

			chestFunction();
		}
		else if (input == "south") {
			mapFunction.animation("south", "B3", "B4", "B5", "  ", "C3", "C4", "C5", "  ", "D3", "D4", "D5", "  ", discoveredGrids); // go to room C5
			position = "C5";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			chestFunction();
		}
		else if (input == "west") {
			mapFunction.animation("west", "A3", "A4", "A5", "B3", "B4", "B5", "C3", "C4", "C5", "D3", "D4", "D5", discoveredGrids); // go to room B4
			position = "B4";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			banditFunction();
		}
	} // ----------------------------------------------------------------------------------------------------------------
	else if (position == "E4") {
		if (mapFunction.isDiscovered("E4", discoveredGrids) == "?") {
			mapFunction.addDiscoveredList("E4", discoveredGrids);
			discoveredGrids++;

			wolf.changeStats(5, 10);
			wolf.updatePlayerStats(health, strength, speed);
			wolf.start();
			health = wolf.newHealth();

			cout << " " << endl;
			displayStats();
			cout << " " << endl;
		}

		if (health <= 0) {
			gameOver();
		}

		cout << "There are two roads, one heaging [north], and the other heading [south]" << endl;
		cout << "Which direction do you want to go? ";
		cin >> input;

		input = mapFunction.decision(input, 2, "north", "south");
		if (input == "north") {
			mapFunction.animation("north", "D2", "D3", "D4", "D5", "E2", "E3", "E4", "E5", "  ", "  ", "  ", "  ", discoveredGrids); // go to room E3
			position = "E3";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			chestFunction();
		}
		else if (input == "south") {
			mapFunction.animation("south", "D3", "D4", "D5", "  ", "E3", "E4", "E5", "  ", "  ", "  ", "  ", "  ", discoveredGrids); // go to room E5
			position = "E5";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			banditFunction();
		}
	}
}
// ----------------------------------------------------------------------------------------------------------------
void alphaWolfFunction() {
	if (mapFunction.isDiscovered("A3", discoveredGrids) == "?") {
		mapFunction.addDiscoveredList("A3", discoveredGrids);
		discoveredGrids++;

		alphaWolf.updatePlayerStats(health, speed, strength);
		alphaWolf.start();
		health = alphaWolf.newHealth();

		cout << " " << endl;
		displayStats();
		cout << " " << endl;
	}

	if (health <= 0) {
		gameOver();
	}

	cout << "There are three roads, one heading [north], one heading [east], and the other heading [south]" << endl;
	cout << "Which direction do you want to go? ";
	cin >> input;

	input = mapFunction.decision(input, 3, "north", "east", "south");
	if (input == "north") {
		mapFunction.animation("north", "  ", "  ", "  ", "  ", "A1", "A2", "A3", "A4", "B1", "B2", "B3", "B4", discoveredGrids); // go to room A2
		position = "A2";

		cout << " " << endl;
		displayStats();
		cout << " " << endl;

		chestFunction();
	}
	else if (input == "east") {
		mapFunction.animation("east", "  ", "  ", "  ", "A2", "A3", "A4", "B2", "B3", "B4", "C2", "C3", "C4", discoveredGrids); // go to room B3
		position = "B3";

		cout << " " << endl;
		displayStats();
		cout << " " << endl;

		wolfFunction();
	}
	else if (input == "south") {
		mapFunction.animation("south", "  ", "  ", "  ", "  ", "A2", "A3", "A4", "A5", "B2", "B3", "B4", "B5", discoveredGrids); // go to room A4
		position = "A4";

		cout << " " << endl;
		displayStats();
		cout << " " << endl;

		chestFunction();
	}
}
// ----------------------------------------------------------------------------------------------------------------
void banditFunction() {
	if (position == "A1") {
		if (mapFunction.isDiscovered("A1", discoveredGrids) == "?") {
			mapFunction.addDiscoveredList("A1", discoveredGrids);
			discoveredGrids++;

			bandit.changeStats(8, 10);
			bandit.updatePlayerStats(health, strength, speed);
			bandit.start();
			health = bandit.newHealth();

			cout << " " << endl;
			displayStats();
			cout << " " << endl;
		}

		if (health <= 0) {
			gameOver();
		}

		cout << "There are two roads, one heading [east], the other heading [south]" << endl;
		cout << "Which direction do you want to go? ";
		cin >> input;

		input = mapFunction.decision(input, 2, "east", "south");
		if (input == "east") {
			mapFunction.animation("east", "  ", "  ", "  ", "  ", "A1", "A2", "  ", "B1", "B2", "  ", "C1", "C2", discoveredGrids); // go to room B1
			position == "B1";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			wolfFunction();
		}
		else if (input == "south") {
			mapFunction.animation("south", "  ", "  ", "  ", "  ", "  ", "A1", "A2", "A3", "  ", "B1", "B2", "B3", discoveredGrids); // go to room A2
			position = "A2";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			chestFunction();
		}
	}// ----------------------------------------------------------------------------------------------------------------
	else if (position == "B4") {
		if (mapFunction.isDiscovered("B4", discoveredGrids) == "?") {
			mapFunction.addDiscoveredList("B4", discoveredGrids);
			discoveredGrids++;

			bandit.changeStats(8, 7);
			bandit.updatePlayerStats(health, strength, speed);
			bandit.start();
			health = bandit.newHealth();

			cout << " " << endl;
			displayStats();
			cout << " " << endl;
		}

		if (health <= 0) {
			gameOver();
		}

		cout << "There two roads, one heading [east], and the other [west]" << endl;
		cout << "Which direction do you want to go? ";
		cin >> input;

		input = mapFunction.decision(input, 2, "east", "west");
		if (input == "east") {
			mapFunction.animation("east", "A3", "A4", "A5", "B3", "B4", "B5", "C3", "C4", "C5", "D3", "D4", "D5", discoveredGrids); // go to room C4
			position = "C4";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			wolfFunction();
		}
		else if (input == "west") {
			mapFunction.animation("west", "  ", "  ", "  ", "A3", "A4", "A5", "B3", "B4", "B5", "C3", "C4", "C5", discoveredGrids); // go to room A4
			position = "A4";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			chestFunction();
		}
	} // ----------------------------------------------------------------------------------------------------------------
	else if (position == "B5") {
		if (mapFunction.isDiscovered("B5", discoveredGrids) == "?") {
			mapFunction.addDiscoveredList("B5", discoveredGrids);
			discoveredGrids++;

			bandit.changeStats(8, 7);
			bandit.updatePlayerStats(health, strength, speed);
			bandit.start();
			health = bandit.newHealth();

			cout << " " << endl;
			displayStats();
			cout << " " << endl;
		}
		if (health <= 0) {
			gameOver();
		}

		cout << "There two roads, one heading [east], and the other heading [west]" << endl;
		cout << "Which direction do you want to go? ";
		cin >> input;

		input = mapFunction.decision(input, 2, "east", "west");
		if (input == "east") {
			mapFunction.animation("east", "A4", "A5", "  ", "B4", "B5", "  ", "C4", "C5", "  ", "D4", "D5", "  ", discoveredGrids);
			position = "C5";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			chestFunction();
		}
		else if (input == "west") {
			mapFunction.animation("west", "  ", "  ", "  ", "A4", "A5", "  ", "B4", "B5", "  ", "C4", "C5", "  ", discoveredGrids);
			position = "A5";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			goblinFunction();
		}
	} // ----------------------------------------------------------------------------------------------------------------
	else if (position == "E5") {
		if (mapFunction.isDiscovered("E5", discoveredGrids) == "?") {
			mapFunction.addDiscoveredList("E5", discoveredGrids);
			discoveredGrids++;

			bandit.changeStats(8, 9);
			bandit.updatePlayerStats(health, strength, speed);
			bandit.start();
			health = bandit.newHealth();

			cout << " " << endl;
			displayStats();
			cout << " " << endl;
		}

		if (health <= 0) {
			gameOver();
		}

		cout << "There are two roads, one heading [north], and the other [west]" << endl;
		cout << "Which direction do you want to go? ";
		cin >> input;

		input = mapFunction.decision(input, 2, "north", "west");
		if (input == "north") {
			mapFunction.animation("north", "D3", "D4", "D5", "  ", "E3", "E4", "E5", "  ", "  ", "  ", "  ", "  ", discoveredGrids);
			position = "E4";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			wolfFunction();
		}
		else if (input == "west") {
			mapFunction.animation("west", "C4", "C5", "  ", "D4", "D5", "  ", "E4", "E5", "  ", "  ", "  ", "  ", discoveredGrids);
			position = "D5";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			goblinFunction();
		}
	}
}
// ----------------------------------------------------------------------------------------------------------------
void goblinFunction() {
	if (position == "C2") {
		if (mapFunction.isDiscovered("C2", discoveredGrids) == "?") {
			mapFunction.addDiscoveredList("C2", discoveredGrids);
			discoveredGrids++;

			goblin.changeStats(8, 5);
			goblin.updatePlayerStats(health, strength, speed);
			goblin.start();
			health = goblin.newHealth();

			cout << " " << endl;
			displayStats();
			cout << " " << endl;
		}

		if (health <= 0) {
			gameOver();
		}

		cout << "There are two roads, one heading [north], and the other heading [east]" << endl;
		cout << "Which direction do you want to go? ";
		cin >> input;

		input = mapFunction.decision(input, 2, "north", "east");
		if (input == "north") {
			mapFunction.animation("north", "  ", "B1", "B2", "B3", "  ", "C1", "C2", "C3", "  ", "D1", "D2", "D3", discoveredGrids);
			position = "C1";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			chestFunction();
		}
		else if (input == "east") {
			mapFunction.animation("east", "B1", "B2", "B3", "C1", "C2", "C3", "D1", "D2", "D3", "E1", "E2", "E3", discoveredGrids);
			position = "D2";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			chestFunction();
		}
	} // ----------------------------------------------------------------------------------------------------------------
	else if (position == "D3") {
		if (mapFunction.isDiscovered("D3", discoveredGrids) == "?") {
			mapFunction.addDiscoveredList("D3", discoveredGrids);
			discoveredGrids++;

			goblin.changeStats(8, 7);
			goblin.updatePlayerStats(health, strength, speed);
			goblin.start();
			health = goblin.newHealth();

			cout << " " << endl;
			displayStats();
			cout << " " << endl;
		}

		if (health <= 0) {
			gameOver();
		}

		cout << "There are two roads, one heading [north], and the other heading [south]" << endl;
		cout << "Which direction do you want to go? ";
		cin >> input;

		input = mapFunction.decision(input, 2, "north", "south");
		if (input == "north") {
			mapFunction.animation("north", "C1", "C2", "C3", "C4", "D1", "D2", "D3", "D4", "E1", "E2", "E3", "E4", discoveredGrids);
			position = "D2";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			chestFunction();
		}
		else if (input == "south") {
			mapFunction.animation("south", "C2", "C3", "C4", "C5", "D2", "D3", "D4", "D5", "E2", "E3", "E4", "E5", discoveredGrids);
			position = "D4";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			chestFunction();
		}
	} // ----------------------------------------------------------------------------------------------------------------
	else if (position == "A5") {
		if (mapFunction.isDiscovered("A5", discoveredGrids) == "?") {
			mapFunction.addDiscoveredList("A5", discoveredGrids);
			discoveredGrids++;

			goblin.changeStats(8, 7);
			goblin.updatePlayerStats(health, speed, strength);
			goblin.start();
			health = goblin.newHealth();

			cout << " " << endl;
			displayStats();
			cout << " " << endl;
		}

		if (health <= 0) {
			gameOver();
		}

		cout << "There are two roads, one heading [north], and the other heading [east]" << endl;
		cout << "Which direction do you want to go? ";
		cin >> input;

		input = mapFunction.decision(input, 2, "north", "east");
		if (input == "north") {
			mapFunction.animation("north", "  ", "  ", "  ", "  ", "A3", "A4", "A5", "  ", "B3", "B4", "B5", "  ", discoveredGrids);
			position = "A4";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			chestFunction();
		}
		else if (input == "east") {
			mapFunction.animation("east", "  ", "  ", "  ", "A4", "A5", "  ", "B4", "B5", "  ", "C4", "C5", "  ", discoveredGrids);
			position = "B5";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			banditFunction();
		}
	} // ----------------------------------------------------------------------------------------------------------------
	else if (position == "D5") {
		if (mapFunction.isDiscovered("D5", discoveredGrids) == "?") {
			mapFunction.addDiscoveredList("D5", discoveredGrids);
			discoveredGrids++;

			goblin.changeStats(7, 7);
			goblin.updatePlayerStats(health, strength, speed);
			goblin.start();
			health = goblin.newHealth();

			cout << " " << endl;
			displayStats();
			cout << " " << endl;
		}

		if (health <= 0) {
			gameOver();
		}

		cout << "There are three roads, one heading [north], one heading [east], and the other heading [west]" << endl;
		cout << "Which direction do you want to go? ";
		cin >> input;

		input = mapFunction.decision(input, 3, "north", "east", "west");
		if (input == "north") {
			mapFunction.animation("north", "C3", "C4", "C5", "  ", "D3", "D4", "D5", "  ", "E3", "E4", "E5", "  ", discoveredGrids);
			position = "D4";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			chestFunction();
		}
		else if (input == "east") {
			mapFunction.animation("east", "C4", "C5", "  ", "D4", "D5", "  ", "E4", "E5", "  ", "  ", "  ", "  ", discoveredGrids);
			position = "E5";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			banditFunction();
		}
		else if (input == "west") {
			mapFunction.animation("west", "B4", "B5", "  ", "C4", "C5", "  ", "D4", "D5", "  ", "E4", "E5", "  ", discoveredGrids);
			position = "C5";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			chestFunction();
		}
	}
}
// ----------------------------------------------------------------------------------------------------------------
void chestFunction() {
	if (position == "D2") {
		if (mapFunction.isDiscovered("D2", discoveredGrids) == "?") {
			mapFunction.addDiscoveredList("D2", discoveredGrids);
			discoveredGrids++;

			chest.updatePlayerStats(health, strength, speed, swordType, armourType);
			chest.start("potion"); // parameter is based on the type of chest (potion or inventory)

			health = chest.newHealth();
			strength = chest.newStrength();
			speed = chest.newSpeed();

			cout << " " << endl;
			displayStats();
			cout << " " << endl;
		}

		cout << " " << endl;
		cout << "There are four roads going in all directions. [north] [east] [south] [west]" << endl;
		cout << "The road going north leads to the Bandit Boss, who is blocking the way into the town, you must fight it to go in the town" << endl;
		cout << "The road going east leads to the Goblin Boss, who is also blocking th way into the town, you must fight it to go in the town" << endl << endl;
		cout << "Which direction do you want to go? ";
		cin >> input;

		input = mapFunction.decision(input, 4, "north", "east", "south", "west");
		if (input == "north") {
			mapFunction.animation("north", "  ", "C1", "C2", "C3", "  ", "D1", "D2", "D3", "  ", "E1", "E2", "E3", discoveredGrids);
			position = "D1";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			banditBossFunction();
		}
		else if (input == "east") {
			mapFunction.animation("east", "C1", "C2", "C3", "D1", "D2", "D3", "E1", "E2", "E3", "  ", "  ", "  ", discoveredGrids);
			position = "E2";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			goblinBossFunction();
		}
		else if (input == "south") {
			mapFunction.animation("south", "C1", "C2", "C3", "C4", "D1", "D2", "D3", "D4", "E1", "E2", "E3", "E4", discoveredGrids);
			position = "D3";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			goblinFunction();
		}
		else if (input == "west") {
			mapFunction.animation("west", "B1", "B2", "B3", "C1", "C2", "C3", "D1", "D2", "D3", "E1", "E2", "E3", discoveredGrids);
			position = "C2";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			goblinFunction();
		}
	} // ----------------------------------------------------------------------------------------------------------------
	else if (position == "D4") {
		if (mapFunction.isDiscovered("D4", discoveredGrids) == "?") {
			mapFunction.addDiscoveredList("D4", discoveredGrids);
			discoveredGrids++;

			chest.updatePlayerStats(health, strength, speed, swordType, armourType);
			chest.start("inventory");

			swordType = chest.newSword();
			strength = chest.newStrength();
			armourType = chest.newArmour();
			health = chest.newHealth();

			cout << " " << endl;
			displayStats();
			cout << " " << endl;
		}

		cout << " " << endl;
		cout << "There are three roads, one going [north], one going [south], and the other going [west]" << endl;
		cout << "Which direction do you want to go? ";
		cin >> input;

		input = mapFunction.decision(input, 3, "north", "south", "west");
		if (input == "north") {
			mapFunction.animation("north", "C2", "C3", "C4", "C5", "D2", "D3", "D4", "D5", "E2", "E3", "E4", "E5", discoveredGrids);
			position = "D3";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			goblinFunction();
		}
		else if (input == "south") {
			mapFunction.animation("south", "C3", "C4", "C5", "  ", "D3", "D4", "D5", "  ", "E3", "E4", "E5", "  ", discoveredGrids);
			position = "D5";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			goblinFunction();
		}
		else if (input == "west") {
			mapFunction.animation("west", "B3", "B4", "B5", "C3", "C4", "C5", "D3", "D4", "D5", "E3", "E4", "E5", discoveredGrids);
			position = "C4";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			wolfFunction();
		}
	} // ----------------------------------------------------------------------------------------------------------------
	else if (position == "C1") {
		if (mapFunction.isDiscovered("C1", discoveredGrids) == "?") {
			mapFunction.addDiscoveredList("C1", discoveredGrids);
			discoveredGrids++;

			chest.updatePlayerStats(health, strength, speed, swordType, armourType);
			chest.start("potion");

			health = chest.newHealth();
			strength = chest.newStrength();
			speed = chest.newSpeed();

			cout << " " << endl;
			displayStats();
			cout << " " << endl;
		}

		cout << " " << endl;
		cout << "There are three roads, one going [east], one going [south], and the other going [west]" << endl;
		cout << "The road going east leads to the Bandit Boss, who is also blocking th way into the town, you must fight it to go in the town" << endl << endl;
		cout << "Which direction do you want to go? ";
		cin >> input;

		input = mapFunction.decision(input, 3, "east", "south", "west");
		if (input == "east") {
			mapFunction.animation("east", "  ", "B1", "B2", "  ", "C1", "C2", "  ", "D1", "D2", "  ", "E1", "E2", discoveredGrids);
			position = "D1";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			banditBossFunction();
		}
		else if (input == "south") {
			mapFunction.animation("south", "  ", "B1", "B2", "B3", "  ", "C1", "C2", "C3", "  ", "D1", "D2", "D3", discoveredGrids);
			position = "C2";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			goblinFunction();
		}
		else if (input == "west") {
			mapFunction.animation("west", "  ", "A1", "A2", "  ", "B1", "B2", "  ", "C1", "C2", "  ", "D1", "D2", discoveredGrids);
			position = "B1";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			wolfFunction();
		}
	} // ----------------------------------------------------------------------------------------------------------------
	else if (position == "A2") {
		if (mapFunction.isDiscovered("A2", discoveredGrids) == "?") {
			mapFunction.addDiscoveredList("A2", discoveredGrids);
			discoveredGrids++;

			chest.updatePlayerStats(health, strength, speed, swordType, armourType);
			chest.start("potion");

			health = chest.newHealth();
			strength = chest.newStrength();
			speed = chest.newSpeed();

			cout << " " << endl;
			displayStats();
			cout << " " << endl;
		}

		cout << " " << endl;
		cout << "There are three roads, one going [north], one going [east], and the other going [south]" << endl;
		cout << "Which direction do you want to go? ";
		cin >> input;

		input = mapFunction.decision(input, 3, "north", "east", "south");
		if (input == "north") {
			mapFunction.animation("north", "  ", "  ", "  ", "  ", "  ", "A1", "A2", "A3", "  ", "B1", "B2", "B3", discoveredGrids);
			position = "A1";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			banditFunction();
		}
		else if (input == "east") {
			mapFunction.animation("east", "  ", "  ", "  ", "A1", "A2", "A3", "B1", "B2", "B3", "C1", "C2", "C3", discoveredGrids);
			position = "B2";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			chestFunction();
		}
		else if (input == "south") {
			mapFunction.animation("south", "  ", "  ", "  ", "  ", "A1", "A2", "A3", "A4", "B1", "B2", "B3", "B4", discoveredGrids);
			position = "A3";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			alphaWolfFunction();
		}
	} // ----------------------------------------------------------------------------------------------------------------
	else if (position == "B2") {
		if (mapFunction.isDiscovered("B2", discoveredGrids) == "?") {
			mapFunction.addDiscoveredList("B2", discoveredGrids);
			discoveredGrids++;

			chest.updatePlayerStats(health, strength, speed, swordType, armourType);
			chest.start("inventory");

			swordType = chest.newSword();
			strength = chest.newStrength();
			armourType = chest.newArmour();
			health = chest.newHealth();

			cout << " " << endl;
			displayStats();
			cout << " " << endl;
		}

		cout << " " << endl;
		cout << "There are three roads, one going [north], one going [south], and the other going [west]" << endl;
		cout << "Which direction do you want to go? ";
		cin >> input;

		input = mapFunction.decision(input, 3, "north", "south", "west");
		if (input == "north") {
			mapFunction.animation("north", "  ", "A1", "A2", "A3", "  ", "B1", "B2", "B3", "  ", "C1", "C2", "C3", discoveredGrids);
			position = "B1";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			wolfFunction();
		}
		else if (input == "south") {
			mapFunction.animation("south", "A1", "A2", "A3", "A4", "B1", "B2", "B3", "B4", "C1", "C2", "C3", "C4", discoveredGrids);
			position = "B3";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			wolfFunction();
		}
		else if (input == "west") {
			mapFunction.animation("west", "  ", "  ", "  ", "A1", "A2", "A3", "B1", "B2", "B3", "C1", "C2", "C3", discoveredGrids);
			position = "A2";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			chestFunction();
		}
	} // ----------------------------------------------------------------------------------------------------------------
	else if (position == "E3") {
		if (mapFunction.isDiscovered("A2", discoveredGrids) == "?") {
			mapFunction.addDiscoveredList("A2", discoveredGrids);
			discoveredGrids++;

			chest.updatePlayerStats(health, strength, speed, swordType, armourType);
			chest.start("potion");

			health = chest.newHealth();
			strength = chest.newStrength();
			speed = chest.newSpeed();

			cout << " " << endl;
			displayStats();
			cout << " " << endl;
		}

		cout << " " << endl;
		cout << "There are two roads, one going [north], and the other going [south]" << endl;
		cout << "The road going north leads to the Goblin Boss, who is also blocking th way into the town, you must fight it to go in the town" << endl << endl;
		cout << "Which direction do you want to go? ";
		cin >> input;

		input = mapFunction.decision(input, 2, "north", "south");
		if (input == "north") {
			mapFunction.animation("north", "D1", "D2", "D3", "D4", "E1", "E2", "E3", "E4", "  ", "  ", "  ", "  ", discoveredGrids);
			position = "E2";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			goblinBossFunction();
		}
		else if (input == "south") {
			mapFunction.animation("south", "D2", "D3", "D4", "D5", "E2", "E3", "E4", "E5", "  ", "  ", "  ", "  ", discoveredGrids);
			position = "E4";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			wolfFunction();
		}
	} // ----------------------------------------------------------------------------------------------------------------
	else if (position == "A4") {
		if (mapFunction.isDiscovered("A4", discoveredGrids) == "?") {
			mapFunction.addDiscoveredList("A4", discoveredGrids);
			discoveredGrids++;

			chest.updatePlayerStats(health, strength, speed, swordType, armourType);
			chest.start("inventory");

			swordType = chest.newSword();
			strength = chest.newStrength();
			armourType = chest.newArmour();
			health = chest.newHealth();

			cout << " " << endl;
			displayStats();
			cout << " " << endl;
		}

		cout << " " << endl;
		cout << "There are three roads, one going [north], one going [east], and the other going [south]" << endl;
		cout << "Which direction do you want to go? ";
		cin >> input;

		input = mapFunction.decision(input, 3, "north", "east", "south");
		if (input == "north") {
			mapFunction.animation("north", "  ", "  ", "  ", "  ", "A2", "A3", "A4", "A5", "B2", "B3", "B4", "B5", discoveredGrids);
			position = "A3";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			alphaWolfFunction();
		}
		else if (input == "east") {
			mapFunction.animation("east", "  ", "  ", "  ", "A3", "A4", "A5", "B3", "B4", "B5", "C3", "C4", "C5", discoveredGrids);
			position = "B4";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			banditFunction();
		}
		else if (input == "south") {
			mapFunction.animation("south", "  ", "  ", "  ", "  ", "A3", "A4", "A5", "  ", "B3", "B4", "B5", "  ", discoveredGrids);
			position = "A5";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			goblinFunction();
		}
	} // ----------------------------------------------------------------------------------------------------------------
	else if (position == "C5") {
		if (mapFunction.isDiscovered("C5", discoveredGrids) == "?") {
			mapFunction.addDiscoveredList("C5", discoveredGrids);
			discoveredGrids++;

			chest.updatePlayerStats(health, strength, speed, swordType, armourType);
			chest.start("inventory");

			swordType = chest.newSword();
			strength = chest.newStrength();
			armourType = chest.newArmour();
			health = chest.newHealth();

			cout << " " << endl;
			displayStats();
			cout << " " << endl;
		}

		cout << " " << endl;
		cout << "There are three roads, one going [north], one going [east], and the other going [west]" << endl;
		cout << "Which direction do you want to go? ";
		cin >> input;

		input = mapFunction.decision(input, 3, "north", "east", "west");
		if (input == "north") {
			mapFunction.animation("north", "B3", "B4", "B5", "  ", "C3", "C4", "C5", "  ", "D3", "D4", "D5", "  ", discoveredGrids);
			position = "C4";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			wolfFunction();
		}
		else if (input == "east") {
			mapFunction.animation("east", "B4", "B5", "  ", "C4", "C5", "  ", "D4", "D5", "  ", "E4", "E5", "  ", discoveredGrids);
			position = "D5";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			goblinFunction();
		}
		else if (input == "west") {
			mapFunction.animation("west", "A4", "A5", "  ", "B4", "B5", "  ", "C4", "C5", "  ", "D4", "D5", "  ", discoveredGrids);
			position = "B5";

			cout << " " << endl;
			displayStats();
			cout << " " << endl;

			banditFunction();
		}
	}
}
// ----------------------------------------------------------------------------------------------------------------
void banditBossFunction() {
	banditBoss.updatePlayerStats(health, strength);
	banditBoss.start();
	health = banditBoss.updatePlayerHealth();

	cout << " " << endl;

	system("PAUSE");

	gameOver(); // calls game over state
}
// ----------------------------------------------------------------------------------------------------------------
void goblinBossFunction() {
	goblinBoss.updatePlayerStats(health, strength);
	goblinBoss.start();
	health = goblinBoss.updatePlayerHealth();

	cout << " " << endl;

	system("PAUSE");

	gameOver();
}
