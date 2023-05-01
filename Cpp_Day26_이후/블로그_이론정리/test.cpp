#include <iostream>

using namespace std;

class Base
{
protected:
	void Print() { cout << "asdf"; }
	
};

class Derived :public Base
{
//public:
	void Test()
	{
		Print();
	}
};

int main()
{
	return 0;
}