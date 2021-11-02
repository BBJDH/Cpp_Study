#pragma once
#include<string>

class Animal
{
public:
	enum class Gender
	{
		Male,
		Female
	};

public:

	Animal(
		std::string const name,
		Gender      const gender, 
		float       const length, 
		float       const height, 
		float       const weight
	);
	~Animal();

	void cry()const;
	void eat()const;
	void sleep()const;


private:
	
	Gender const gender;
	std::string  name;
	unsigned     age;
	float        length;
	float        height;
	float        weight;
};