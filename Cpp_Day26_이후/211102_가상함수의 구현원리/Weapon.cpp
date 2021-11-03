#include "Weapon.h"
//#include"Random.h"
//#include"Sword.h"
//#include"Staff.h"
//#include"Bow.h"

//Weapon::Weapon()
//{
//	Random rand(1, 3, 1);
//	selectweapon(rand);
//}

Weapon::Weapon(unsigned const atk):atk(atk)
{
}



unsigned Weapon::attack() const
{
    return atk;
}

//void Weapon::selectweapon(unsigned const weaponnum)
//{
//	switch (weaponnum)
//	{
//		case 1:
//		{
//			weapon = new Sword;
//			break;
//		}
//		case 2:
//		{
//			weapon = new Staff;
//			break;
//		}
//		case 3:
//		{
//			weapon = new Bow;
//			break;
//		}
//
//	}
//}