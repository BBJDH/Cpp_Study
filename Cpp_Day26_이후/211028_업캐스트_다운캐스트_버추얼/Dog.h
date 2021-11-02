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
	//�����Լ��� �Ļ� ����(Ŭ����)���� �������Ѵ�
	// -> �������̵�
	//�⺻Ŭ������ �ñ״�ó�� ��ġ�ؾ��Ѵ�
	/*virtual*/void cry()const final override;
	//final �� dog �� �Ļ� Ŭ�������� cry ������ �Ұ���
private:
	Species species;
};

