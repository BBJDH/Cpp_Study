#include "Staff.h"
#include<iostream>

Staff::Staff():Weapon(5)
{
}

void Staff::playmotion() const
{
	std::cout << "ÈÖµÎ¸£±â!" << std::endl;

}

void Staff::printtype() const
{
	std::cout << "ÁöÆÎÀÌ";
}
