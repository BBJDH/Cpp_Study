#include<iostream>
#include"Base.h"  //�ش� ���� �������� ������� Ž��
//#include"Base.cpp" �� ���� ������ ��Ŀ�� �̾��ش�
int main()
{
	using namespace std;
	{
		Base b;

		b.Set(5);
		cout << b.Get() << endl;
	}
	
	return 0;
}