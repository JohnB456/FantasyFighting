// John Buob
// This is my own work

#include "Enemy.h"



Enemy::Enemy() : Character()
{
	expDropped = 1;
	action = 0;
}

Enemy::Enemy(std::string n , int h, int ed, int mdMin, int mdMax, int d) : Character(n,h)
{
	this->mdMin = mdMin;
	this->mdMax = mdMax;
	expDropped = ed;
	damage = d;
	action = 0;
}

void Enemy::setMoneyDropped()
{
	moneyDropped = rand() % mdMin + mdMax;
}

int Enemy::randomAction()
{
	srand(time(NULL));
	action = rand() % 10 + 1;
	return action;
}

int Enemy::getMoneyDropped()
{
	setMoneyDropped();
	return moneyDropped;
}

int Enemy::getExpDropped() const
{
	return expDropped;
}

int Enemy::getDamage()
{
	return damage;
}

std::string Enemy::getType() const
{
	return "Enemy";
}

int Enemy::attack()
{
	return damage;
}

