#include "Template.h"
#include<cstring>
template<typename T>
 T add(T const x, T const y) //����� ������ ���, �Ͻ��� �ν��Ͻ�ȭ, �˾Ƽ� �� ���� 
{
	return x+y;
}
 //����� Ư��ȭ
template<>
char const* add(char const*const x, char const*const y)
 {
	 size_t const size = strlen(x) + strlen(y) + sizeof(char);
	 char * const temp = new char[size] {};
	 strcpy_s(temp, size, x);
	 strcat_s(temp, size, y);

	 return temp;

 }

//����� ��üȭ  (���ø� �ν��Ͻ�ȭ)
template int add(int const x, int const y);
template float add<float>(float const x, float const y);

template<typename T, typename U>
Pair<T, U> Pair<T, U>::operator+(Pair const& pair)const
{
	/*
		RVO(Return Value Oprimazation)
		��ȯ�� ����ȭ

		�Լ��� ���� ������ �ܼ� ��ü ���� �� �ش� ��ü�� ��ȯ�ϴ� ���̶��,
		�ش� �Լ��� ȣ�⿡ ���� �� ���Ǹ� inlining �ϵ��� �ϴ� ����ȭ
	*/

	/*
	NRVO(Named Return Value Oprimazation)
	��� ��ȯ�� ����ȭ

	Pair const named = Pair
	{
		this->upper + pair.upper,
		this->lower + pair.lower
	};
	return named;

	�������� ����ȭ�϶� �ζ���ȭ �ȴ�.
*/
	return Pair
	{
		this->upper + pair.upper,
		this->lower + pair.lower
	};
}

//Ŭ���� ���ø��� ��� �Լ��� �κ� Ư��ȭ�� �Ұ����ϴ�.
//template<typename T>
//Pair<T, int> Pair<T, int>::operator+(Pair<T,int> const& pair)const
//{
//
//	return Pair
//	{
//		this->upper + pair.upper,
//		this->lower + pair.lower
//	};
//}
Pair<int, int> Pair<int, int>::operator+(Pair const& pair)const
{

	return Pair
	{
		this->upper + pair.upper,
		this->lower + pair.lower
	};
}