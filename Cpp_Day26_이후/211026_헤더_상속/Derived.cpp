#include<iostream>

#include "Base.h"
#include "Derived.h"
void Derived::Print() const
{
	std::cout << Get()<< std::endl;
}


