#include<iostream>

using namespace std;

class _int2
{
public:
	int X;
	int Y;

	_int2() :X{ 0 }, Y{ 0 }
	{
		cout << "�⺻ ������ ȣ��\n";
	}
	_int2(int const x, int const y) :X{ x }, Y{ y }
	{
		cout << "�Ű����� ������ ȣ��\n";
	}
	_int2(_int2 const& init)
	{//���� ������
		cout << "��������� ȣ��\n";
		*this = init;
	}
	_int2(_int2&& init)
	{//�̵� ������
		cout << "�̵������� ȣ��\n";
		*this = init;
	}

public:
	_int2 Get() const
	{// rvalue
		cout << "rvalue ��ȯ ȣ��\n";
		return *this; //��������� lvalue ���µ� ��ȯ�� _int2�� rvalue�� ���⼭ ��� �ٲ������ ã�� ���߾�
	}

	_int2& operator =(_int2&& Right) 
	{// �̵� ���� ���� ������
		cout << "xvalue ����\n";
		if (this != &Right)
		{
			this->X = Right.X;
			this->Y = Right.Y;
		}
		return *this;
	}

	_int2& operator =(_int2 const& Right) 
	{//���� ���� ������
		cout << "lvalue ���� ����\n";
		if (this != &Right)
		{
			this->X = Right.X;
			this->Y = Right.Y;
		}
		return *this;
	}
};


int main()
{
	_int2 test{};
	_int2 test2{ 1,4 };

	test = test2.Get();
	cout << test.X << " " << test.Y;

	return 0;
}

