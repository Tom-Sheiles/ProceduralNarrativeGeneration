#pragma once
#include <iostream>
#include <string>
#include "GlobalVariables.h"

class Place {
public:
	std::string name;
	Species majorDemographic;
	PlaceType placeType;

	Place(Species majorDemographic) {
		this->name = randomInt(RandomRange(0, 100));
		this->majorDemographic = majorDemographic;
		this->placeType = (PlaceType)randomInt(RandomRange(0, (int)PlaceType::SIZE));
	}

	void printPlace() {
		std::cout << "Name: " << name << " Demographic: " << majorDemographic.name << " " << s_GetPlaceType(placeType) << "\n";
	}
};
