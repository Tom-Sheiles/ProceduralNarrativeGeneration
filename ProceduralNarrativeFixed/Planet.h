#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include "Random.h"
#include "GlobalVariables.h"
#include "Species.h"
#include "Util.h"
#include "Place.h"

std::string continentNames[] = { "Kalimdor", "The Eastern Kingdoms", "Panderia", "Ernartiea", "Calderia", "Shalderi", "Tamriel" };

class Continent {
public:
	std::string continentName;

	Continent() {
		continentName = continentNames[randomInt(RandomRange(0, 7))];
		this->wellNumber = 0;
	}


	std::vector<Species> addLocalSpecies(std::vector<Species> species, RandomRange numberOfSpecies)
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

		return ancientSpecies;
	}

	// TODO: Finish functionality for place generation that allows for random towns, cities and villages to form on continents.
	//       After this, work on the actual game loop of the simulation that allows civilizations to take actions as well as a
	//       system of reputation between civs that influence the opinions of each faction.
	//       
	//       Long term goal should be a decision based system that activly tries to generate plot lines and controlls narrative pacing
	//       by steering groups towards conflicts and maximizes understandability by reducing the chance that multiple large scale stories
	//       can happen at the same time.

	std::vector<Place> addPlace(std::vector <Species> species, RandomRange numberOfPlaces)
	{
		int r_numberOfPlaces = randomInt(numberOfPlaces);
		for (int i = 0; i < r_numberOfPlaces; i++)
		{
			int s = randomInt(RandomRange(0, species.size()));
			Place newPlace(selectRandom(species));
			places.push_back(newPlace);
			//newPlace.printPlace();
		}
		return places;
	}


	void printContinent() {

		std::cout << " " << continentName << ":";
		
		if (ancientSpecies.size() > 0) {
			std::cout << "\n    Ancients: \n       ";
			for (int i = 0; i < ancientSpecies.size(); i++)
			{
				std::cout << ancientSpecies[i].name << "\n       ";
			}
		}

		if (wellNumber > 1)
			std::cout << "\n    A magical essence permiates this land";

		if (places.size() > 0)
		{
			std::cout << "\n    Settlements: \n        ";
			for (int i = 0; i < places.size(); i++)
			{
				std::cout << places[i].name << " a " << places[i].majorDemographic.name << " " << s_GetPlaceType(places[i].placeType);
				std::cout << "\n        ";
			}
		}

		std::cout << "\n";
	}


private:
	std::vector<Species> ancientSpecies;
	int wellNumber;

	std::vector<Place> places;
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
			printf("Name: %s\n  ", continents[i].continentName.c_str());
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
		for (int i = 0; i < numberOfContinents; i++) {
			globalAncients = continents[i].addLocalSpecies(ancientSpecies, RandomRange(0, 3));
			globalPlaces =  continents[i].addPlace(humanoids, RandomRange(0, 3));

			continents[i].printContinent();
		}
	}


	void progressWorldState()
	{

	}


private:
	std::string planetName;

	int numberOfContinents;
	RandomRange* continentsRange;
	Continent* continents;

	RandomRange* ancientSpeciesRange;

	std::vector<Species> globalAncients;
	std::vector<Place> globalPlaces;
};
