// John Buob
// This is my own work

#ifndef ENEMYRAND_H
#define ENEMYRAND_H

#include "Enemy.h"
#include <vector>

class EnemyRandomizer {
private:
	std::vector<Enemy> enemies = {
	Enemy("Chicken", 1, 0, 0, 0, 0),
	Enemy("Slime", 5, 5, 1, 10, 1),
	Enemy("Skeleton", 10, 5, 5, 20, 2),
	Enemy("Mage", 8, 4, 11, 15, 2),
	Enemy("Goblin", 7, 2, 10, 15, 2),
	Enemy("Bat", 3, 1, 1, 3, 1),
	Enemy("Ghost", 10, 6, 7, 9, 2),
	Enemy("Zombie", 12, 6, 10, 15, 2),
	Enemy("Snake Warrior", 12, 10, 10, 15, 2),
	Enemy("Golemite", 15, 7, 20, 25, 3),
	Enemy("Troll Warrior", 20, 10, 20, 25, 3),
	Enemy("Baby Dragon", 30, 25, 30, 35, 4),
	Enemy("Golem", 30, 25, 30, 45, 4),
	Enemy("Dark Knight", 25, 16, 45, 55, 4),
	Enemy("Orge", 60, 30, 70, 80, 6),
	Enemy("Wraith", 35, 18, 25, 35, 4),
	Enemy("Necromancer", 40, 22, 30, 39, 4),
	Enemy("Treasure Slime", 20, 20, 25, 50, 1),
	Enemy("Treasure Goblin", 28, 20, 30, 60, 2),
	Enemy("Treasure Golemite", 60, 30, 75, 100, 3),
	};
public:
	EnemyRandomizer();
	Enemy randomEnemyBeginneer();
	Enemy randomEnemyMid();
	Enemy randomEnemyEnd();
};

#endif

EnemyRandomizer::EnemyRandomizer() {}

Enemy EnemyRandomizer::randomEnemyBeginneer()
{
	srand(time(NULL));
	int chosenEnemy = rand() % 5 + 1;
	Enemy enemy = enemies[chosenEnemy];
	return enemy;
}

inline Enemy EnemyRandomizer::randomEnemyMid()
{
	srand(time(NULL));
	int chosenEnemy = rand() % 9 + 7;
	Enemy enemy = enemies[chosenEnemy];
	return enemy;
}

inline Enemy EnemyRandomizer::randomEnemyEnd()
{
	srand(time(NULL));
	int chosenEnemy = rand() % 20 + 10;
	Enemy enemy = enemies[chosenEnemy];
	return enemy;
}
