#include"Animal.h"
#include"Cat.h"
#include"Dog.h"



//Ŭ������ �����
//is -a has -a ���迡 ���

class test;

int main()
{
	//Animal animal("����", Animal::Gender::Female, 9, 7, 1);

	Cat cat(
		Cat::Species::Turkish_Angora,
		"�ʷ���",
		Animal::Gender::Female,
		35.5f,
		15.3f,
		5.45f);

	Dog dog(
		Dog::Species::Welsh_Corgi,
		"�Ʒ���",
		Animal::Gender::Male,
		40.0f,
		17.3f,
		8.47f);

	//abstract �߻�Ŭ������ �����ʹ� ���� ���
	Animal* const animals[2]  //�� ĳ����
	{						//���� ������ ���� �������� ĳ��Ʈ
							//�ݴ�� �ٿ�ĳ��Ʈ
		&cat,
		&dog
	};

	for (size_t i = 0; i < 2; ++i)
	{
		animals[i]->cry();
	}
	
	return 0;
}

//TODO:�����Լ��� ���� ����
//Player Ŭ���� �����
//WeaPon{Staff atk5,Bow 3,Sword 10}
//		�ֵθ���		���		����
//		5			3		10
// �÷��̾��� Attck �Լ� ȣ���
// ���� ���⸦ ���� �÷��̾ 
// ���⿡ �°� ���� ��ǰ� ���ð� ��ȯ
// 
//