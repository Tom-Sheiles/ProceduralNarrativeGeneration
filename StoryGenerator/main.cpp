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

	mainPlanet.printWorldInfo();
}