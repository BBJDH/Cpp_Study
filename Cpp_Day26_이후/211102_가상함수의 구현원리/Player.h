#pragma once
#include"Weapon.h"

class Player
{
public:
	Player();
	Player(Weapon  const*const  weapon,int const hp);
	void equip(Weapon const *const  weapon);
	void printweapon()const;
	void takedamege(int const damege);
	void printstat()const;
	int  attack()const;
	bool islive()const;
	~Player();
private:
	void selectweapon(unsigned const weaponnum);
	Weapon const* weapon;
	unsigned hp;
};

