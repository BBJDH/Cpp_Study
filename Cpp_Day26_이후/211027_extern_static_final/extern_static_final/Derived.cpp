#include<iostream>

#include "Base.h"
#include "Derived.h"

namespace  //�ܺο��� �������� �͸��� ���� �����̽� ����
{
	int g = 5;
	//static int g; �� g�� �����Ϸ� �����Ѵ�
	//�Լ��� ��������
	void test()
	{
		std::cout << g << std::endl;
	}
}

void Derived::Print() const
{
	//g =0; ���ο����� ��� ����! 
	std::cout << Get()<< std::endl;
}


