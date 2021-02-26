#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "GlobalVariables.h"
#include "Util.h"


struct Species {
	std::string name;
	CreatureType type;
	unsigned int speciesID;

	Species(std::string name = "!!MissingName!!", CreatureType type = CreatureType::Unknown) {
		this->name = name;
		this->type = type;

		speciesID = util_HashString(name.c_str());
	}
};


std::vector<Species> g_Species = {
	{"Dragon", CreatureType::Ancient},
	{"Elemental", CreatureType::Ancient},
	{"Human", CreatureType::Humanoid},
	{"Night Elf", CreatureType::Humanoid},
	{"High Elf", CreatureType::Humanoid},
	{"Orc", CreatureType::Humanoid},
	{"Dwarf", CreatureType::Humanoid},
	{"Troll", CreatureType::Humanoid},
	{"Goblin", CreatureType::Humanoid},
	{"Demon", CreatureType::Monster}
};


void printSpeciesVector(const std::vector<Species> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << "ID: " << v[i].speciesID << " NAME: " << v[i].name << "\n";
	}
}
