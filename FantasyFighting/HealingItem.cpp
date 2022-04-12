// John Buob
// This is my own work

#include "HealingItem.h"

HealingItem::HealingItem() :Item()
{
	healingValue = 0;
}

HealingItem::HealingItem(std::string n, int h) : Item(n)
{
	healingValue = h;
}

int HealingItem::getHealingValue() const
{
	return healingValue;
}

void HealingItem::setHealingValue(int h)
{
	healingValue = h;
}

std::string HealingItem::getType() const
{
	return "HealingItem";
}
