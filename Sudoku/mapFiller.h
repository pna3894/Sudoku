#pragma once
#ifndef MAPFILLER_H
#define MAPFILLER_H

#include <string>
#include <vector>
using namespace std;

void fillCorners(string* map);
void fillVerticals(string* map);
void fillHorizontals(string* map);
void fillCells(string* map, vector<vector<bool>> isHidden, vector<vector<int>> cells);
void fillMap(string* map, vector<vector<bool>> isHidden, vector<vector<int>> cells);

#endif // !MAPFILLER_H

