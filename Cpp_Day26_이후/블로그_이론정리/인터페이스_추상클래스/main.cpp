#include <iostream>

using namespace std;

class Base 
{
public:

	virtual void Move()=0;
	int a;
};

__interface IMoveAble //인터페이스 상속 가능
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