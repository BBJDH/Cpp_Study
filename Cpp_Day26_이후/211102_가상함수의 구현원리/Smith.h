#pragma once
#include"Sword.h"
#include"Staff.h"
#include"Bow.h"

#pragma region 템플릿 미사용
//class Smith final
//{
//public:
//	enum class WeaponName
//	{
//		Sword,
//		Staff,
//		Bow,
//	};
//	static Weapon* const Create(WeaponName weaponname);
//};

#pragma endregion
template<typename T>
class Smith final
{
public:
	Weapon * Create();

};
