#pragma once
class Cat :public Animal
{
public:
	enum class Species {
		Turkish_Angora,
		Korean_Shorthair,
		Ragdoll,
		Russian_Blue
	};
public:
	Cat(
		Species     const species,
		std::string const name,
		Gender      const gender,
		float       const length,
		float       const height,
		float       const weight
	);
	~Cat();
	void cry()const;
private: 
	Species species;
};

