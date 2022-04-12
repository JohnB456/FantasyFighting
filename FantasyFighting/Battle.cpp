#include "Battle.h"

Battle::Battle()
{
	player = Player("Bob");
	battleOver = false;
}

Battle::Battle(Player& p)
{
	player = p;
	enemy = Enemy("Slime", 5, 5, 1, 10, 1);
}

Battle::Battle(Player& c, Enemy e)
{
	player = c;
	enemy = e;
	battleOver = false;
}

Player Battle::getPlayer() const
{
	return player;
}

Enemy Battle::getEnemy() const
{
	return enemy;
}

void Battle::setPlayer(Player p)
{
	player = p;
}

void Battle::setEnemy(Enemy e)
{
	enemy = e;
}



int Battle::attack(std::string ct, Character& c)
{
	srand(time(NULL));
	int chance = 0;
	int damage = 0;
	if (ct == "Player")
	{
		chance = rand() % 10 + 1;

		if (chance == 1 || chance == 2)
		{
			std::cout << c.getName() << " missed" << std::endl;
		}
		else if (chance == 10)
		{
			damage = c.attack() * 2;
			std::cout << c.getName() << " dealt " << damage << " damage with a critical hit!" << std::endl;
		}
		else
		{
			damage = c.attack();
			std::cout << c.getName() << " dealt " << damage << " damage!" << std::endl;
		}
	}
	else if (ct == "Enemy")
	{
		chance = rand() % 10 + 1;

		if (chance == 1 || chance == 2)
		{
			std::cout << c.getName() << " missed" << std::endl;
		}
		else if (chance == 10)
		{
			damage = c.attack() * 2;
			std::cout << c.getName() << " dealt " << damage << " damage with a critical hit!" << std::endl;
		}
		else
		{
			damage = c.attack();
			std::cout << c.getName() << " dealt " << damage << " damage!" << std::endl;
		}
		
	}
	return damage;
}
