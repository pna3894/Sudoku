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

vector<int> Map::get_row(int n)
{
	n %= 9;
	return cells[n];
}

void Map::set_row(int n, vector<int> row)
{
	cells[n] = row;
}


void Map::Draw()
{
	string map[13];

	fillMap(map, isHidden, cells);


	for (int i = 0; i < 13; i++)
		cout << map[i] << endl;
}

void Map::assignDefaultCells(vector<vector<int>>& cells)
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cells[i][j] = (j + 3 * (i + 1) + i / 3) % 9 + 1;
}

void Map::swapRows(int a, int b)
{
	a %= 9;
	b %= 9;

	vector<int> tmpRow = cells[a];
	cells[a] = cells[b];
	cells[b] = tmpRow;
}

void Map::swapCols(int a, int b)
{
	//confirmation that a,b in [0,8]
	a %= 9;
	b %= 9;

	vector<int> tmpCol(9);

	for (int i = 0; i < 9; i++)
	{
		tmpCol[i] = cells[i][a];
		cells[i][a] = cells[i][b];
		cells[i][b] = tmpCol[i];
	}
}

void Map::swapHorReg(int a, int b)
{
	//assure that a,b in [0,3]; convert to start idx row
	a = (a % 3) * 3;
	b = (b % 3) * 3;

	vector<vector<int>> tmpReg(3, vector<int>(9));

	for (int i = 0; i < 3; i++)
	{
		tmpReg[i] = cells[i + a];
		cells[i + a] = cells[i + b];
		cells[i + b] = tmpReg[i];
	}
}

void Map::swapVertReg(int a, int b)
{
	//assure that a,b in [0,3]; convert to start idx row
	a = (a % 3) * 3;
	b = (b % 3) * 3;

	vector<vector<int>> tmpReg(9, vector<int>(3));

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			tmpReg[j][i] = cells[j][i + a];
			cells[j][i + a] = cells[j][i + b];
			cells[j][i + b] = tmpReg[j][i];
		}
	}
}

void Map::transpose()
{
	vector<vector<int>> transposed(9, vector<int>(9));

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			transposed[j][i] = cells[i][j];
		}
	for (int i = 0; i < 9; i++)
		cells[i] = transposed[i];
}

bool Map::IsSolvable()
{
	bool solvable = true;
	return true;
}