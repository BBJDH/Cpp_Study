#include<iostream>
#include"Template.h"
#include<malloc.h>

#pragma region 스터디
//void allocate(char** str)
//{
//	*str = new char[5]{"test"};
//}
//void printarr(int const* const arr, int const size)
//{
//	//arr = nullptr;
//
//	for (size_t i = 0; i < size; ++i)
//		std::cout<<arr[i]<<" ";
//}
//void printarr2(int const*const & const arr, int const size)
//{
//	//arr = nullptr;
//	for (size_t i = 0; i < size; ++i)
//		std::cout << arr[i] << " ";
//}
//void printarr3(int const arr[], int const size)
//{
//	arr = nullptr;
//
//	for (size_t i = 0; i < size; ++i)
//		std::cout << arr[i] << " ";
//}
//void printarr4(int const (&arr)[5])
//{
//	//arr = nullptr;
//
//	for (size_t i = 0; i < 5; ++i)
//		std::cout << arr[i] << " ";
//}
//void swap(int* const a, int* const b)
//{
//
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//void swap2(int* a, int* b)
//{
//
//	*a ^= *b;
//	*b ^= *a;
//	*a ^= *b;
//}
//char test(char& ch)
//{
//	return ch;
//}
//char test(char ch)
//{
//	//char temp = ch;
//	return ch;
//}
//class Card {
//public:
//	Card():num(count)
//	{
//		count++;
//	}
//
//	static unsigned count;
//	char const* shape = "☆";
//	unsigned num=1;
//private:
//};
//unsigned Card::count;
//void printcard(Card * card, int size)
//{
//	for (unsigned i = 0; i < size; ++i)
//	{
//		std::cout << card[i].shape;
//		std::cout << card[i].num;
//		std::cout << std::endl;
//	}
//}
#pragma endregion

template<typename T>
class Creator {

};

int main()
{
#pragma region 스터디
	//char* str = nullptr;
	//allocate(&str);
	//std::cout << str << std::endl;
	//delete[] str;
	//int arr[5] = { 1,2,3,4,5 };
	//printarr4(arr);
	//Card card[12];
	//printcard(card, 12);

#pragma endregion

	char const *const str = add("test", "study");
	std::cout << str << std::endl;
	delete[] str;
	Pair<int> pi;
	Pair<int, int> const pii{};
	//TODO: 클래스 복제 템플릿

	return 0;
}