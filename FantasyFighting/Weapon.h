// John Buob
// This is my own work

#ifndef WEAPON_H
#define WEAPON_H

#include "GameAsset.h"
#include <string>

class Weapon : public GameAsset{
private:
	int damage;
public:
	Weapon();
	Weapon(std::string, int);
	int getDamage() const;
	void setDamage(int);
};

#endif
