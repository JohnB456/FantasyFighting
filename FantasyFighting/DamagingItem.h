// John Buob
// This is my own work

#ifndef DAMAGING_H
#define DAMAGING_H

#include "Item.h"
#include <string>

class DamagingItem :public Item
{
private:
	int damageValue;
public:
	DamagingItem();
	DamagingItem(std::string, int);
	int getDamageValue() const;
	void setDamageValue(int);
	std::string getType() const;
};

#endif