#include "Sword.h"
#include<iostream>

Sword::Sword():Weapon(10)
{
}

void Sword::playmotion() const
{
	std::cout << "����!" << std::endl;

}

void Sword::printtype() const
{
	std::cout << "Į";

}
