#pragma once
#include "Monster.h"
#include"Weapon.h"
class Orc final: public Monster
{
public:
	Orc();
	Orc(Weapon*const weapon);
private:
	void printbrood()const override;
};

