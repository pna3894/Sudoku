#pragma once
#ifndef GAME_H
#define GAME_H

#include "Map.h"

class Game
{
public:
	Game();
	~Game();
	
	void Start();

private:
	Map* map;
};

#endif