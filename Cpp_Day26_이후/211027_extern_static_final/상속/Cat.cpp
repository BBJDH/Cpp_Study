#include<iostream>
#include"Animal.h"
#include "Cat.h"

Cat::Cat(
	Species     const species,
	std::string const name,
	Gender      const gender,
	float       const length,
	float       const height,
	float       const weight):
	species(species),
	Animal(name,gender,length,height,weight)
{
	std::cout << "Cat Constructor Call" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Call" << std::endl;
}

void Cat::cry()const
{
	std::cout << "¾ß¿Ë!" << std:: endl;
}
