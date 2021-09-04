#include "mapFiller.h"
#include <string>

void fillCorners(string* map)
{
	for (int i = 0; i < 13; i += 4)
		for (int j = 0; j < 13; j += 4)
			map[i][j] = '+';
}

void fillVerticals(string* map)
{
	for (int i = 1; i < 12; i++)
		for (int j = 0; j < 13; j += 4)
			if (i % 4) map[i][j] = '|';
}

void fillHorizontals(string* map)
{
	for (int i = 0; i < 13; i++)
		for (int j = 1; j < 12; j++)
			if (j % 4) map[i][j] = '-';
}

void fillCells(string* map, vector<vector<bool>> isHidden, vector<vector<int>> cells)
{
	for (int r = 1; r < 12; r++)
		for (int c = 1; c < 12; c++)
			if (r % 4 && c % 4)
			{
				int rIdx = r - r / 4 - 1;
				int cIdx = c - c / 4 - 1;

				if (isHidden[rIdx][cIdx])
					map[r][c] = '.';
				else
					map[r][c] = cells[rIdx][cIdx] + '0';
			}
}

void fillMap(string* map, vector<vector<bool>> isHidden, vector<vector<int>> cells)
{
	for (int i = 0; i < 13; i++)
		map[i].assign(13, ' ');

	fillCorners(map);
	fillVerticals(map);
	fillHorizontals(map);
	fillCells(map, isHidden, cells);
}