// John Buob
// This is my own work
#include "GameAsset.h"

GameAsset::GameAsset()
{
	name = "";
}

GameAsset::GameAsset(std::string n)
{
	name = n;
}

std::string GameAsset::getName() const
{
	return name;
}

void GameAsset::setName(std::string n)
{
	name = n;
}


