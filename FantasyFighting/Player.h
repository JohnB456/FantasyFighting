// John Buob
// This is my own work

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Item.h"
#include "HealingItem.h"
#include "DamagingItem.h"
#include <vector>

class Player : public Character
{
private:
	int level, exp, gold;
	 std::vector<Item*> items;
public:
	Player();
	Player(std::string);
	Player(std::string, int, int, int, int, int, std::vector<Item*>, std::vector<Weapon>);
	int getLevel() const;
	int getExp() const;
	int getGold() const;
	void setLevel(int);
	void setExp(int);
	void setGold(int);
	void setItems(std::vector<Item*>);
	void levelUp();
	std::string getType() const;
	void displayPlayer();
};

#endif
