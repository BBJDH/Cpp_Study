#include<iostream>

using namespace std;

class _int2
{
public:
	int X;
	int Y;

	_int2() :X{ 0 }, Y{ 0 }
	{
		cout << "기본 생성자 호출\n";
	}
	_int2(int const x, int const y) :X{ x }, Y{ y }
	{
		cout << "매개변수 생성자 호출\n";
	}
	_int2(_int2 const& init)
	{//복사 생성자
		cout << "복사생성자 호출\n";
		*this = init;
	}
	_int2(_int2&& init)
	{//이동 생성자
		cout << "이동생성자 호출\n";
		*this = init;
	}

public:
	_int2 Get() const
	{// rvalue
		cout << "rvalue 반환 호출\n";
		return *this; //만들어진건 lvalue 였는데 반환은 _int2로 rvalue라서 여기서 어떻게 바뀌는지는 찾지 못했어
	}

	_int2& operator =(_int2&& Right) 
	{// 이동 복사 대입 연산자
		cout << "xvalue 복사\n";
		if (this != &Right)
		{
			this->X = Right.X;
			this->Y = Right.Y;
		}
		return *this;
	}

	_int2& operator =(_int2 const& Right) 
	{//복사 대입 연산자
		cout << "lvalue 복사 시행\n";
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

