#include "Store.h"
// John Buob
// This is my own work


Store::Store()
{
	stock.push_back(Weapon("Bow", 3));
	stock.push_back(Weapon("Sword", 5));
	stock.push_back(Weapon("Crossbow", 7));
	stock.push_back(Weapon("Greatsword", 10));
	stock.push_back(Weapon("Eagleshot", 12));
	stock.push_back(Weapon("Leecher", 15));
	stock.push_back(Weapon("GrandCross", 20));
	stock.push_back(Weapon("MightyBlade", 30));
	stock.push_back(Weapon("PowerShot", 35));
	stock.push_back(Weapon("GrandBlade", 45));

	prices.push_back(10);
	prices.push_back(12);
	prices.push_back(18);
	prices.push_back(20);
	prices.push_back(25);
	prices.push_back(28);
	prices.push_back(32);
	prices.push_back(35);
	prices.push_back(50);
	prices.push_back(75);
}

void Store::displayStock()
{
	std::cout << "Merchant: What will you buy?" << std::endl;
	for (int n = 0; n < stock.size(); n++)
	{
		std::cout <<  n+1 << ", " << stock[n].getName() << " which does " << stock[n].getDamage() << " damage and costs " << prices[n] << " gold." << std::endl;
	}
}

Weapon Store::sellWeapon(int weaponIndex)
{
	weaponIndex -= 1;
	Weapon soldWeapon = stock[weaponIndex];
	return soldWeapon;
}

int Store::getPrice(int priceIndex)
{
	return prices[priceIndex];
}
