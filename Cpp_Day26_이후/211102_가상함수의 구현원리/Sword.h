#pragma once
#include "Weapon.h"
class Sword final: public Weapon
{
public:
	Sword();
private:
	void playmotion()const override;
	void printtype()const override;
};

