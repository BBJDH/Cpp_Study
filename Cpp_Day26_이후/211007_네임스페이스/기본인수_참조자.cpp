#include<iostream>

using namespace std;// 선언한곳 이후부터 네임스페이스가 적용된다
// 이후 회수는 불가능

/*
	기본 인수(Default Argument)

	함수의 인자에 기본 값을 부여하는 기능
	인자 목록의 마지막 인자부터 부여할 수 있다.

	오버로딩과 함께 사용할 경우, 호출의 모호성 문제가 발생할 수 있으며,
	같은 이유로 인자 목록의 마지막 인자로부터 부여해야한다는 규칙이 있다.

*/
//void Square(int* const operand, int const count)
//{
//	for (int i = 0; i < count; ++i)
//		operand[i] *= operand[i];
//}
//위의 함수 void Square(int* const operand, int const count=1)로 해주면
//Square(&a); 호출시 아래의 함수와 호출이 혼동된다

//void Square(int* const operand)
//{
//		*operand *= *operand;
//}



//int main()
//{
//	int arr[5];
//	for (int i = 0; i < 5; ++i)
//		arr[i] = i;
//	Square(arr, 5);
//	for (int i = 0; i < 5; ++i)
//		cout << arr[i] << endl;
//
//	return 0;
//}

//void swap(int* const a, int* const b)
//{
//	int temp = 0;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}
//void swap(int* const a, int* const b)
//{
//	a ^= b;
//	b ^= a;
//	a ^= b;
//}

void swap(int& a, int& b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}

/*
	레퍼런스[참조자](Reference)

	특정 자료형 변수를 가리키는 변수
	내부적으로는 *const로 구현되어 있기 때문에,
	사용에는 포인터와 대비되는 몇 가지 특징을 가진다.

	1. Null 포인터의 존재 유무
	   - &로 선언후 널포인터가 될 수 없다
	2. 참조 대상(주소)의 변경 가능 유무
	   - 주소 변경 불가능
	3. 역참조 가능 유무
	   -
*/

void Square(int* const arr, int const count)
{
	for (int i = 0; i < count; ++i)
		arr[i] *= arr[i];
}

struct A {
	char ch;
	char ch2;
	char ch3;
	double d;
	char ch4;
	char ch5;
	char ch6;


};


int main()
{
	A a;

	cout << sizeof(a);

	//int a = 1, b = 2;


	//cout << a << b << endl;
	//swap(a, b);
	//cout << a << b << endl;

	int arr[5];
	for (int i = 0; i < 5; ++i)
		arr[i] = i + 1;
	Square(arr, 5);

	return 0;
}

