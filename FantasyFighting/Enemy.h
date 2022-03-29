// John Buob
// This is my own work

#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include <random>


class Enemy : public Character
{
private:
	int action = 0;
	int moneyDropped = 0;
	int expDropped = 0 ;
	int mdMin = 0;
	int mdMax = 0;
	int damage = 0;
	void setMoneyDropped();
public:
	Enemy();
	Enemy(std::string, int, int, int, int, int);
	int randomAction();
	std::string getType() const;
	int getMoneyDropped();
	int getExpDropped() const;
	int getDamage();
	int attack();
};

#endif
