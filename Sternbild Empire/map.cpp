#include "stdafx.h"
#include "map.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <Windows.h>

using namespace std;


map::map()
{
	directions[0] = "north";
	directions[1] = "east";
	directions[2] = "south";
	directions[3] = "west";

	discoveredList[0] = "C3";
}


map::~map(void)
{
}

string map::decision(string a, int b, string c, string d, string e, string f) {
	transform(a.begin(), a.end(), a.begin(), ::tolower);

	directions[0] = c; // adds possible directions in array
	directions[1] = d;
	if (b <= 3) {
		directions[2] = e;
	}
	if (b <= 4) {
		directions[3] = f;
	}
	string directionDecide = "";

	if (directionValid(a, b)) {
		return a;
	}
	else {
		for (int i = 0; i < b; i++) {
			if (i == b - 1) {
				directionDecide = directionDecide + "[" + directions[i] + "] ";
			}
			else {
				directionDecide = directionDecide + "[" + directions[i] + "] or "; // goes through all possible  directions and outputs them
			}
		}

		cout << "Invalid input, please type it again. " + directionDecide << endl;
		string input;
		cin >> input;

		return decision(input, b, c, d, e); // calls itself
	}

}

bool map::directionValid(string a, int b) {
	int index = 5;

	for (int i = 0; i < b; i++) {
		if (a == directions[i]) { // goes through array to check if the cin is valid
			index = i;
		}
	}
	return index <= 3; // returns the boolean value if the input was part of the directions[] array
}

void map::addDiscoveredList(string a, int b) {
	discoveredList[b] = a;
}

string map::isDiscovered(string a, int b) {
	if (a == "  ") {
		return " "; // returns blank if the grid is not part of the map
	}
	for (int i = 0; i < b; i++) {
		if (a == discoveredList[i]) { // goes through list of discovered grids
			return "x"; // x for has been discovered
		}

	}
	return "?"; // ? for has not been discovered
}

