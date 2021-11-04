#include "Template.h"
#include<cstring>
template<typename T>
 T add(T const x, T const y) //헤더에 공개된 경우, 암시적 인스턴스화, 알아서 다 만듬 
{
	return x+y;
}
 //명시적 특수화
template<>
char const* add(char const*const x, char const*const y)
 {
	 size_t const size = strlen(x) + strlen(y) + sizeof(char);
	 char * const temp = new char[size] {};
	 strcpy_s(temp, size, x);
	 strcat_s(temp, size, y);

	 return temp;

 }

//명시적 구체화  (템플릿 인스턴스화)
template int add(int const x, int const y);
template float add<float>(float const x, float const y);

template<typename T, typename U>
Pair<T, U> Pair<T, U>::operator+(Pair const& pair)const
{
	/*
		RVO(Return Value Oprimazation)
		반환값 최적화

		함수의 수행 내용이 단순 개체 생성 후 해당 개체를 반환하는 것이라면,
		해당 함수의 호출에 대해 그 정의를 inlining 하도록 하는 최적화
	*/

	/*
	NRVO(Named Return Value Oprimazation)
	명명 반환값 최적화

	Pair const named = Pair
	{
		this->upper + pair.upper,
		this->lower + pair.lower
	};
	return named;

	릴리즈모드 최적화일때 인라인화 된다.
*/
	return Pair
	{
		this->upper + pair.upper,
		this->lower + pair.lower
	};
}

//클래스 템플릿의 멤버 함수는 부분 특수화가 불가능하다.
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