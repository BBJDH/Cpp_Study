#include<iostream>
#include"Base.h" 
#include"Derived.h"

extern int g;  //�ٸ� cpp�� g�� ������ ����
//external �ܺ���
//static ������
extern void test();
//��ȹ�Ȱ��� �ƴ϶�� ��򰡿� �����Ͽ�(extern) ����Ұ��
//�������� ���鿡�� �Ҹ��ϴ�
//�ܺο��� ���³����� �� Ǯ��� ���°� �Ҹ��ϴ�
void test2()
{
	static int i = 0; 
	std::cout << ++i << std::endl;
}
//���� �ȿ����� static �� �����Լ��ȿ��� ��� �����Ѵ�
//���α׷������ ���� �����Ǹ�,
//���� ���� �ٸ� �ܺ��Լ����� ������ �Ұ����ϴ�.



//�Լ��� ���� �ص� extern�� �ڵ� �����
int main()
{
	for(size_t i =0; i<5; ++i)
		test2();
	//g = 0;
	//std::cout << g << std::endl;
	//
	
	return 0;
}