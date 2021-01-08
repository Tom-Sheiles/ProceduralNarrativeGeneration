#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <time.h>


int continentNumber = 0; // put this into include class as well

int randomInt(int min, int max)
{
	return rand() % max + min;
}

float randomFloat(float min, float max)
{
	return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}


class Kingdom {

};


class CreatureType {

};


class Continent {
public:
	int continentName;

	Continent() {
		continentName = ++continentNumber;
	}
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


private:
	std::string planetName;
	int numberOfContinents;
	Continent* continents;

};


int main()
{
	srand(time(NULL));

	Planet mainPlanet;
	mainPlanet.printWorldInfo();

}