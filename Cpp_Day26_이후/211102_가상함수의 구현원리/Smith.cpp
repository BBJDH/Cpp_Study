#include "Smith.h"

 Weapon  * const Smith::Create(WeaponName weaponname)
{
	switch (weaponname)
	{
		case WeaponName::Sword:
			return new Sword;
		case WeaponName::Staff:
			return new Staff;
		case WeaponName::Bow:
			return new Bow;
	}
	return nullptr;
}
