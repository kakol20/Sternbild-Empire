#include "stdafx.h"
#include "chestClass.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


chestClass::chestClass()
{
}


chestClass::~chestClass()
{
}

chestClass::chestClass(int a, int b, int c) { // sets local variables
	playerHealth = a;
	playerSpeed = b;
	playerStrength = c;
}

void chestClass::updatePlayerStats(int a, int b, int c, string d, string e) {
	playerHealth = a;
	playerStrength = b;
	playerSpeed = c;
	playerSwordType = d;
	playerArmourType = e;
}

int chestClass::newHealth() { // returns the player's new health value
	return playerHealth;
}
int chestClass::newStrength() { // returns the player's new strength value
	return playerStrength;
}
int chestClass::newSpeed() { // returns the player's new speed value
	return playerSpeed;
}
string chestClass::newSword() { // returns the player's new sword type
	return playerSwordType;
}
string chestClass::newArmour() { // returns the player's new armour type
	return playerArmourType;
}

string chestClass::potionDecision(string a) {
	transform(a.begin(), a.end(), a.begin(), ::tolower);

	if (a == "health" || a == "strength" || a == "speed") { // checks if the input was valid
		return a;
	}
	else {
		cout << "Invalid input, please type it again. [health] or [strength] or [speed] ";
		string input;
		cin >> input;
		return potionDecision(input);
	}
}

string chestClass::inventoryDecision(string a) {
	transform(a.begin(), a.end(), a.begin(), ::tolower);

	if (a == "sword" || a == "armour") { // checks if the input was valid
		return a;
	}
	else {
		cout << "Ivalid input, please type it again. [sword] or [armour] ";
		string input;
		cin >> input;
		return inventoryDecision(input);
	}
}

void chestClass::start(string chestType) {
	if (chestType == "potion") { // checks chest type
		cout << "There is a glowing chest, inside there is one [health] potion, one [strength] potion and one [speed] potion" << endl;
		cout << "Which potion do you want to take? ";
		string input;
		cin >> input;

		input = potionDecision(input);
		if (input == "health") {
			cout << "The health potion gives you +1HP." << endl;
			playerHealth = playerHealth + 1;
		}
		else if (input == "strength") {
			cout << "The strength potion gives you +1 strength." << endl;
			playerStrength = playerStrength + 1;
		}
		else if (input == "speed") {
			cout << "The speed potion gives you +1 speed." << endl;
			playerSpeed = playerSpeed + 1;
		}
	}
	else if (chestType == "inventory") {
		string swordUpgrade;
		if (playerSwordType == "none") { // checks sword the player has
			swordUpgrade = "wood";
		}
		else if (playerSwordType == "wood") {
			swordUpgrade = "stone";
		}
		else if (playerSwordType == "stone") {
			swordUpgrade = "iron";
		}
		else if (playerSwordType == "iron") {
			swordUpgrade = "diamond";
		}

		string armourUpgrade;
		if (playerArmourType == "none") { // checks the armour the player has
			armourUpgrade = "leather";
		}
		else if (playerArmourType == "leather") {
			armourUpgrade = "chain";
		}
		else if (playerArmourType == "chain") {
			armourUpgrade = "iron";
		}
		else if (playerArmourType == "iron") {
			armourUpgrade = "diamond";
		}

		cout << "There is a glowing chest, inside there is one " + swordUpgrade + " [sword], and one " + armourUpgrade + " [armour]. " << endl; // output based on the player's current inventory
		cout << "Which one do you want to take? ";
		string input;
		cin >> input;

		input = inventoryDecision(input);
		if (input == "sword") {
			cout << "The " + swordUpgrade + " sword gives you 2 additional strength." << endl;
			playerStrength = playerStrength + 2;
			playerSwordType = swordUpgrade;
		}
		else if (input == "armour") {
			cout << "The " + armourUpgrade + " armour gives you 2 additional health." << endl;
			playerHealth = playerHealth + 2;
			playerArmourType = armourUpgrade;
		}
	}

	cout << "The chest disappears." << endl; // this is so the chest cannot be rediscovered again
}
