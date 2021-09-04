#pragma once
#ifndef RNDINT_H
#define RNDINT_H

#include <random>
using namespace std;

class RndInt
{
public:
	RndInt();
	~RndInt();

	unsigned next(unsigned min, unsigned max);

private:
	unsigned min, max;
	mt19937 rnd_engine;
};

#endif // !RNDINT_H
