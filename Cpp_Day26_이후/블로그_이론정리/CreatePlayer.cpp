/*
 *�Ʒ��� �ڵ忡�� �Լ� ȣ������� ���� ��ü������ �����Ͻÿ�
 *
 *-> StatInfo ��ȯ�� ���� ������ ȣ��, =������ �����ε�(&���Դ��) ȣ��
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
 *�Ʒ� �ڵ忡�� test1�� test2�� �������� �����Ͻÿ�.
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