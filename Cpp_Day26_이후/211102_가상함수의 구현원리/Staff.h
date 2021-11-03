#pragma once
#include "Weapon.h"
class Staff final:public Weapon
{
public:
	Staff();
private:
	void playmotion()const override;
	void printtype()const override;
};

