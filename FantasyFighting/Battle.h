// John Buob
// This is my own work

#ifndef BATTLE_H
#define BATTLE_H

#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <string>
#include <random>
#include <vector>

class Battle {
private:
	Player player;
	Enemy enemy;
	bool battleOver;
public:
	Battle();
	Battle(Player&);
	Battle(Player&, Enemy);
	Player getPlayer() const;
	Enemy getEnemy() const;
	void setPlayer(Player);
	void setEnemy(Enemy);
	int attack(std::string,Character&);
};

#endif
