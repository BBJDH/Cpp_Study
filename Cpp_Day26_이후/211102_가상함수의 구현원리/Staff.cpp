#include "Staff.h"
#include<iostream>

Staff::Staff():Weapon(5)
{
}

void Staff::playmotion() const
{
	std::cout << "�ֵθ���!" << std::endl;

}

void Staff::printtype() const
{
	std::cout << "������";
}
