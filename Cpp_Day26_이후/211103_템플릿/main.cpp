#include<iostream>
#include"Template.h"
#include<malloc.h>

#pragma region 스터디
//void swap(int* const a, int* const b)
//{
//
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
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
	//char str[3][10]= {"나는","아이언맨","입니다."} ;
	//char(* p)[10] = str;
	//std::cout << *(p+1) << std::endl;


	
	char const *const str = add("test", "study");

	std::cout << str << std::endl;

	delete[] str;


	

	return 0;
}