void map::animation(string a, string b, string c, string d, string e, string f, string g, string h, string i, string j, string k, string l, string m, int n) {
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hconsole, 0x0A); // changes text colour to green

	system("cls");
	if (a == "north") {
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + c + "   |    " + g + "   |    " + k + "   | o = Player" << endl;
		cout << "|    " + isDiscovered(c, n) + "    |    " + isDiscovered(g, n) + "    |    " + isDiscovered(k, n) + "    | x = Discovered" << endl; // shows if the grid, on screen, if it has been discovered or not
		cout << "|         |         |         | ? = Undiscovered" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + d + "   |    " + h + "   |    " + l + "   |" << endl;
		cout << "|    " + isDiscovered(d, n) + "    |    o    |    " + isDiscovered(l, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + e + "   |    " + i + "   |    " + m + "   |" << endl;
		cout << "|    " + isDiscovered(e, n) + "    |    " + isDiscovered(i, n) + "    |    " + isDiscovered(m, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		Sleep(500);

		system("cls");
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + c + "   |    " + g + "   |    " + k + "   | o = Player" << endl;
		cout << "|    " + isDiscovered(c, n) + "    |    " + isDiscovered(g, n) + "    |    " + isDiscovered(k, n) + "    | x = Discovered" << endl;
		cout << "|         |         |         | ? = Undiscovered" << endl;
		cout << " --------- ----o---- ---------" << endl;
		cout << "|    " + d + "   |    " + h + "   |    " + l + "   |" << endl;
		cout << "|    " + isDiscovered(d, n) + "    |    x    |    " + isDiscovered(l, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + e + "   |    " + i + "   |    " + m + "   |" << endl;
		cout << "|    " + isDiscovered(e, n) + "    |    " + isDiscovered(i, n) + "    |    " + isDiscovered(m, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		Sleep(500);

		system("cls");
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + c + "   |    " + g + "   |    " + k + "   | o = Player" << endl;
		cout << "|    " + isDiscovered(c, n) + "    |    o    |    " + isDiscovered(k, n) + "    | x = Discovered" << endl;
		cout << "|         |         |         | ? = Undiscovered" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + d + "   |    " + h + "   |    " + l + "   |" << endl;
		cout << "|    " + isDiscovered(d, n) + "    |    x    |    " + isDiscovered(l, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + e + "   |    " + i + "   |    " + m + "   |" << endl;
		cout << "|    " + isDiscovered(e, n) + "    |    " + isDiscovered(i, n) + "    |    " + isDiscovered(m, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		Sleep(500);

		system("cls");
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + b + "   |    " + f + "   |    " + j + "   | o = Player" << endl;
		cout << "|    " + isDiscovered(b, n) + "    |    " + isDiscovered(f, n) + "    |    " + isDiscovered(j, n) + "    | x = Discovered" << endl;
		cout << "|         |         |         | ? = Undiscovered" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + c + "   |    " + g + "   |    " + k + "   |" << endl;
		cout << "|    " + isDiscovered(c, n) + "    |    o    |    " + isDiscovered(k, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + d + "   |    " + h + "   |    " + l + "   |" << endl;
		cout << "|    " + isDiscovered(d, n) + "    |    " + isDiscovered(h, n) + "    |    " + isDiscovered(l, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		Sleep(500);
	}
	else if (a == "east") {
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + b + "   |    " + e + "   |    " + h + "   | o = Player" << endl;
		cout << "|    " + isDiscovered(b, n) + "    |    " + isDiscovered(e, n) + "    |    " + isDiscovered(h, n) + "    | x = Discovered" << endl;
		cout << "|         |         |         | ? = Undiscovered" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + c + "   |    " + f + "   |    " + i + "   |" << endl;
		cout << "|    " + isDiscovered(c, n) + "    |    o    |    " + isDiscovered(i, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + d + "   |    " + g + "   |    " + j + "   |" << endl;
		cout << "|    " + isDiscovered(d, n) + "    |    " + isDiscovered(g, n) + "    |    " + isDiscovered(j, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		Sleep(500);

		system("cls");
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + b + "   |    " + e + "   |    " + h + "   | o = Player" << endl;
		cout << "|    " + isDiscovered(b, n) + "    |    " + isDiscovered(e, n) + "    |    " + isDiscovered(h, n) + "    | x = Discovered" << endl;
		cout << "|         |         |         | ? = Undiscovered" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + c + "   |    " + f + "   |    " + i + "   |" << endl;
		cout << "|    " + isDiscovered(c, n) + "    |    x    o    " + isDiscovered(i, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + d + "   |    " + g + "   |    " + j + "   |" << endl;
		cout << "|    " + isDiscovered(d, n) + "    |    " + isDiscovered(g, n) + "    |    " + isDiscovered(j, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		Sleep(500);

		system("cls");
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + b + "   |    " + e + "   |    " + h + "   | o = Player" << endl;
		cout << "|    " + isDiscovered(b, n) + "    |    " + isDiscovered(e, n) + "    |    " + isDiscovered(h, n) + "    | x = Discovered" << endl;
		cout << "|         |         |         | ? = Undiscovered" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + c + "   |    " + f + "   |    " + i + "   |" << endl;
		cout << "|    " + isDiscovered(c, n) + "    |    x    |    o    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + d + "   |    " + g + "   |    " + j + "   |" << endl;
		cout << "|    " + isDiscovered(d, n) + "    |    " + isDiscovered(g, n) + "    |    " + isDiscovered(j, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		Sleep(500);

		system("cls");
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + e + "   |    " + h + "   |    " + k + "   | o = Player" << endl;
		cout << "|    " + isDiscovered(e, n) + "    |    " + isDiscovered(h, n) + "    |    " + isDiscovered(k, n) + "    | x = Discovered" << endl;
		cout << "|         |         |         | ? = Undiscovered" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + f + "   |    " + i + "   |    " + l + "   |" << endl;
		cout << "|    " + isDiscovered(f, n) + "    |    o    |    " + isDiscovered(l, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + g + "   |    " + j + "   |    " + m + "   |" << endl;
		cout << "|    " + isDiscovered(g, n) + "    |    " + isDiscovered(j, n) + "    |    " + isDiscovered(m, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		Sleep(500);
	}
	else if (a == "south") {
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + b + "   |    " + f + "   |    " + j + "   | o = Player" << endl;
		cout << "|    " + isDiscovered(b, n) + "    |    " + isDiscovered(f, n) + "    |    " + isDiscovered(j, n) + "    | x = Discovered" << endl;
		cout << "|         |         |         | ? = Undiscovered" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + c + "   |    " + g + "   |    " + k + "   |" << endl;
		cout << "|    " + isDiscovered(c, n) + "    |    o    |    " + isDiscovered(k, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + d + "   |    " + h + "   |    " + l + "   |" << endl;
		cout << "|    " + isDiscovered(d, n) + "    |    " + isDiscovered(h, n) + "    |    " + isDiscovered(l, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		Sleep(500);

		system("cls");
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + b + "   |    " + f + "   |    " + j + "   | o = Player" << endl;
		cout << "|    " + isDiscovered(b, n) + "    |    " + isDiscovered(f, n) + "    |    " + isDiscovered(j, n) + "    | x = Discovered" << endl;
		cout << "|         |         |         | ? = Undiscovered" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + c + "   |    " + g + "   |    " + k + "   |" << endl;
		cout << "|    " + isDiscovered(c, n) + "    |    x    |    " + isDiscovered(k, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- ----o---- ---------" << endl;
		cout << "|    " + d + "   |    " + h + "   |    " + l + "   |" << endl;
		cout << "|    " + isDiscovered(d, n) + "    |    " + isDiscovered(h, n) + "    |    " + isDiscovered(l, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		Sleep(500);

		system("cls");
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + b + "   |    " + f + "   |    " + j + "   | o = Player" << endl;
		cout << "|    " + isDiscovered(b, n) + "    |    " + isDiscovered(f, n) + "    |    " + isDiscovered(j, n) + "    | x = Discovered" << endl;
		cout << "|         |         |         | ? = Undiscovered" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + c + "   |    " + g + "   |    " + k + "   |" << endl;
		cout << "|    " + isDiscovered(c, n) + "    |    x    |    " + isDiscovered(k, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + d + "   |    " + h + "   |    " + l + "   |" << endl;
		cout << "|    " + isDiscovered(d, n) + "    |    o    |    " + isDiscovered(l, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		Sleep(500);

		system("cls");
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + c + "   |    " + g + "   |    " + k + "   | o = Player" << endl;
		cout << "|    " + isDiscovered(c, n) + "    |    " + isDiscovered(g, n) + "    |    " + isDiscovered(k, n) + "    | x = Discovered" << endl;
		cout << "|         |         |         | ? = Undiscovered" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + d + "   |    " + h + "   |    " + l + "   |" << endl;
		cout << "|    " + isDiscovered(d, n) + "    |    o    |    " + isDiscovered(l, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + e + "   |    " + i + "   |    " + m + "   |" << endl;
		cout << "|    " + isDiscovered(e, n) + "    |    " + isDiscovered(i, n) + "    |    " + isDiscovered(m, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		Sleep(500);
	}
	else if (a == "west") {
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + e + "   |    " + h + "   |    " + k + "   | o = Player" << endl;
		cout << "|    " + isDiscovered(e, n) + "    |    " + isDiscovered(h, n) + "    |    " + isDiscovered(k, n) + "    | x = Discovered" << endl;
		cout << "|         |         |         | ? = Undiscovered" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + f + "   |    " + i + "   |    " + l + "   |" << endl;
		cout << "|    " + isDiscovered(f, n) + "    |    o    |    " + isDiscovered(l, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + g + "   |    " + j + "   |    " + m + "   |" << endl;
		cout << "|    " + isDiscovered(g, n) + "    |    " + isDiscovered(j, n) + "    |    " + isDiscovered(m, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		Sleep(500);

		system("cls");
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + e + "   |    " + h + "   |    " + k + "   | o = Player" << endl;
		cout << "|    " + isDiscovered(e, n) + "    |    " + isDiscovered(h, n) + "    |    " + isDiscovered(k, n) + "    | x = Discovered" << endl;
		cout << "|         |         |         | ? = Undiscovered" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + f + "   |    " + i + "   |    " + l + "   |" << endl;
		cout << "|    " + isDiscovered(f, n) + "    o    x    |    " + isDiscovered(l, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + g + "   |    " + j + "   |    " + m + "   |" << endl;
		cout << "|    " + isDiscovered(g, n) + "    |    " + isDiscovered(j, n) + "    |    " + isDiscovered(m, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		Sleep(500);

		system("cls");
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + e + "   |    " + h + "   |    " + k + "   | o = Player" << endl;
		cout << "|    " + isDiscovered(e, n) + "    |    " + isDiscovered(h, n) + "    |    " + isDiscovered(k, n) + "    | x = Discovered" << endl;
		cout << "|         |         |         | ? = Undiscovered" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + f + "   |    " + i + "   |    " + l + "   |" << endl;
		cout << "|    o    |    x    |    " + isDiscovered(l, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + g + "   |    " + j + "   |    " + m + "   |" << endl;
		cout << "|    " + isDiscovered(g, n) + "    |    " + isDiscovered(j, n) + "    |    " + isDiscovered(m, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		Sleep(500);

		system("cls");
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + b + "   |    " + e + "   |    " + h + "   | o = Player" << endl;
		cout << "|    " + isDiscovered(b, n) + "    |    " + isDiscovered(e, n) + "    |    " + isDiscovered(h, n) + "    | x = Discovered" << endl;
		cout << "|         |         |         | ? = Undiscovered" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + c + "   |    " + f + "   |    " + i + "   |" << endl;
		cout << "|    " + isDiscovered(c, n) + "    |    o    |    " + isDiscovered(i, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		cout << "|    " + d + "   |    " + g + "   |    " + j + "   |" << endl;
		cout << "|    " + isDiscovered(d, n) + "    |    " + isDiscovered(g, n) + "    |    " + isDiscovered(j, n) + "    |" << endl;
		cout << "|         |         |         |" << endl;
		cout << " --------- --------- ---------" << endl;
		Sleep(500);
	}

	SetConsoleTextAttribute(hconsole, 0x0F); // changes text color to white
}
