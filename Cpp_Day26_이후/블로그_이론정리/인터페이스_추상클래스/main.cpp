#include <iostream>

using namespace std;

class Base 
{
public:

	virtual void Move()=0;
	int a;
};

__interface IMoveAble //�������̽� ��� ����
{
	void Move();
	//static Stop();
};



int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	Base A;

	return 0;
}