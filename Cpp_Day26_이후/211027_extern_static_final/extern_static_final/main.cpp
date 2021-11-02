#include<iostream>
#include"Base.h" 
#include"Derived.h"

extern int g;  //다른 cpp의 g를 가져다 쓴다
//external 외부의
//static 정적인
extern void test();
//계획된것이 아니라면 어딘가에 종속하여(extern) 사용할경우
//유지보수 측면에서 불리하다
//외부에서 쓰는내용을 다 풀어다 쓰는건 불리하다
void test2()
{
	static int i = 0; 
	std::cout << ++i << std::endl;
}
//지역 안에서의 static 은 메인함수안에서 계속 생존한다
//프로그램종료시 같이 삭제되며,
//메인 밖의 다른 외부함수에서 접근은 불가능하다.



//함수는 선언만 해도 extern이 자동 적용됨
int main()
{
	for(size_t i =0; i<5; ++i)
		test2();
	//g = 0;
	//std::cout << g << std::endl;
	//
	
	return 0;
}