#pragma once
#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include "mapFiller.h"

using namespace std;

class Map
{
public:
	Map();
	~Map();

	void Draw();
	void ShowInfo();
	bool IsSolvable();

private:
	const int height = 9;
	const int width = 9;
	vector<vector<bool>> isHidden;
	vector<vector<int>> cells;
};

#endif // !MAP_H
