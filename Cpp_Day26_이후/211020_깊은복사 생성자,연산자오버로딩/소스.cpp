#include<iostream>
#include<cassert>

struct S
{
	int i;
};

class Test
{

public:

	enum class Type : unsigned char//: short �ϸ� short�� �ٲ��
	{
		Char,
		Int,
		Float,
	};

	constexpr Test(Type const& t) : type{ t }
	{
		assert(static_cast<unsigned>(t) < 3);

		++count;

	}
	constexpr Test(Type const& other) : Test(other.type)  
	{
		i = other.i;
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

	static unsigned count;   //���� ����μ� �������̴� ����


	enum class Type const type;
	union   
	{
		char  c;
		int     i;
		float  f;

	};




};
int main()
{
	{
		S s1;
		s1.i = 5;
		S s2 = s1;
		s1 = s2;   // ��� ����
	}
}