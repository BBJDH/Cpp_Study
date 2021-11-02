#include<iostream>
#include"Animal.h"
#include "Dog.h"

Dog::Dog(
	Species     const species,
	std::string const name,
	Gender      const gender,
	float       const length,
	float       const height,
	float       const weight
	): species(species),
	Animal(name,gender,length,height,weight)
{
	std::cout << "Dog Constructor Call" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor Call" << std::endl;
}

void Dog::cry() const
{
	std::cout << "¸Û¸Û!" << std::endl;
	//std::cout <<Dog::cry << std::endl;
}
