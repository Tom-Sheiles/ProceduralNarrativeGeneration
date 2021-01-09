#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include "Random.h"
#include "GlobalVariables.h"
#include "Species.h"
#pragma once

class Place {
	// should have subtypes such as city
};

class Continent {
public:
	int continentName;

	Continent() {
		continentName = ++continentNumber;
	}

	void addLocalSpecies(Species species, RandomRange numberOfSpecies)
	{
		int r_numberOfSpecies = randomInt(numberOfSpecies);

		for()
	}

private:
	std::vector<Species> localSpecies;
};


class Planet {

public:

	Planet(int minContinents = 2, int maxContinents = 3)
	{
		this->continentsRange = new RandomRange(minContinents, maxContinents);

		planetName = "Azeroth"; // This should be random later
		numberOfContinents = randomInt(*continentsRange); // have global script with variables such as min and max continents

		continents = new Continent[numberOfContinents];
	}

	void printWorldInfo()
	{
		printf("The planet known as %s is comprised of %d continents.\n", planetName.c_str(), numberOfContinents);
		printf("These continents are ");

		for (int i = 0; i < numberOfContinents - 1; i++)
		{
			printf("%d, ", continents[i].continentName);
		}
		printf("and %d.\n", continents[numberOfContinents - 1].continentName);
	}

	void generatePreHistory() {

		std::vector<Species> ancientSpecies;

		for (int i = 0; i < g_Species.size(); i++)
		{
			if (g_Species[i].type == CreatureType::Ancient)
				ancientSpecies.push_back(g_Species[i]);
		}

		for (int i = 0; i < continentNumber; i++) {

		}
	}

private:
	std::string planetName;
	int numberOfContinents;
	RandomRange* continentsRange;
	Continent* continents;

	RandomRange* ancientSpeciesRange;
};
