#pragma once
#include "Monster.h"
class Goblin final: public Monster
{
public:
	Goblin();
private:
	Goblin(Weapon* const weapon);
	void printbrood()const override;
};

