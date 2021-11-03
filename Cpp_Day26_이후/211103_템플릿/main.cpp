#include<iostream>
#include"Template.h"
#include<malloc.h>

#pragma region ½ºÅÍµð
void swap(int* const a, int* const b)
{

	int temp = *a;
	*a = *b;
	*b = temp;
}
//void swap2(int* a, int* b)
//{
//
//	*a ^= *b;
//	*b ^= *a;
//	*a ^= *b;
//}
//char test(char& ch)
//{
//	return ch;
//}
//char test(char ch)
//{
//	//char temp = ch;
//	return ch;
//}
#pragma endregion


int main()
{
	int* a = new int{ 5 };
	int* b = new int{ 10 };
	swap(a, b);
	std::cout << *a << *b << std::endl;


	//char const *const str = add("test", "study");

	//std::cout << str << std::endl;

	//delete[] str;


	

	return 0;
}