#pragma once
#include <string>

enum class CreatureType { Humanoid, Monster, Ancient, Elemental, Animal, Unknown};
enum class PlaceType { Village, Town, City, SIZE };

std::string s_GetCreatureType() {
	return "TODO";
}

std::string s_GetPlaceType(PlaceType type)
{
	switch (type)
	{
	case PlaceType::Village:
	{
		return "Village";
		break;
	}
	case PlaceType::Town:
	{
		return "Town";
		break;
	}
	case PlaceType::City:
	{
		return "City";
		break;
	}

	default:
		return "Invalid";
		break;
	}
}