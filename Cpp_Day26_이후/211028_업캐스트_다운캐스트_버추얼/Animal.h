#pragma once
#include<string>

class Animal abstract //abstract �� �Ʒ����� �����ȴ�
{						// �� Ŭ���������� ��ü �����Ұ���
public:					//�̷� �߻�Ŭ������ �����ͻ����� ����
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
	//�����Լ��� cry ����
	virtual  void cry() const abstract;
	//�Ǵ� virtual  void cry()const =0 ;
	//���������Լ��� �ϳ��� ������ Ŭ������
	//�߻�Ŭ������ �ν��Ͻ� ������ ���ѵȴ�
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