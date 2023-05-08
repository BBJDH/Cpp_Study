
#include <iostream>
#include <string>

using namespace std;

struct Node
{
	long long & RX;
};

struct Node2
{
	string str;
	//int i;
	//int i2;
	char ch1;
	char ch2;
	char ch3;


};


void Test(long long && R)
{
	cout << &R;
}



int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	//int* Pointer = nullptr;

	//cout << sizeof(Pointer);

	//long long a = 5;
	//int* p = nullptr;
	//{
	//	int b = 6;
	//	//p = &b;
	//	p = new int;
	//	delete p;
	//}
	//cout << *p;

	//long long& r = a;

	//cout << &r<<"\n"<<&a<<"\n";
	//cout << sizeof(r);
	//cout << &a << "\n";
	//Test(5);

	long long a = 19;
	Node Test{a};
	Node2 Test2{};
	cout << sizeof(Node2);

	return 0;
}