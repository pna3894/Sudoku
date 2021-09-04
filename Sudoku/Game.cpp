#include "Game.h"

Game::Game()
{
	map = new Map();
}

Game::~Game()
{
	delete map;
}

void Game::Start()
{
	map->Draw();
}