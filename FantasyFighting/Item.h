// John Buob
// This is my own work

#ifndef ITEM_H
#define ITEM_H

#include "GameAsset.h"
#include <string>

class Item : public GameAsset
{
private:
	bool isUsed = false;
public:
	Item();
	Item(std::string);
	bool getIsUsed() const;
	void useItem();
	std::string getType();
};

#endif