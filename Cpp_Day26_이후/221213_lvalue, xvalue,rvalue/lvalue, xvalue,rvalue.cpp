#include<iostream>

using namespace std;

class _int2
{
public:
	_int2(){}
	_int2(int x, int y) :X(x), Y(y) {}
	int X;
	int Y;
};

class Node : public _int2
{
public:
	string Name;

	Node() :_int2(), Name {}
	{
		cout << "기본 생성자 호출\n";
	}
	Node(int const x, int const y, string const& name) :_int2(x,y), Name { name }
	{
		cout << "매개변수 생성자 호출\n";
	}
	Node(Node const& init)
	{//복사 생성자
		cout << "복사생성자 호출\n";
		*this = init;
	}
	Node(Node&& init) noexcept
	{//이동 생성자
		cout << "이동생성자 호출\n";
		*this = std::move(init);
	}

public:
	Node Get() const
	{// prvalue 반환
		cout << "prvalue 반환 호출\n";
		return *this; 
	}

	Node& operator =(Node&& Right) noexcept
	{// 이동 복사 대입 연산자
		cout << "xvalue 복사\n";
		if (this != &Right)
		{
			this->X = Right.X;
			this->Y = Right.Y;
			this->Name = std::move(Right.Name);
		}
		return *this;
	}

	Node& operator =(Node const& Right)
	{//복사 대입 연산자
		cout << "lvalue 복사 시행\n";
		if (this != &Right)
		{
			this->X = Right.X;
			this->Y = Right.Y;
			this->Name = Right.Name;
		}
		return *this;
	}
};

//void Func(string & a)
//{
//	cout << a;
//}
//void Func(string a)
//{
//	cout << a;
//}
//void Func(string &&a) // L
//{
//	cout << a;
//}
//template<typename  T>
void Func(string a) // R
{
	cout << a;
}

void Func(string && a) // R
{
	cout << a;
}

int main()
{

	//_int2 test{ 1,4,"첫 테스트 생성" };		//오버로딩된 생성자 호출
	//_int2 test2(static_cast<_int2&&>(test));

	//cout << "\n\n std::move도 동일한 동작을 할까? \n\n";

	//_int2 test3{ 1,4,"두번째 테스트 생성" };		//오버로딩된 생성자 호출
	//_int2 test4(std::move(test3));


	//cout << "\n이미 이동된 객체는 비어있으므로 건드리면 안된다..\n";
	//cout << "\ntest와 test3는 비어있다 출력해보면\n";
	//cout << test.Name << test3.Name;

	Node TestA{};
	Node B{};
	B= TestA.Get();



	return 0;
}

//_int2 test2{}; 

//cout << "\n\nprvalue 대입연산\n\n";

//test2 = test.Get();

	//_int2 test2{ std::move(test) };

	//cout << test.Name;


	//cout << "벡터 생성 \n";
	//vector<_int2> arr{};

	//arr.emplace_back(test); //내부적으로 move
	//arr.push_back(test);  //내부적으로 = 사용함
	//_int2 test3{ test.Get() };


	//cout << test2.X << " " << test2.Y<<"\n\n";
	//cout << "이번엔 lvalue 복사를 해보자\n";
	//_int2 test3(test);
	//cout << test3.X << " " << test3.Y << "\n\n";


//Xvalue를 통한 다형성
//
//#include<iostream>
//
//
//using namespace std;
//
//class A
//{
//
//public:
//
//	int X = 10;
//	virtual void Print() { cout << "A"; }
//
//};
//
//class B :public A
//{
//public:
//
//	B Get()
//	{
//		return *this;
//	}
//	void Print() override { cout << "B"; }
//};
//
//int main()
//{
//	A&& a = B();
//	a.Print();
//
//	return 0;
//}