// John Buob
// This is my own work

#ifndef CHARACTER_H
#define CHARACTER_H

#include "Weapon.h"
#include <string>
#include <vector>
#include <iostream>

class Character {
protected:
	std::string name;
	int health;
	int remainingHealth;
private:
	std::vector<Weapon*> weaponList;
	Weapon currentWeapon;
	bool isDead;
	bool isHoldingItem;
public:
	Character();
	Character(std::string);
	Character(std::string, int);
	Character(std::string, int, int, std::vector<Weapon>);
	~Character();
	std::string getName() const;
	int getHealth();
	int getRemainHealth() const;
	bool isCharacterDead() const;
	std::string getCurrentWeaponName() const;
	void setName(std::string);
	void setHealth(int h);
	void setRemainingHealth(int);
	void setCurrentWeapon();
	void setDeath(bool);
	void IsHoldingItem();
	virtual int attack();
	void checkHealth();
	void obtainWeapon(const Weapon);
	virtual std::string getType() const = 0;
};

#endif
