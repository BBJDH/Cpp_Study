
#include <iostream>

using namespace std;




int main()
{
	int a = 10;

	unique_ptr<int> Pointer = make_unique<int>(10);
	cout << *Pointer<<"\n";
	shared_ptr<int> SharedPointer = make_shared<int>(50);
	cout << *SharedPointer;
	return 0;
}