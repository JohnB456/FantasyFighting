// John Buob
// This is my own work

#include "Battle.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyRandomizer.h"
#include <string>
#include <vector>
int main()
{
	EnemyRandomizer r;
	std::string input = "";
	std::cout << "What is our Hero's name?: ";
	std::cin >> input;
	std::cout << std::endl;
	Player player(input);
	Enemy enemy = r.randomEnemyBeginneer();
	enemy.setRemainingHealth(enemy.getHealth());
	Battle test(player, enemy);

	bool continueFighting = true;
	std::string characterType = "";
	int damage = 0;
	int expDropped = 0;
	int moneyDropped = 0;
	bool battleOver = false;
	
	while (continueFighting == true)
	{
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
				damage = test.attack(player.getType(), player);
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
				std::cout << std::endl;
				player.levelUp();
				std::cout << std::endl;

				std::cout << "Do you want to see your character's stats?: ";
				input = "";
				std::cin >> input;

				std::cout << std::endl;

				if (input == "Yes" || input == "yes")
				{
					player.displayPlayer();
				}
			}
			else
			{
				if (enemyAction == 1 || enemyAction == 2 || enemyAction == 3 || enemyAction == 4 || enemyAction == 5)
				{
					damage = test.attack(enemy.getType(), enemy);
					if (damage != 0)
					{
						player.setRemainingHealth(player.getRemainHealth() - damage);
						std::cout << player.getName() << " took " << damage << " damage!!" << std::endl;
					}
				}
				else if (enemyAction == 6 || enemyAction == 7 || enemyAction == 8 || enemyAction == 9 || enemyAction == 10)
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

		input = "";
		std::cout << "Do you want to continue fighting?: ";
		std::cin >> input;
		if (input == "Yes" || input == "yes" && player.getRemainHealth() > 0)
		{
			battleOver = false;
			continueFighting = true;
			if (player.getLevel() <= 10)
				enemy = r.randomEnemyBeginneer();
			else if (player.getLevel() > 10 && player.getLevel() < 25)
				enemy = r.randomEnemyMid();
			else if (player.getLevel() > 25)
				enemy = r.randomEnemyEnd();
			enemy.setDeath(false);
			enemy.setRemainingHealth(enemy.getHealth());
		}
		else if(input == "No" || input == "no")
		{
			battleOver = true;
			continueFighting = false;
		}
	}
	return 0;
}