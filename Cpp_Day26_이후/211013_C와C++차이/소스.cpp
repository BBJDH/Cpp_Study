/*
절차 지향 프로그래밍
프로시저 : 함수(명령어의 묶음)
프로기저 기반 프로그래밍
추상화, 재사용성을 추구

객체지향 프로그래밍(Object Oriented Programming, OOP)
추상화
캡슐화
 -정보 은닉
 상속
 다형성

*/

#include<iostream>
using namespace std;
struct Test
{
	int i;

	void print()
	{
		cout << i << endl;
	}
};

int main()
{
	Test test;
	test.i = 10;
	test.print();

	sizeof(test);

	Test s;
	s.i = 20; 
	s.print();

	return 0;
}