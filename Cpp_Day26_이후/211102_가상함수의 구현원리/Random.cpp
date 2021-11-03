#include "Random.h"
#include<iostream>
#include<cassert>



#pragma region Random Ŭ���� ����
//�ߺ� ���� ���� ����
// ���� �� ~ ���� ���� ����(-������ ����, ������� unsigned int),
// �� ��� ����, �迭�� ���ʴ�� �־ ��ȯ(�����Ҵ�� �迭�� �����ͷ� ��ȯ)
// ex) 1~ 50 ����
//-> �����Ҵ����� size 50, �ʱ�ȭ�� 1~50, �ε��� ����
//index = rand()%size �� �޾� ���� ���� �ε����� ���� ���� ��� ��̿� �ְ�,
//index�� ���� �迭�� ���� ��(size-1)���� ��ü �� size 1 ���� 
// ->���� rand()%size ���� size�� 1���������Ƿ� �� �� �迭�� ���� rand���� ���ܵȴ�
//[12345] ���� 3�� ������ [1254]3  ([]�� rand�� ����, ���������� --size;)
Random::Random(int const& start_num, int const& end_num, unsigned const& count) :arr_size(count)
{
	assert(end_num > start_num);
	assert(count > 0);

	unsigned size = end_num - start_num + 1;
	int value = start_num;

	int* const Arry_Range = new int[size] {};

	for (unsigned i = 0; i < size; ++i)
	{
		Arry_Range[i] = value++;
	}  //���� ����

	result = new int[count] {};


	for (unsigned i = 0; i < count; ++i)
	{
		int const index = rand() % size;
		result[i] = Arry_Range[index];
		Swap(Arry_Range[index], Arry_Range[size - 1]);
		--size;
	}

}
Random::Random(Random const& r) :result(r.result), arr_size(r.arr_size)
{}
int Random::GetResult(unsigned const& index)const
{
	assert(index < arr_size);
	return result[index];
}
void Random::Print() const
{
	for (unsigned i = 0; i < arr_size; i++)
	{
		std::cout << result[i] << "\t";
		if (i % 10 == 9)
			std::cout << std::endl;
	}
}

Random::operator int() const
{
	assert(result!=nullptr);
	assert(arr_size == 1);
	return result[0];
}

constexpr void Random::Swap(int& a, int& b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}

#pragma endregion
