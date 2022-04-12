// John Buob
// This is my own work

#include "DamagingItem.h"

DamagingItem::DamagingItem() :Item()
{
	damageValue = 0;
}

DamagingItem::DamagingItem(std::string n, int d) : Item(n)
{
	damageValue = d;
}

int DamagingItem::getDamageValue() const
{
	return damageValue;
}

void DamagingItem::setDamageValue(int d)
{
	damageValue = d;
}

std::string DamagingItem::getType() const
{
	return "DamagingItem";
}