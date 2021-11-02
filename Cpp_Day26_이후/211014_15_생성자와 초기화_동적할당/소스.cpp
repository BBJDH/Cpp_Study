#include<malloc.h>
#include<cstring>
#include<iostream>


class Dog
{
public:
	enum Breed
	{
		Jindo,
		Shiba,
		Samoyed,
		Bulldog
	};


	void PrintDogName()
	{
		std::cout << this->name;
	}

	Dog() : breed(Dog::Jindo), weight(1), height(1), age(1) {};
	//��� �ʱ�ȭ ���
	Dog(Breed const breed, char const* const name, float const height, float const weight, int age)
		: breed(breed), name(nullptr/*_strdup(name)*/), weight(weight), height(height), age(1)   //����� ������ ���ÿ� ����
	{
		//���� ���� ����
		//this->age = age;
		//this->length = length;
		//this->height = height;
		//this->weight = weight;
		//Dog::age = 1;
		//Dog::height = height;
		//Dog::weight = weight;    //�Ѵ� ����

		unsigned size = strlen(name) + sizeof(char);   //strlen �� ���ڿ����� /0�� ī��Ʈ���������Ƿ� �ϳ��� ������ �߰�
		Dog::name = new char[size] {}; //�ش� ���� �ʱ�ȭ

		strcpy_s(Dog::name, size, name);

	}
	~Dog()
	{
		if (Dog::name != nullptr)
			delete Dog::name;
	}
private:
	//Dog* const Parent;
	// (*dog1.parent).parent == dog1.parent->parent �� �θ������� ����





private:
	//private �� �⺻ ���õȴ�
	Breed const breed = Breed::Jindo;
	char* name;
	unsigned		    age;   //unsigned int �� �ڵ� �����, signed �� ����
	float		    height;
	float		    weight;


};


int main()
{
	/*
		���� �ʱ�ȭ (Copy Initialization, =)
		   - �⺻���� �ʱ�ȭ ���
		���� �ʱ�ȭ (Direct Initialization, () )
		   - �ʱ�ȭ�� ���� ���� ���, ��ȣ�� ���� ����
		���� �ʱ�ȭ (Uniform Initialization, {} )
			- Dog dog3{ Dog::Bulldog, 100.0, 3.0};
			  double => int ��  �Ͻ��� ��Һ�ȯ�� ������


	*/
	//Dog dog0;     //Dog dog0() �� �Լ� �������� ������ dog0{}; �� ����
	//Dog dog1(Dog::Bulldog ,1 ,1);
	//Dog dog2 = Dog(Dog::Jindo, 1, 1);
	//Dog dog3{ Dog::Bulldog, 100.0, 3.0};
	//Dog dog4 = { Dog::Bulldog, 100.0, 3.0 };   //�����ڰ� �ֱ⿡ �����ϴ�
	////�ǹ� ��
	//Dog dog5 = Dog(); 
	//Dog dog6
	//{ 
	//	Dog::Bulldog,
	//	100.0,
	//	3.0
	//};
	Dog dog10
	{
		Dog::Samoyed,
		"river",
		100,
		3,
		1,
	};

	dog10.PrintDogName();


	//C ������ �����Ҵ� malloc ��������
	//<malloc.h> �� ����
	//C++ ������ <cstdio>, <cstring> ���� ����
	//windows.h �� ms ���߿����� ���δ�
	//
	// 	   C�� ���� �Ҵ���� ������
	// 
	// 	     - ���� �����ϴ� �������, ����� �߰��� �ʿ䰡 ����.
	// 	     - ����ڰ� ũ�⸦ �˷� �� �ʿ䰡 ����.
	// 	     - �Ҵ��� ������ �����Ϳ� ���� �� ��ȯ(ĳ����)�� ������ �ʿ䰡 ����.
	// 	     - ������ ���Ŀ� ����  ��ü�� ������, �Ҹ��ڰ� ȣ��ȴ�.
	// 	     - ���� ��ü�� �迭�� �Ҵ��ϰ� �����ϴ� ����� �ٸ���.
	// 	  
	// 
	//
	//���� �Ҵ� ��
	{
		int* ip = new int; //�Ǵ� int()
		delete ip;

		int* p_arr = new int[5]{ 0,2,3 };
		delete[] p_arr;
	}

	//int* ip = malloc(4);    //C++ ������ �̷� �Ͻ��� ����ȯ�� �Ұ��ϴ�
	//�׷��ٸ�
	{
		int* ip2 = static_cast<int*>(malloc(4));

		free(ip2);
	}
	// -> static_cast�� �������� ������ ����ȯ�� ����������
	//�߰������� ������ �Ͻ��� ����ȯ�� �����ϴ�
	//����ƽ ĳ��Ʈ�� ����ϴ°� �������� �����ϵ��� �����ش�
	// �߰� �� ��ȣ�� �������� ����ȴ�
	// return(0) ==return 0;
	//sizeof ip �� ���� ������ �ڷ����� �Ұ��� sizeof(int)


	//���� ip�� �ٽ� ���� ������ �ִٸ� �� nullptr�� �ʱ�ȭ�ȴ�
	//�̸� ���� ó���ϱ�����



	return 0;
}