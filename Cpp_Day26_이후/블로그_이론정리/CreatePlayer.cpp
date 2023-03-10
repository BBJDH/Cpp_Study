/*
 *아래의 코드에서 함수 호출과정에 대해 구체적으로 설명하시오
 *
 *-> StatInfo 반환을 위한 생성자 호출, =연산자 오버로딩(&대입대상) 호출
 *
 */

//#include <iostream>
//
//using namespace std;
//
//struct StatInfo 
//{
//	int Hp;
//	int Mp;
//	int Attack;
//};
//
//StatInfo CreatePlayer()
//{
//	StatInfo result;
//	result.Hp = 100;
//	result.Mp = 50;
//	result.Attack = 10;
//
//	return result;
//}
//
//int main()
//{
//	StatInfo player;
//	player.Hp = 0xbbbb'bbbb;
//	player.Mp = 0xbbbb'bbbb;
//	player.Attack = 0xbbbb'bbbb;
//
//	player = CreatePlayer();
//
//	return 0;
//}


/*
 *아래 코드에서 test1과 test2의 차이점을 설명하시오.
 *
 */

#include <iostream>

using namespace std;

int main()
{
	const char* test1 = "Hello World";
	char test2[] = "Hello World";

	cout << test2[2];
	cout << test1[2];

	return 0;
}