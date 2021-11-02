#pragma once
class Dog :  public Animal
{
public:
	enum  class Species :unsigned char
	{
		Jindo,
		Shiba,
		Maltese,
		Shitzu,
		Welsh_Corgi
	};
public:
	Dog(
		Species     const species,
		std::string const name,
		Gender      const gender,
		float       const length,
		float       const height,
		float       const weight
	);
	~Dog();
	void cry()const;
private:
	Species const species;
};

