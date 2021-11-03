#include "Goblin.h"
#include<iostream>
#include"Random.h"
Goblin::Goblin():Monster(70)
{
	Random rand(1, 3, 1);
	selectweapon(rand);
}
Goblin::Goblin(Weapon* const weapon):Monster(weapon,70)
{
}

void Goblin::printbrood() const
{
	std::cout << "°íºí¸°";
}
