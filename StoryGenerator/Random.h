#pragma once
#include <cstdlib>

struct RandomRange { 
	int min; int max; 
	RandomRange(int min, int max)
	{
		this->min = min;
		this->max = max;
	}
};

int randomInt(RandomRange range)
{
	return rand() % range.max + range.min;
}

float randomFloat(float min, float max)
{
	return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}
