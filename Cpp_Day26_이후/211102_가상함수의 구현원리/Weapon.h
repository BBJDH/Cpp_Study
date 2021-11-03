#pragma once
//#include"Random.h"
class Weapon abstract //sword staff bow
{
public:
	//weapon 안에서 랜덤 무기 뽑기 가능?
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

