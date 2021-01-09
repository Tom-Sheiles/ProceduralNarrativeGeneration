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
		this->wellNumber = 0;
	}


	void addLocalSpecies(std::vector<Species> species, RandomRange numberOfSpecies)
	{
		// Ancient Species

		int r_numberOfSpecies = randomInt(numberOfSpecies);

		for (int i = 0; i < r_numberOfSpecies; i++)
		{
			int s = randomInt(RandomRange(0, species.size()));
			ancientSpecies.push_back(species[s]);
		}

		// magic
		int wellChance = randomInt(RandomRange(0, 3));
		int wellNumber = 0;

		for (int i = 0; i < wellChance; i++)
		{
			if (randomPercent(0.6))
				wellNumber++;
		}

		this->wellNumber = wellNumber;
	}

	// TODO: Finish functionality for place generation that allows for random towns, cities and villages to form on continents.
	//       After this, work on the actual game loop of the simulation that allows civilizations to take actions as well as a
	//       system of reputation between civs that influence the opinions of each faction.
	//       
	//       Long term goal should be a decision based system that activly tries to generate plot lines and controlls narrative pacing
	//       by steering groups towards conflicts and maximizes understandability by reducing the chance that multiple large scale stories
	//       can happen at the same time.

	void addPlace(std::vector <Species> species, RandomRange numberOfPlaces)
	{

	}


	std::string s_AncientInfo()
	{
		std::string s = "";
		
		if (ancientSpecies.size() > 0) {
			s += "Ancients: ";
			for (int i = 0; i < ancientSpecies.size(); i++)
			{
				s += ancientSpecies[i].name + " ";
			}
			if (wellNumber > 0) s += " has a magical energy permiating it";
		}
		return s;
	}


private:
	std::vector<Species> ancientSpecies;
	int wellNumber;
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
		printf("\n Planet: %s\n\n Continents:\n  ", planetName.c_str());

		for (int i = 0; i < numberOfContinents; i++)
		{
			printf("Name: %d\n  ", continents[i].continentName);
			printf("%s \n  ", continents[i].s_AncientInfo().c_str());

			printf("\n");
		}
	}


	void generatePreHistory() {

		std::vector<Species> ancientSpecies;
		std::vector<Species> humanoids;

		// find all ancient species
		for (int i = 0; i < g_Species.size(); i++)
		{
			switch (g_Species[i].type)
			{
				case CreatureType::Ancient:
				{
					ancientSpecies.push_back(g_Species[i]);
					break;
				}

				case CreatureType::Humanoid:
				{
					humanoids.push_back(g_Species[i]);
					break;
				}
				default:
					break;
			}
		}

		// Add species and towns to continents
		for (int i = 0; i < continentNumber; i++) {
			continents[i].addLocalSpecies(ancientSpecies, RandomRange(0, 3));
			continents[i].addPlace(humanoids, RandomRange(1, 5));
		}
	}


private:
	std::string planetName;

	int numberOfContinents;
	RandomRange* continentsRange;
	Continent* continents;

	RandomRange* ancientSpeciesRange;
};
