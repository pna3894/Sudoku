#pragma once
#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include <iostream>
#include "mapFiller.h"

using namespace std;

class Map
{
public:
	Map();
	~Map();

	void Draw();
	bool IsSolvable();
	vector<int> get_row(int n);
	void set_row(int n, vector<int> row);
	void swapRows(int a, int b);
	void swapCols(int a, int b);
	void swapHorReg(int a, int b);
	void swapVertReg(int a, int b);
	void transpose();

private:
	const int height = 9;
	const int width = 9;
	vector<vector<bool>> isHidden;
	vector<vector<int>> cells;

	void assignDefaultCells(vector<vector<int>> &cells);
};

#endif // !MAP_H
