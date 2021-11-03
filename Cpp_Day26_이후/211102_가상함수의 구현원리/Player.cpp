#include<iostream>
#include "Player.h"
#include"Sword.h"
#include"Bow.h"
#include"Staff.h"
#include"Random.h"
Player::Player():hp(100)
{
	Random randweapon(1, 3, 1); //1~3���� 1�� �ߺ���������
	selectweapon(randweapon); //random�� int ����ȯ �����ε�
								//int ����ȯ �����ε��� ������� ���� �Ѱ��϶�������
}

Player::Player(Weapon const*const weapon, int const hp)
	:weapon(weapon),hp(hp)
{
}

void Player::equip(Weapon const *const  weapon)
{
	this->weapon = weapon;
}

void Player::printweapon() const
{
	std::cout << "�����̸� : ";
	weapon->printtype();
	std::cout << std::endl;
	std::cout << "������ : " << weapon->attack() << std::endl;
	weapon->playmotion();
}

void Player::takedamege(int const damege)
{
	if (damege > hp)
	{
		hp = 0;
		return;
	}
	hp -= damege;
}

void Player::printstat() const
{
	std::cout << "<<�÷��̾�>>" << std::endl;
	std::cout << "���� : ";
	weapon->printtype();
	std::cout << std::endl;
	std::cout << "���ݷ� : " << weapon->attack() << std::endl;
	std::cout << "ü�� : " << hp << std::endl;

}

int Player::attack() const
{
	return 	weapon->attack();
	
}

bool Player::islive() const
{
	if(hp>0)
		return true;
	return false;
}

Player::~Player()
{
	//if (weapon != nullptr)
	//	delete weapon;
}

void Player::selectweapon(unsigned const weaponnum)
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
