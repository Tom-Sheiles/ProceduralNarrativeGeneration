#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include "Random.h"
#include "GlobalVariables.h"
#include "Species.h"
#include "Util.h"
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

	void addLocalSpecies(std::vector<Species> species, RandomRange numberOfSpecies)
	{
		// Ancient Species

		int r_numberOfSpecies = randomInt(numberOfSpecies);

		for (int i = 0; i < r_numberOfSpecies; i++)
		{
			int s = randomInt(RandomRange(0, species.size()));
			localSpecies.push_back(species[s]);
		}

		// magic
		int wellChance = randomInt(RandomRange(0, 3));
		int wellNumber = 0;

		for (int i = 0; i < wellChance; i++)
		{
			if (randomPercent(0.6))
				wellNumber++;
		}

		std::cout << continentName << " has " << r_numberOfSpecies << " ancient species and " << wellNumber << " magic sources\n";
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

		// find all ancient species
		for (int i = 0; i < g_Species.size(); i++)
		{
			if (g_Species[i].type == CreatureType::Ancient)
				ancientSpecies.push_back(g_Species[i]);
		}

		// randomly select which continents have them
		for (int i = 0; i < continentNumber; i++) {
			continents[i].addLocalSpecies(ancientSpecies, RandomRange(0, 3));
		}
	}

private:
	std::string planetName;
	int numberOfContinents;
	RandomRange* continentsRange;
	Continent* continents;

	RandomRange* ancientSpeciesRange;
};
