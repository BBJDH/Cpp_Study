#pragma once
#include "Weapon.h"
class Monster abstract //Ʈ�� ��ũ ���
{
public:
	//Monster(); 
	void printweapon()const;
	virtual void printbrood()const abstract;

	void takedamege(unsigned const damage);
	void printstat();
	int attack()const;
	bool islive()const;
protected:
	Monster(unsigned const hp);
	Monster(Weapon  *const weapon, unsigned const hp);
	void selectweapon(unsigned const weaponnum);

private:
	void movecursor(short x, short y);

	//void selectbrood(unsigned const broodnum);
	//Monster* monster;
	Weapon * weapon;
	unsigned hp;
};

