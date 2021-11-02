#include <iostream>
//#include<string>
#include "Animal.h"
#pragma once

Animal::Animal(
	std::string const name,
	Gender      const gender,
	float       const length, 
	float       const height,
	float       const weight
): 
	  name(  name),
	gender(gender),
	   age(     0),
	length(length),
	height(height),
	weight(weight)
{
	std::cout << "Animal Constructor Call" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor Call" << std::endl;
}

void Animal::cry()const
{
}

void Animal::eat()const
{
	std::cout << "Eat well" << std::endl;
}

void Animal::sleep()const
{
	std::cout << "Sleep well" << std::endl;
}
