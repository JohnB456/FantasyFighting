// John Buob
// This is my own work

#include "Battle.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyRandomizer.h"
#include "Store.h"
#include <string>
#include <vector>
#include <fstream>

void fight(Player&);
void weaponShop(Player&, Store&);
void rest(Player&);
void playerMenu(Player&);
void save(Player&);

int main()
{
	bool gameQuit = false;
	std::string input = "";
	Player player;

	std::cout << "Welcome are new or a returning player(new or returning): ";
	std::cin >> input;
	std::cout << std::endl;

	if (input == "New" || input == "new")
	{
		std::cout << "What is our Hero's name?: ";
		std::cin >> input;
		std::cout << std::endl;
		player = Player(input);
	}
	else if (input == "Returning" || input == "returning")
	{
		std::fstream fin("Player.txt");
		fin >> player;
	}

	Store store;

	std::cout << "Welcome " << player.getName() << " to Fantasy Fighting!"<< std::endl;
	while (gameQuit == false)
	{
		input = "";
		std::cout << "what do you want to do?" << std::endl;
		std::cout << "Fight" << "/Shop" << "/Rest" << "/Player" << "/Save" << "/Quit" << std::endl;
		std::cout << std::endl;

		std::cin >> input;


		if (input == "Fight" || input == "fight")
		{
			std::cout << std::endl;
			std::cout << std::endl;
			fight(player);
			std::cout << std::endl;
			std::cout << std::endl;
		}

		else if (input == "Shop" || input == "shop")
		{
			std::cout << std::endl;
			std::cout << std::endl;
			weaponShop(player, store);
			std::cout << std::endl;
			std::cout << std::endl;
		}

		else if (input == "Rest" || input == "rest")
		{
			std::cout << std::endl;
			std::cout << std::endl;
			rest(player);
			std::cout << std::endl;
			std::cout << std::endl;
		}

		else if (input == "Player" || input == "player")
		{
			std::cout << std::endl;
			std::cout << std::endl;
			playerMenu(player);
			std::cout << std::endl;
			std::cout << std::endl;
		}

		else if (input == "Save" || input == "save")
		{
			std::cout << std::endl;
			std::cout << std::endl;
			save(player);
			std::cout << std::endl;
			std::cout << std::endl;
		}

		else if (input == "Quit" || input == "quit")
		{
			input = "";
			std::cout << "Do you want to save before quitting?: ";
			std::cin >> input;
			std::cout << std::endl;

			if (input == "Yes" || input == "yes")
				save(player);

			gameQuit = true;
		}
	}
	return 0;
}

void fight(Player& player)
{
	EnemyRandomizer r;
	Enemy enemy = r.randomEnemyBeginneer();
	enemy.setRemainingHealth(enemy.getHealth());
	Battle test(player, enemy);
	std::string input = "";

	bool continueFighting = true;
	std::string characterType = "";
	int damage = 0;
	int expDropped = 0;
	int moneyDropped = 0;
	bool battleOver = false;


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
				std::cout << std::endl;
				std::cout << "Game Over" << std::endl;
				exit(1);
			}
		}


			battleOver = false;
			if (player.getLevel() <= 10)
				enemy = r.randomEnemyBeginneer();
			else if (player.getLevel() > 10 && player.getLevel() < 25)
				enemy = r.randomEnemyMid();
			else if (player.getLevel() > 25)
				enemy = r.randomEnemyEnd();
			enemy.setDeath(false);
			enemy.setRemainingHealth(enemy.getHealth());
		
	}

void weaponShop(Player& p, Store& s)
{
	std::string input = "";
	int index = 0;
	std::cout << "You have " << p.getGold() << " gold." << std::endl;
	s.displayStock();
	std::cout << std::endl;
	std::cout << "Which slot is the weapon you want to buy in?(0 if you can't buy a weapon): ";
	std::cin >> index;
	if (index == 0)
	{
		std::cout << "You chose not to buy a weapon." << std::endl;
	}
	else if (p.getGold() > s.getPrice(index) || p.getGold() == s.getPrice(index))
	{
		p.obtainWeapon(s.sellWeapon(index));
		p.setGold(p.getGold() - s.getPrice(index));
	}
	else
	{
		std::cout << "Sorry you can't buy that." << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Do you want to change your weapon?: ";
	std::cin >> input;
	std::cout << std::endl;

	if (input == "Yes" || input == "yes")
		p.setCurrentWeapon();
	
}

void rest(Player& player)
{
	std::string input = "";
	std::cout << "Welcome to the inn" << std::endl;
	std::cout << "Pay 5 gold to spend the night?: ";
	std::cin >> input;
	if (input == "Yes" || input == "yes")
	{
		std::cout << "You spend the night in the inn" << std::endl;
		std::cout << "You recovered your HP";
		player.setRemainingHealth(player.getHealth());
	}
	else
	{
		std::cout << "You left the inn";
	}

}

void playerMenu(Player& player)
{
	std::string input = "";
	player.displayPlayer();
	std::cout << "Current Weapon: " << player.getCurrentWeaponName() << std::endl;

	std::cout << "Do you want to change your weapon?: ";
	std::cin >> input;
	std::cout << std::endl;
	
	if (input == "Yes" || input == "yes")
		player.setCurrentWeapon();

}

void save(Player& player)
{
	std::fstream fout("Player.txt");
	fout << player;
}