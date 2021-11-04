#include<iostream>
#include"Player.h"
#include"Smith.h"
#include"Weapon.h"
#include"Monster.h"
#include"Sword.h"
#include"Staff.h"
#include"Bow.h"
#include"Orc.h"
#include"Troll.h"
#include"Goblin.h"
//??? 이렇게 헤더 줄줄이 있는게 맞나?

#include"Simulation.h"

//컨트롤 유 -> 소문자로
//컨트롤 쉬프트 유 -> 대문자로

int main()
{
	srand(time(NULL));
#pragma region player-weapon 테스트
	//무기 각각의 헤더 필요
	//Bow const*const bow = new Bow;
	//Sword sword;
	//Bow bow;
	//Staff staff;
	//Player player;
	//Weapon *w;

	//player.equip(w);

	//Player player(&sword, 100);
	//player.printweapon();

	//player.printweapon();
	//player = Player(&staff, 100);
	//player.printweapon();


	//randweapon 테스트
	//for (size_t i = 0; i < 8; ++i)
	//{
	//	Player player;
	//	player.printweapon();
	//}
	
#pragma endregion
#pragma region Monster-Weapon 테스트
	//무기 몬스터 각각의 헤더 필요
	//Sword sword;
	//Bow bow;
	//Staff staff;
	//Orc orc(&sword);
	//orc.printbrood();
	//std::cout << std::endl;
	//orc.printweapon();
	//Troll troll(&bow);
	//troll.printbrood();
	//std::cout << std::endl;
	//troll.printweapon();
	//Goblin goblin(&staff);
	//goblin.printbrood();
	//std::cout << std::endl;
	//goblin.printweapon();
	Orc orc;
	printblood(orc);
#pragma endregion

#pragma region 전투 시뮬레이션테스트
	//플레이어무기, 몬스터랜덤생성테스트

		//Simulation simulation;

		//simulation.play();



#pragma endregion
		//typedef unsigned Damage;  타입 통일!

#pragma region Player - Smith 팩토리 테스트

	//이렇게 하면 모든 weapon은 동적할당으로만 생성된다!
	//편하게 소멸자에서 delete 가능
	//Player player;
	//Smith s;
	//player.equip
	//(
	//	s.Create(Smith::WeaponName::Sword)
	//);
	//player.printweapon();
	//player.equip
	//(
	//	s.Create(Smith::WeaponName::Staff)
	//);
	//player.printweapon();
	//player.equip
	//(
	//	s.Create(Smith::WeaponName::Bow)
	//);
	//player.printweapon();

	//std::cout << sizeof(s) << std::endl;
	
#pragma endregion

	

	return 0;
}


