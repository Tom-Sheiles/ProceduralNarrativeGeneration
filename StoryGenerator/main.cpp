#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <time.h>
#include "Random.h"

int continentNumber = 0; // put this into include class as well

enum class CreatureType {Humanoid, Monster, Ancient, Elemental, Animal};


class Place {
	// should have subtypes such as city
};


class Species {
public:
	std::string speciesName;
	CreatureType type;

};


class Continent {
public:
	int continentName;

	Continent() {
		continentName = ++continentNumber;
	}

private:
	Place* places;

};


class Planet {

public:

	Planet()
	{
		planetName = "Azeroth"; // This should be random later
		numberOfContinents = randomInt(2, 3); // have global script with variables such as min and max continents

		continents = new Continent[numberOfContinents];
	}

	void printWorldInfo()
	{
		printf("The planet known as %s is comprised of %d continents.\n", planetName.c_str(), numberOfContinents);
		printf("These continents are ");

		for (int i = 0; i < numberOfContinents-1; i++)
		{
			printf("%d, ", continents[i].continentName);
		}
		printf("and %d.\n", continents[numberOfContinents - 1].continentName);
	}

	// Generates Ancients mostly dragons and elementals
	void generatePreHistory()
	{

		
	}

private:
	std::string planetName;
	int numberOfContinents;
	Continent* continents;
	Species* species;

	int numberOfAncients;
};


int main()
{
	srand(time(NULL));

	Planet mainPlanet;
	mainPlanet.printWorldInfo();
}


