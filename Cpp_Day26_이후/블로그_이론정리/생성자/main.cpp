
#include <iostream>

using namespace std;

struct _int2
{
	int X;
	int Y;
	_int2() {}
	_int2(_int2 const & InOther)
	{
		this->X = InOther.X;
		this->Y = InOther.Y;
	}
};

class Test
{
public:
	_int2 X;
	Test() 
	{
		cout << "기본 생성자 호출\n";
	}
	Test(Test & InOther)
	{
		cout << "복사 생성자 호출\n";
		this->X = InOther.X;
	}

};



int main()
{
	Test t1{};
	Test t2{};
	t1 = t2;

	return 0;
}