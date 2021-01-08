#pragma once
#include <cstdlib>

int randomInt(int min, int max)
{
	return rand() % max + min;
}

float randomFloat(float min, float max)
{
	return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}
