// John Buob
// This is my own work

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <vector>
#include <iostream>

class Player : public Character
{
private:
	int level, exp, gold;
public:
	Player();
	Player(std::string);
	Player(std::string, int, int, int, int, int);
	int getLevel() const;
	int getExp() const;
	int getGold() const;
	void setLevel(int);
	void setExp(int);
	void setGold(int);
	void levelUp();
	std::string getType() const;
	void displayPlayer();
	friend std::ostream& operator<<(std::ostream&, const Player&);
	friend std::istream& operator>>(std::istream&, Player&);
};

#endif
