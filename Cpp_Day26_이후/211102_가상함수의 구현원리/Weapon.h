#pragma once
//#include"Random.h"
class Weapon abstract //sword staff bow
{
public:
	//weapon �ȿ��� ���� ���� �̱� ����?
	//Weapon();
	unsigned attack()const;
	virtual void playmotion()const abstract;
	virtual void printtype()const abstract;

protected:
	Weapon(unsigned const atk);

private:
	//void selectweapon(unsigned const weaponnum);
	//Weapon* weapon;
	unsigned atk;

};

