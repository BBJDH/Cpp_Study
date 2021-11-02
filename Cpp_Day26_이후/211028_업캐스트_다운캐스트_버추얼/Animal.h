#pragma once
#include<string>

class Animal abstract //abstract 더 아래에서 구현된다
{						// 현 클래스형식의 개체 생성불가능
public:					//이런 추상클래스의 포인터생성은 가능
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
	//가상함수로 cry 선언
	virtual  void cry() const abstract;
	//또는 virtual  void cry()const =0 ;
	//순수가상함수를 하나라도 도함한 클래스는
	//추상클래스로 인스턴스 생성이 제한된다
	void eat()const;
	void sleep()const;


private:
	
	Gender       gender;
	std::string  name;
	unsigned     age;
	float        length;
	float        height;
	float        weight;
};