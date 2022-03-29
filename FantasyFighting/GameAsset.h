// John Buob
// This is my own work

#ifndef ASSET_H
#define ASSET_H

#include <string>

class GameAsset {
protected:
	std::string name;
public:
	GameAsset();
	GameAsset(std::string);
	std::string getName() const;
	void setName(std::string);
	// virtual std::string getType() = 0;
};

#endif
