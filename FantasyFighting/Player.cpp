// John Buob
// This is my own work

#include "Player.h"

Player::Player():Character()
{
	level = 1;
	exp = 0;
	expNeeded = 20;
	gold = 0;
}

Player::Player(std::string n):Character(n)
{
	level = 1;
	exp = 0;
	expNeeded = 20;
	gold = 0;
}

//Player::Player(std::string, int, int, int, int, int)
//{
//}

int Player::getLevel() const
{
	return level;
}

int Player::getExp() const
{
	return exp;
}

int Player::getExpNeeded() const
{
	return expNeeded;
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

void Player::setExpNeeded(int en)
{
	expNeeded = en;
}

void Player::setGold(int g)
{
	gold = g;
}

void Player::levelUp()
{
	if (exp >= expNeeded)
	{
		++level;
		health += 5;
	}
}

std::string Player::getType() const
{
	return "Player";
}

void Player::displayPlayer()
{
	std::cout << name << std::endl;
	std::cout << "Level: " << level << "\tExp: " << exp << "/" << expNeeded << std::endl;
	std::cout << "Health: " << remainingHealth << "/" << health << std::endl;
	std::cout << "Gold: " << gold << std::endl;
}
