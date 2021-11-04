#include<iostream>
#include<Windows.h>
#include "Monster.h"
#include"Bow.h"
#include"Staff.h"
#include"Sword.h"



Monster::Monster(unsigned const hp):weapon(nullptr),hp(hp)
{
}

Monster::Monster(Weapon  *const weapon, unsigned const hp)
	:weapon(weapon),hp(hp)
{
}

void Monster::printweapon() const
{
	std::cout << "�����̸� : ";
	weapon->printtype();
	std::cout << std::endl;
	std::cout << "������ : " << weapon->attack() << std::endl;
}

void Monster::takedamege(unsigned const damege)
{
	if (damege > hp)
	{
		hp = 0;
		return;
	}
	hp -= damege;
}

void Monster::selectweapon(unsigned const weaponnum)
{
	switch (weaponnum)
	{
	case 1:
	{
		weapon = new Sword;
		break;
	}
	case 2:
	{
		weapon = new Staff;
		break;
	}
	case 3:
	{
		weapon = new Bow;
		break;
	}

	}
}

void Monster::printstat() 
{
	movecursor(20, 0);
	std::cout << "<<����>>" << std::endl;
	movecursor(20, 1);

	std::cout << "���� : ";
	printbrood();
	std::cout << std::endl;
	movecursor(20, 2);

	std::cout << "���� : ";
	weapon->printtype();
	std::cout << std::endl;
	movecursor(20, 3);

	std::cout << "���ݷ� : " << weapon->attack() << std::endl;
	movecursor(20, 4);

	std::cout << "ü�� : " << hp << std::endl;
}
int Monster::attack() const
{
	return weapon->attack();
}
bool Monster::islive() const
{
	if(hp>0)
		return true;
	return false;
}
void Monster::movecursor(short x, short y)
{
	COORD position = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}


//void Monster::selectbrood(unsigned const broodnum)
//{
//	switch (broodnum)
//	{
//	case 1:
//	{
//		monster = new Orc;
//		break;
//	}
//	case 2:
//	{
//		monster = new Troll;
//		break;
//	}
//	case 3:
//	{
//		monster = new Goblin;
//		break;
//	}
//
//	}
//}
