#include<stdio.h>

typedef struct TEST
{
	int i;

	void (* const Set)(struct TEST * test);
	void (* const print)(struct TEST* test);

}Test;

void Set(int i, Test * const this)
{
	this->i = i;
};

void print(Test * const test)
{
	printf_s("%i\n", test->i);
}

int main()
{
	Test t = {10, Set,print};

	t.print(20,&t);
	return 0;
}