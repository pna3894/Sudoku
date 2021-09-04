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
	string input;

	rndMix();
	
	while(true)
	{
		map->Draw();
		cout << "Enter cell number: ";
		cin >> input;
		if (input[0] == 'q')
			break;
		else if (input.size() > 2)
			continue;
		cout << "Enter desirable number: ";
		cin >> input;
		if (input[0] == 'q')
			break;
		else if (input.size() > 2)
			continue;
		system("CLS");
	}

	system("CLS");
	cout << "Game is terminated";
}

void Game::NewGame()
{
	system("CLS");
	map = new Map();
	rndMix();
	map->Draw();
}

void Game::rndMix()
{
	int totCount = rnd.next(50, 100);

	while (totCount)
	{
		int mixFunc = rnd.next(0, 100) % 5;

		switch (mixFunc)
		{
		case 0:
			mixLines(1);
			break;
		case 1:
			mixRegions(1);
			break;
		case 2:
			mixLines(0);
			break;
		case 3:
			mixRegions(0);
			break;
		case 4:
			map->transpose();
			break;
		default:
			break;
		}

		totCount--;
	}
}

void Game::mixLines(bool isRows)
{
	int from, to, region;

	region = (rnd.next(0, 100) % 3) * 3;
	from = rnd.next(0, 100) % 3 + region;
	to = rnd.next(0, 100) % 3 + region;
	while (to == from)
		to = rnd.next(0, 100) % 3;

	if (isRows)
		map->swapRows(from, to);
	else
		map->swapCols(from, to);
}

void Game::mixRegions(bool isHorizon)
{
	int from, to;

	from = rnd.next(0, 100) % 3;
	to = rnd.next(0, 100) % 3;
	while (to == from)
		to = rnd.next(0, 100) % 3;

	if (isHorizon)
		map->swapHorReg(from, to);
	else
		map->swapVertReg(from, to);
}