#include"Animal.h"
#include"Cat.h"
#include"Dog.h"



//클래스의 상속은
//is -a has -a 관계에 사용

class test;

int main()
{
	//Animal animal("공룡", Animal::Gender::Female, 9, 7, 1);

	Cat cat(
		Cat::Species::Turkish_Angora,
		"초롱이",
		Animal::Gender::Female,
		35.5f,
		15.3f,
		5.45f);

	Dog dog(
		Dog::Species::Welsh_Corgi,
		"아롱이",
		Animal::Gender::Male,
		40.0f,
		17.3f,
		8.47f);

	//abstract 추상클래스의 포인터는 생성 허용
	Animal* const animals[2]  //업 캐스팅
	{						//하위 형식이 상위 형식으로 캐스트
							//반대는 다운캐스트
		&cat,
		&dog
	};

	for (size_t i = 0; i < 2; ++i)
	{
		animals[i]->cry();
	}
	
	return 0;
}

//TODO:가상함수의 구현 원리
//Player 클래스 만들고
//WeaPon{Staff atk5,Bow 3,Sword 10}
//		휘두르기		쏘기		베기
//		5			3		10
// 플레이어의 Attck 함수 호출시
// 각각 무기를 가진 플레이어가 
// 무기에 맞게 공격 모션과 어택값 반환
// 
//