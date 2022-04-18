// John Buob
// This is my own work

#include "Player.h"

Player::Player():Character()
{
	level = 1;
	exp = 0;
	gold = 0;
}

Player::Player(std::string n):Character(n)
{
	level = 1;
	exp = 0;
	gold = 0;
}

Player::Player(std::string n, int h, int rh, int l, int ep, int g):Character(n,h,rh)
{
	level = l;
	exp = ep;
	gold = g;
}

int Player::getLevel() const
{
	return level;
}

int Player::getExp() const
{
	return exp;
}

int Player::getGold() const
{
	return gold;
}

void Player::setLevel(int l)
{
	level = l;
}

void Player::setExp(int e)
{
	exp = e;
}

void Player::setGold(int g)
{
	gold = g;
}

void Player::levelUp()
{
	if (exp >= 100)
	{
		std::cout << "You leveled up!" << std::endl;
		std::cout << std::endl;
		level++;
		setHealth(12);
		setRemainingHealth(12);
		exp -= 100;
	}
}

std::string Player::getType() const
{
	return "Player";
}

void Player::displayPlayer()
{
	std::cout << name << std::endl;
	std::cout << "Level: " << level << "\tExp: " << exp << std::endl;
	std::cout << "Health: " << remainingHealth << "/" << health << std::endl;
	std::cout << "Gold: " << gold << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Player& rhs)
{
	out << rhs.name;
	out << rhs.health;
	out << rhs.remainingHealth;
	out << rhs.level;
	out << rhs.exp;
	out << rhs.gold;
	return out;
}

std::istream& operator>>(std::istream& in, Player& rhs)
{
	in >> rhs.name;
	in >> rhs.health;
	in >> rhs.remainingHealth;
	in >> rhs.level;
	in >> rhs.exp;
	in >> rhs.gold;
	return in;
}
