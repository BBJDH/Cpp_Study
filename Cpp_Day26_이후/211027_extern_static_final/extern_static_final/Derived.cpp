#include<iostream>

#include "Base.h"
#include "Derived.h"

namespace  //외부에서 못쓰도록 익명의 네임 스페이스 선언
{
	int g = 5;
	//static int g; 이 g를 이파일로 한정한다
	//함수도 마찬가지
	void test()
	{
		std::cout << g << std::endl;
	}
}

void Derived::Print() const
{
	//g =0; 내부에서는 사용 가능! 
	std::cout << Get()<< std::endl;
}


