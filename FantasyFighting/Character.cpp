// John Buob
// This is my own work

#include "Character.h"

Character::Character()
{
	name = "";
	health = 10;
	remainingHealth = health;
	weaponList.push_back(new Weapon("Fists", 1));
	currentWeapon = *weaponList[0];
}

Character::Character(std::string n)
{
	name = n;
	health = 10;
	remainingHealth = health;
	weaponList.push_back(new Weapon("Fists", 1));
	currentWeapon = *weaponList[0];
}

Character::Character(std::string n, int h)
{
	name = n;
	health = h;
}

Character::Character(std::string n, int h, int rh)
{
	name = n;
	health = h;
	remainingHealth = rh;
	weaponList.push_back(new Weapon("Fists", 1));
	currentWeapon = *weaponList[0];
}

Character::~Character()
{
	for (int n = weaponList.size() - 1; n >= 0; n--)
	{
		delete weaponList[n];
	}
}

std::string Character::getName() const
{
	return name;
}

int Character::getHealth()
{
	return health;
}

int Character::getRemainHealth() const
{
	return remainingHealth;
}

bool Character::isCharacterDead() const
{
	return isDead;
}

std::string Character::getCurrentWeaponName() const
{
	return currentWeapon.getName();
}

void Character::setName(std::string n)
{
	name = n;
}

void Character::setHealth(int h)
{
	health = h;
}

void Character::setRemainingHealth(int rh)
{
	remainingHealth = rh;
}

void Character::IsHoldingItem()
{
	if (isHoldingItem)
	{
		std::cout << "Yes" << std::endl;
	}
	else
	{
		std::cout << "No" << std::endl;
	}
}

int Character::attack()
{
	int damage{};
	if (isHoldingItem)
	{
		damage = currentWeapon.getDamage();
	}
	if(!isHoldingItem) {
	damage = 1;
	}
	return damage;
}

void Character::checkHealth()
{
	if (remainingHealth <= 0)
	{
		remainingHealth = 0;
		isDead = true;
	}
}

void Character::showWeapons() const
{
	for (int i = 0; i < weaponList.size(); i++)
	{
		Weapon weaponSlot = *weaponList[i];
		std::cout << i + 1 << ", " << weaponSlot.getName() << " which does " << weaponSlot.getDamage() << " damage." << std::endl;
	}
}

void Character::obtainWeapon(Weapon w)
{
	std::cout << name << " has obtained a " << w.getName() << " which does " << w.getDamage() << " damage." << std::endl;
	std::cout << std::endl;
	weaponList.push_back(new Weapon(w.getName(), w.getDamage()));
	
}

void Character::setCurrentWeapon()
{
	std::cout << "Current weapon being used is " << currentWeapon.getName() << "." << std::endl;
	int selectedWeapon = 0;
	showWeapons();
	std::cout << "Select Weapon: ";
	std::cin >> selectedWeapon;
	currentWeapon = *weaponList[--selectedWeapon];
	std::cout << currentWeapon.getName() << " is now equipped" << std::endl;
	if (currentWeapon.getName() == "Fists")
	{
		isHoldingItem = false;
	}
	else
	{
		isHoldingItem = true;
	}
}

void Character::setDeath(bool d)
{
	isDead = d;
}
