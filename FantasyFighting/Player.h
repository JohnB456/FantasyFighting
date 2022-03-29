// John Buob
// This is my own work

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public Character
{
private:
	int level, exp, expNeeded, gold;
	// vector<Item> items;
public:
	Player();
	Player(std::string);
	//Player(std::string, int, int, int, int, int, vector<Item>);
	int getLevel() const;
	int getExp() const;
	int getExpNeeded() const;
	int getGold() const;
	// vector<Item> getItems() const;
	void setLevel(int);
	void setExp(int);
	void setExpNeeded(int);
	void setGold(int);
	// void setItems(vector<Item>);
	void levelUp();
	std::string getType() const;
	void displayPlayer();
};

#endif
