#include<iostream>
#include "Orc.h"
#include"Random.h"
#pragma once
Orc::Orc():Monster(100)
{
	Random rand(1, 3, 1);
	selectweapon(rand);
}
Orc::Orc(Weapon*const weapon):Monster(weapon,100)
{
}
void Orc::printbrood() const
{
	std::cout << "¿ÀÅ©";
}
