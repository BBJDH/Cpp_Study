#include<iostream>
#include"Base.h"  //�ش� ���� �������� ������� Ž��
//#include"Base.cpp" �� ���� ������ ��Ŀ�� �̾��ش�
#include"Derived.h"
//TODO: ����� ���� ������ �뵵
//TODO: ��� �߰� ����
int main()
{
	using namespace std;
	{
		Base b;

		b.Set(5);
		cout << b.Get() << endl;
	}
	{
		Derived d;
		d.Print();
	}
	
	return 0;
}