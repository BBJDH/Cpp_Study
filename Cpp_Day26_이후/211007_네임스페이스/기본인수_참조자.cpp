#include<iostream>

using namespace std;// �����Ѱ� ���ĺ��� ���ӽ����̽��� ����ȴ�
// ���� ȸ���� �Ұ���

/*
	�⺻ �μ�(Default Argument)

	�Լ��� ���ڿ� �⺻ ���� �ο��ϴ� ���
	���� ����� ������ ���ں��� �ο��� �� �ִ�.

	�����ε��� �Բ� ����� ���, ȣ���� ��ȣ�� ������ �߻��� �� ������,
	���� ������ ���� ����� ������ ���ڷκ��� �ο��ؾ��Ѵٴ� ��Ģ�� �ִ�.

*/
//void Square(int* const operand, int const count)
//{
//	for (int i = 0; i < count; ++i)
//		operand[i] *= operand[i];
//}
//���� �Լ� void Square(int* const operand, int const count=1)�� ���ָ�
//Square(&a); ȣ��� �Ʒ��� �Լ��� ȣ���� ȥ���ȴ�

//void Square(int* const operand)
//{
//		*operand *= *operand;
//}



//int main()
//{
//	int arr[5];
//	for (int i = 0; i < 5; ++i)
//		arr[i] = i;
//	Square(arr, 5);
//	for (int i = 0; i < 5; ++i)
//		cout << arr[i] << endl;
//
//	return 0;
//}

//void swap(int* const a, int* const b)
//{
//	int temp = 0;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}
//void swap(int* const a, int* const b)
//{
//	a ^= b;
//	b ^= a;
//	a ^= b;
//}

void swap(int& a, int& b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}

/*
	���۷���[������](Reference)

	Ư�� �ڷ��� ������ ����Ű�� ����
	���������δ� *const�� �����Ǿ� �ֱ� ������,
	��뿡�� �����Ϳ� ���Ǵ� �� ���� Ư¡�� ������.

	1. Null �������� ���� ����
	   - &�� ������ �������Ͱ� �� �� ����
	2. ���� ���(�ּ�)�� ���� ���� ����
	   - �ּ� ���� �Ұ���
	3. ������ ���� ����
	   -
*/

void Square(int* const arr, int const count)
{
	for (int i = 0; i < count; ++i)
		arr[i] *= arr[i];
}

struct A {
	char ch;
	char ch2;
	char ch3;
	double d;
	char ch4;
	char ch5;
	char ch6;


};


int main()
{
	A a;

	cout << sizeof(a);

	//int a = 1, b = 2;


	//cout << a << b << endl;
	//swap(a, b);
	//cout << a << b << endl;

	int arr[5];
	for (int i = 0; i < 5; ++i)
		arr[i] = i + 1;
	Square(arr, 5);

	return 0;
}

