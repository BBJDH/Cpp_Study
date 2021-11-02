#include<iostream>
#include"Base.h"  //해당 폴더 기준으로 헤더파일 탐색
//#include"Base.cpp" 도 가능 하지만 링커가 이어준다
#include"Derived.h"
//TODO: 헤더의 본래 목적과 용도
//TODO: 헤더 추가 순서
int main()
{
	using namespace std;
	{
		Base b;

		b.Set(5);
		cout << b.Get() << endl;
	}
	{
		Derived d;
		d.Print();
	}
	
	return 0;
}