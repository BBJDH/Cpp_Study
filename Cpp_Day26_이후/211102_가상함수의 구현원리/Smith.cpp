#include "Smith.h"

#pragma region ���ø� �̻��
//Weapon* const Smith::Create(WeaponName weaponname)
//{
//	switch (weaponname)
//	{
//	case WeaponName::Sword:
//		return new Sword;
//	case WeaponName::Staff:
//		return new Staff;
//	case WeaponName::Bow:
//		return new Bow;
//	}
//
//}
#pragma endregion

template<typename T>
 Weapon* Smith<T>::Create()
{
	return new T;
}
