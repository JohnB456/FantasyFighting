// John Buob
// This is my own work

#ifndef STORE_H
#define STORE_H

#include "Weapon.h"
#include <vector>
#include <string>
#include <iostream>

class Store
{
private:
	std::vector<Weapon> stock;
	std::vector<int> prices;
public:
	Store();
	void displayStock();
	Weapon sellWeapon(int);
	int getPrice(int);
};

#endif
