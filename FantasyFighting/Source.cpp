// John Buob
// This is my own work

#include "Battle.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyRandomizer.h"
int main()
{
	//EnemyRandomizer r;
	Player player("Jack");
	Weapon w("Sword", 5);
	player.obtainWeapon(w);
	player.setCurrentWeapon();
	//Battle test(player);
	//test.startBattle();

	return 0;
}