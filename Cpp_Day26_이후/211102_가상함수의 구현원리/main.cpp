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
//??? �̷��� ��� ������ �ִ°� �³�?

#include"Simulation.h"

//��Ʈ�� �� -> �ҹ��ڷ�
//��Ʈ�� ����Ʈ �� -> �빮�ڷ�

int main()
{
	srand(time(NULL));
#pragma region player-weapon �׽�Ʈ
	//���� ������ ��� �ʿ�
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


	//randweapon �׽�Ʈ
	//for (size_t i = 0; i < 8; ++i)
	//{
	//	Player player;
	//	player.printweapon();
	//}
	
#pragma endregion
#pragma region Monster-Weapon �׽�Ʈ
	//���� ���� ������ ��� �ʿ�
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

#pragma region ���� �ùķ��̼��׽�Ʈ
	//�÷��̾��, ���ͷ��������׽�Ʈ

		//Simulation simulation;

		//simulation.play();



#pragma endregion
		//typedef unsigned Damage;  Ÿ�� ����!

#pragma region Player - Smith ���丮 �׽�Ʈ

	//�̷��� �ϸ� ��� weapon�� �����Ҵ����θ� �����ȴ�!
	//���ϰ� �Ҹ��ڿ��� delete ����
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


