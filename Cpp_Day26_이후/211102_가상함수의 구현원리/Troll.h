#pragma once
#include "Monster.h"
#include"Weapon.h"
class Troll final:public Monster
{
public:
	Troll();
	Troll(Weapon *const weapon);
	void printbrood() const override;
};

