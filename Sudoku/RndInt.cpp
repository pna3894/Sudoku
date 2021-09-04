#include "RndInt.h"
#include <time.h>

RndInt::RndInt()
{
	rnd_engine.seed(time(nullptr));
}

RndInt::~RndInt()
{
}

unsigned RndInt::next(unsigned min, unsigned max)
{
	if (min > max)
	{
		unsigned tmp = min;
		min = max;
		max = tmp;
	}

	uniform_int_distribution<unsigned> distr(min, max);

	return distr(rnd_engine);
}