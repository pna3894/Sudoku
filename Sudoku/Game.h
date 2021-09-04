#pragma once
#ifndef GAME_H
#define GAME_H

#include "Map.h"
#include "RndInt.h"
#include <random>

class Game
{
public:
	Game();
	~Game();

	void Start();
	void NewGame();

private:
	Map* map;
	RndInt rnd;

	void rndMix();
	void mixLines(bool isRows);
	void mixRegions(bool isHorReg);
	void delNums();
};

#endif