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
		

}

Map::~Map()
{
	
}

void Map::Draw()
{
	string rawMap[13];

	fillMap(rawMap, isHidden, cells);
}

