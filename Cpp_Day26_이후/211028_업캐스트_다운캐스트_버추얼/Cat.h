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
	//가상함수를 파생 형식(클래스)에서 재정의한다
// -> 오버라이드
	void cry()const override;
private: 
	Species species;
};

