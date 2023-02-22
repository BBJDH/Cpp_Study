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
		cout << "�⺻ ������ ȣ��\n";
	}
	Node(int const x, int const y, string const& name) :_int2(x,y), Name { name }
	{
		cout << "�Ű����� ������ ȣ��\n";
	}
	Node(Node const& init)
	{//���� ������
		cout << "��������� ȣ��\n";
		*this = init;
	}
	Node(Node&& init) noexcept
	{//�̵� ������
		cout << "�̵������� ȣ��\n";
		*this = std::move(init);
	}

public:
	Node Get() const
	{// prvalue ��ȯ
		cout << "prvalue ��ȯ ȣ��\n";
		return *this; 
	}

	Node& operator =(Node&& Right) noexcept
	{// �̵� ���� ���� ������
		cout << "xvalue ����\n";
		if (this != &Right)
		{
			this->X = Right.X;
			this->Y = Right.Y;
			this->Name = std::move(Right.Name);
		}
		return *this;
	}

	Node& operator =(Node const& Right)
	{//���� ���� ������
		cout << "lvalue ���� ����\n";
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

	//_int2 test{ 1,4,"ù �׽�Ʈ ����" };		//�����ε��� ������ ȣ��
	//_int2 test2(static_cast<_int2&&>(test));

	//cout << "\n\n std::move�� ������ ������ �ұ�? \n\n";

	//_int2 test3{ 1,4,"�ι�° �׽�Ʈ ����" };		//�����ε��� ������ ȣ��
	//_int2 test4(std::move(test3));


	//cout << "\n�̹� �̵��� ��ü�� ��������Ƿ� �ǵ帮�� �ȵȴ�..\n";
	//cout << "\ntest�� test3�� ����ִ� ����غ���\n";
	//cout << test.Name << test3.Name;

	Node TestA{};
	Node B{};
	B= TestA.Get();



	return 0;
}

//_int2 test2{}; 

//cout << "\n\nprvalue ���Կ���\n\n";

//test2 = test.Get();

	//_int2 test2{ std::move(test) };

	//cout << test.Name;


	//cout << "���� ���� \n";
	//vector<_int2> arr{};

	//arr.emplace_back(test); //���������� move
	//arr.push_back(test);  //���������� = �����
	//_int2 test3{ test.Get() };


	//cout << test2.X << " " << test2.Y<<"\n\n";
	//cout << "�̹��� lvalue ���縦 �غ���\n";
	//_int2 test3(test);
	//cout << test3.X << " " << test3.Y << "\n\n";


//Xvalue�� ���� ������
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