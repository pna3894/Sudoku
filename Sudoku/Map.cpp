#include "Map.h"

Map::Map()
{
	cells.resize(height);
	isHidden.resize(height);
	for (int i = 0; i < height; i++)
	{
		cells[i].resize(width);
		isHidden[i].resize(width);
	}
	
	assignDefaultCells(cells);
}

Map::~Map()
{
	
}

void Map::Draw()
{
	string map[13];

	
	fillMap(map, isHidden, cells);
	

	for (int i = 0; i < 13; i++)
		cout << map[i] << endl;
}

void Map::assignDefaultCells(vector<vector<int>> &cells)
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cells[i][j] = (j + 3 * (i+1) + i/3) % 9 + 1;
}

