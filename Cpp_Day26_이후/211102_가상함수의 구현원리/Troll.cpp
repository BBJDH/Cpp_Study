#include "Troll.h"
#include<iostream>
#include"Random.h"
Troll::Troll():Monster(200)
{
	Random rand(1, 3, 1);
	selectweapon(rand);
}
Troll::Troll(Weapon * const weapon)
	:Monster(weapon, 200)
{
}

void Troll::printbrood() const
{
	std::cout << "Æ®·Ñ";
}
