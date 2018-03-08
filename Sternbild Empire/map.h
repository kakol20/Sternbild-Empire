#pragma once

#include <string>

using namespace std;

class map
{
public:
	map();
	~map(void);

	string directions[4];
	string discoveredList[25];
	string mapAnim[13];
	string position;

	string decision(string, int, string = "north", string = "east", string = "south", string = "west");
	bool directionValid(string, int);
	void addDiscoveredList(string, int);
	string isDiscovered(string, int);
	void animation(string, string, string, string, string, string, string, string, string, string, string, string, string, int);
};

