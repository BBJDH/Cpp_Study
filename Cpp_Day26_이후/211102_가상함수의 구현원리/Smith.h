#pragma once
#include"Sword.h"
#include"Staff.h"
#include"Bow.h"
class Smith final
{
public:
	enum class WeaponName
	{
		Sword,
		Staff,
		Bow,
	};
	Weapon  * const Create(WeaponName weaponname);
	
};

