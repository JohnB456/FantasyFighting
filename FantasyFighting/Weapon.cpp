// John Buob
// This is my own work

#include "Weapon.h"

Weapon::Weapon() : GameAsset()
{
	damage = 0;
}

Weapon::Weapon(std::string n, int d) : GameAsset(n)
{
	damage = d;
}

int Weapon::getDamage() const
{
	return damage;
}

void Weapon::setDamage(int d)
{
	damage = d;
}