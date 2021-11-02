#include<iostream>
using namespace std;

void Allocate(int*& ipr);
int main()
{
	//int  f =  2;  //상수간의 계산은 인텔리전스에서 확인 가능 
	////float f = 5.0f / 2.0f;  //int를 float화
	////()캐스트 연산자 단점 
	//// 가독성, 찾기 힘들다
	//cout << f << endl;

	//int& i = (int&)(f);

	//i = 8; //됨
	//cout << f << endl;

	//float& fr = (float&)(f); //const f 인데도 ()캐스트를 사용하면 풀고 넣어진다

	//fr = 7.0f;  //됨


	//캐스트 연산자 (sizeof 처럼)
	//static_cast<int> : 논리적으로 안전한 형식에 대한 변환
	//dynmic_cast : 다운 캐스팅에대한 변환
	//const_cast : const 한정자에 대한 변환(위험한 변환) - 일시적으로 const 제거후 사용
	// 	   ->값의 변동이 없다고 확신하지만 타 함수에서 캐스팅해서 쓸때
	//reinterpret_cast : 주소와 참조에 대한 변환(위험한 변환)

	{
		long const  num = 0;
		//(자료형 &) 변수를 레퍼런스로 캐스팅
		int& ref = (int&)(num); //그냥 int형으로 캐스트해서 값은 안바뀌게 쓰고싶을 뿐인데.. 
										//const 인데 값을 풀어버림
	//reinterpret_cast : 주소와 참조에 대한 변환
	//참조자의 대상이 const 이면 오류 검출
		int const& ref = reinterpret_cast<int const&>(num);
		//위와 같이 const를 선언해서 안전하게 수행토록 함
		//ref = 10; // 가능, 위험하다!

	//const_cast : const 한정자에 대한 변환
		int  ref = reinterpret_cast<int&>(const_cast<long&>(num));  //const인 num을 캐스트
		//ref = 5; //가능, 위험하다!
		//const_cast<long&>(num) = 5; //const인데 가능하게 한다 위험하다
		//void test(int& ref); 에서 test(num)으로 호출이 불가능하지만
		//void test(int& const_cast<int&> ref)면  test(num)으로 호출 가능?

	}
	//cout << f << endl;

	int* p = nullptr;

	Allocate(p);
	*p = 5;
	cout << *p << endl;
	return 0;
}
void Allocate(int*& ipr)    //포인터를 레퍼런스로 받아 보자
{
	ipr = (int*)(malloc(sizeof(int)));
}