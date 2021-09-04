#include "Game.h"
#include "Map.h"

Game::Game()
{
	map = new Map();
}

Game::~Game()
{
	delete map;
}

Game::Start()