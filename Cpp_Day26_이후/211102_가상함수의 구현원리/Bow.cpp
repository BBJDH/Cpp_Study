#include "Bow.h"
#include<iostream>
Bow::Bow():Weapon(3)
{
}
void Bow::playmotion() const
{
	std::cout << "½î±â!" << std::endl;
}

void Bow::printtype() const
{
	std::cout << "È°";
}
