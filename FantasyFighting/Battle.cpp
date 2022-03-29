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

void Battle::startBattle()
{
	std::string characterType = "";
	int damage = 0;
	int expDropped = 0;
	int moneyDropped = 0;
	while (battleOver == false)
	{
		int enemyAction = enemy.randomAction();
		std::string playerChoice = "";
			std::cout << player.getName() << " HP: " << player.getRemainHealth() << "/" << player.getHealth() << "\t\t" << enemy.getName() << " HP: " << enemy.getRemainHealth() << "/" << enemy.getHealth() << std::endl;
			std::cout << "What will you do (Attack or Nothing): ";
			std::cin >> playerChoice;
			if (playerChoice == "Attack" || playerChoice == "attack")
			{
				std::cout << std::endl;
				damage = attack(player.getType(), player);
				if (damage != 0)
				{
					enemy.setRemainingHealth(enemy.getRemainHealth() - damage);
					std::cout << enemy.getName() << " took " << damage << " damage!!" << std::endl;
				}
			}
			else if (playerChoice == "Nothing" || playerChoice == "nothing")
			{
				std::cout << std::endl;
				std::cout << player.getName() << " did nothing" << std::endl;
			}
			std::cout << std::endl;
		enemy.checkHealth();
		if (enemy.isCharacterDead() == true)
		{
			int expDropped = enemy.getExpDropped();
			int moneyDropped = enemy.getMoneyDropped();
			std::cout << enemy.getName() << " has fallen" << std::endl;
			std::cout << player.getName() << " gained " << expDropped << " exp" << std::endl;
			player.setExp(player.getExp() + expDropped);
			std::cout << player.getName() << " earned " << moneyDropped << " gold" << std::endl;
			player.setGold(player.getGold() + moneyDropped);
			battleOver = true;
		}
		else
		{
			if (enemyAction == 1 || enemyAction == 2 || enemyAction == 3 || enemyAction == 4 || enemyAction == 5 || enemyAction == 6 || enemyAction ==  7)
			{
				damage = attack(enemy.getType(), enemy);
				if (damage != 0)
				{
					player.setRemainingHealth(player.getRemainHealth() - damage);
					std::cout << player.getName() << " took " << damage << " damage!!" << std::endl;
				}
			}
			else if (enemyAction == 8 || enemyAction == 9 || enemyAction == 10)
			{
				std::cout << enemy.getName() << " is staring" << std::endl;
			}
			std::cout << std::endl;
		}
		player.checkHealth();
		if (player.isCharacterDead() == true)
		{
			std::cout << "Sorry hero you have fallen" << std::endl;
			battleOver = true;
		}
		
		
		
	}

	
	player.displayPlayer();
}
