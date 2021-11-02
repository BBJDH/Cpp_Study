#include"Animal.h"
#include"Cat.h"
#include"Dog.h"

int main()
{
	Cat c1(
		Cat::Species::Turkish_Angora,
		"√ ∑’¿Ã",
		Animal::Gender::Female,
		35.5f,
		15.3f,
		5.45f);


	c1.cry();


	Dog d1(
		Dog::Species::Welsh_Corgi,
		"æ∆∑’¿Ã",
		Animal::Gender::Male,
		40.0f,
		17.3f,
		8.47f);

	d1.cry();

	return 0;
}