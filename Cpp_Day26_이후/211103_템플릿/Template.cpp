#include "Template.h"
#include<cstring>
#include <iostream>
template<typename T>
 T add(T const x, T const y)
{
	std::cout << "Hey!! LookAtMe!!";
	return x+y;
}

struct _int2
{
	int X;
	int Y;
};
 //명시적 구체화
 template int add(int const x, int const y);
 template float add<float>(float const x, float const y);


 //명시적 특수화
template<>
char const* add(char const*const x, char const*const y)
 {
	 int const size = strlen(x) + strlen(y) + sizeof(char);
	 char* temp = new char[size] {};
	 strcat_s(temp, size, x);
	 strcat_s(temp, size, y);

	 return temp;

 }


