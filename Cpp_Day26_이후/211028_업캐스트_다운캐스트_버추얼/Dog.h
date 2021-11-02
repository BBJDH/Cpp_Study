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
	//가상함수를 파생 형식(클래스)에서 재정의한다
	// -> 오버라이드
	//기본클래스의 시그니처와 일치해야한다
	/*virtual*/void cry()const final override;
	//final 시 dog 의 파생 클래스에서 cry 재정의 불가능
private:
	Species species;
};

