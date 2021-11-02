#include<cassert>
#include<iostream>



//enum class Shape : unsigned char
//{
//	Spade,
//	Diamond,
//	Heart,
//	Clover
//
//};

class Test
{

public:

	enum class Type : unsigned char//: short �ϸ� short�� �ٲ��
	{
		Char,
		Int,
		Float,
	};


	Test() = default;
	//�ϳ���
	//Test() = delete;  //��������� �׽�Ʈ�� �⺻ �����ڸ� �ƿ� ����
	//constexpr �����ڸ� ���̸� ������Ÿ�ӿ� �����ϸ� ������Ÿ�ӿ� ����
	/*constexpr*/ Test(Type const& t) : type{ t }, i{ 0 }
	{
		assert(static_cast<unsigned>(t) < 3);
		//assert : �����ϴ� �ܾ��ϴ��� ������ �ǹ�
		// �ݵ�� ���̾�߸� �� ������ ����ȴ� �����̸� �ߴܵȴ�
		//sizeof(Type);
		++count;

		//__FILE__, __FUNCTION__, __LINE__;  // ����, �Լ�, ��� ��
	}
	~Test()
	{
		--count;
	}

	void Set(char const ch)
	{
		assert(type == Test::Type::Char);

		Test::c = c;
	}
	void Set(int const i)
	{
		assert(type == Test::Type::Int);

		Test::i = i;

	}
	void Set(float const f)
	{
		assert(type == Test::Type::Float);

		Test::f = f;

	}
	void Print() const   //���ο��� ��������� ���� �ٲ� �� ����
	{
		//this;

		std::cout << "Count : " << count << std::endl;
		switch (type)
		{
		case Test::Type::Char:
		{
			std::cout << c << std::endl;
			break;
		}
		case Test::Type::Int:
		{
			std::cout << i << std::endl;
			break;
		}
		case Test::Type::Float:
		{
			std::cout << f << std::endl;
			break;
		}

		}
	}
	static unsigned Count()
	{

		return count;
	}

private:
	/*
	�ϵ������ �����̳� ���ɻ��� ������ �����͵��� Ư���� ����Ʈ ���鿡 �°� ��ġ�Ѵ�.
�̸� ����Ʈ ����(Byte alignment)��� �θ���.
�̶� ����Ʈ ��迡 ���߱� ���ؼ� ��ü�� �ڷ� ���� �߰����� ����Ʈ���� ä��� �ȴ�.
	*/
	//���� ��� ����, ������� �Լ��� ���� �� �ִ�.
	static unsigned count;   //���� ����μ� �������̴� ����
	//Ŭ���� ��ü�� �Ҽ��� �ƴ�, Ŭ���� ������ �Ҽ�, ��ü�� �������� �ʾƵ� ����ȴ�



	enum class Type const type;
	union    //����ü, -> ���� �ڵ� 
	{
		char  c;
		int     i;
		float  f;

		//mutable int i;   const ���� ���� ��ȯ�� ����������
	};

	//�����ڸ� �����ϸ� ������ Test(){} �� �������
   //Test* GetTest()
   //{
   //	return new Test();
   //}
   //~Test() = default;
   //U u()
   //{
   //	U x;
   //	x.i = 5;
   //	return x.i;
   //}



};
#pragma region �����ϰ���,���� LNK2019,1120
//void function();  //���� �ְ� ���ǰ� ���� ��� LNK2019, LNK1120
//�Լ��� �տ� extern �� �����Ǿ� �ִ�(External) 
//�ܺηκ��� �ش��Լ��� ���Ǹ� �������ڴٴ� ���� �ǹ�
//���带 �ϸ� �������� �ϰ� ��ũ�� �Ѵ�
//-> .ogj(�Ϸ�� �����ڵ� ����)���� �ڵ�� �ٲٰ� ��ŷ�� ����
//->  .ogj(�Ϸ�� �����ڵ� ����) ���� ȣ��� ���Ǹ� ��Ŀ�� �̾��ش�
//��ŷ�������� ������ exe ���� 
#pragma endregion

unsigned Test::count;


int main()
{
	sizeof(Test);


	//union Color
	//{
	//	unsigned int   code;
	//	unsigned char bgra[4];
	//};
	//Color color;
	//color.code = 0xDC143C;  // 60 20 220 0 ���� ������ ��

	//big endian									 00000101
	//little endian - ��κ��� ä���ϴ� ���  10100000

	{
		Test test(Test::Type::Char);

		test.Set('a');
		//test.Set(99);
		//test.Set(99.9f);  //�̿Ͱ��� ������ ��Ȳ�� ���α׷��� �ߴ��ϰ� �����ϵ���
							//assert�� ����Ѵ�
		std::cout << test.Count() << std::endl;
	}



	//��Ʈ�� K+s : �ڵ� ���� ���α�
#pragma region constexpr, assert, static_assert
	{
		//	int const i = 1;
		int constexpr i = 1;
		// #define I 1 �� �������� �������� ���İ� ������ �������̰� �ִ�
		//int arr[i];

		static_assert(i < 5, "Max of i is 5."); // assert ���� �����ϰ� �ƿ� ������ ��Ű�� �ʴ´�
													//������Ÿ�ӿ��� ���� �����Ѱ��.. 
	}
#pragma endregion


	return 0;
}