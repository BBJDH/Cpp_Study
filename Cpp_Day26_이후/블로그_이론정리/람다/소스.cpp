#include <iostream>

using namespace std;


int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	void(*Fptr)();


	{
		//int a = 10;
		//Fptr = [a]() {cout << "ddd"; };
	}

	Fptr();

	return 0;
}