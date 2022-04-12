// John Buob
// This is my own work
#ifndef HEALING_H
#define HEALING_H

#include "Item.h"
#include <string>

class HealingItem :public Item
{
private:
	int healingValue;
public:
	HealingItem();
	HealingItem(std::string, int);
	int getHealingValue() const;
	void setHealingValue(int);
	std::string getType() const;
};

#endif
