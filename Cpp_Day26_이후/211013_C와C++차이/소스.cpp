/*
���� ���� ���α׷���
���ν��� : �Լ�(��ɾ��� ����)
���α��� ��� ���α׷���
�߻�ȭ, ���뼺�� �߱�

��ü���� ���α׷���(Object Oriented Programming, OOP)
�߻�ȭ
ĸ��ȭ
 -���� ����
 ���
 ������

*/

#include<iostream>
using namespace std;
struct Test
{
	int i;

	void print()
	{
		cout << i << endl;
	}
};

int main()
{
	Test test;
	test.i = 10;
	test.print();

	sizeof(test);

	Test s;
	s.i = 20; 
	s.print();

	return 0;
}