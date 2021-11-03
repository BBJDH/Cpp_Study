#pragma once
#include "Weapon.h"
class Bow final :public Weapon
{
public:
	Bow();
private:
	void playmotion()const override;
	void printtype()const override;
};

