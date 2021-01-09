#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include "Planet.h"


void generatePlanet(Planet* planet)
{
	planet->generatePreHistory();
}


int main()
{
	srand(time(NULL));

	Planet mainPlanet(2, 8);
	generatePlanet(&mainPlanet);

	//mainPlanet.printWorldInfo();
}



