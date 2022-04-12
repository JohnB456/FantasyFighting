#include "Item.h"
// John Buob
// This is my own work

Item::Item():GameAsset()
{
}

Item::Item(std::string n):GameAsset(n)
{
}

bool Item::getIsUsed() const
{
	return false;
}

void Item::useItem()
{
	isUsed = true;
}

std::string Item::getType()
{
	return "Item";
}
