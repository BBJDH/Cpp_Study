
#include <iostream>

using namespace std;
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

	long long a = 5;
	int* p = nullptr;
	{
		int b = 6;
		//p = &b;
		p = new int;
		delete p;
	}
	cout << *p;

	long long& r = a;

	//cout << &r<<"\n"<<&a<<"\n";
	//cout << sizeof(r);
	cout << &a << "\n";
	Test(5);
	return 0;
}