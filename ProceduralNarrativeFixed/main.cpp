#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include "Planet.h"


int main()
{
	srand(time(NULL));

	Planet mainPlanet(2, 4);
	mainPlanet.generatePreHistory();

	while (true)
	{
		mainPlanet.progressWorldState();

		std::cin.ignore(1);
	}
}