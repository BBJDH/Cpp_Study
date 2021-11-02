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

	enum class Type : unsigned char//: short 하면 short로 바뀐다
	{
		Char,
		Int,
		Float,
	};


	Test() = default;
	//하나더
	//Test() = delete;  //명시적으로 테스트의 기본 생성자를 아예 삭제
	//constexpr 생성자를 붙이면 컴파일타임에 가능하면 컴파일타임에 진행
	/*constexpr*/ Test(Type const& t) : type{ t }, i{ 0 }
	{
		assert(static_cast<unsigned>(t) < 3);
		//assert : 주장하다 단언하다의 사전적 의미
		// 반드시 참이어야만 이 구문이 수행된다 거짓이면 중단된다
		//sizeof(Type);
		++count;

		//__FILE__, __FUNCTION__, __LINE__;  // 파일, 함수, 면번 줄
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
	void Print() const   //내부에서 멤버변수의 값을 바꿀 수 없다
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
	하드웨어의 제약이나 성능상의 이유로 데이터들을 특정한 바이트 경계들에 맞게 배치한다.
이를 바이트 정렬(Byte alignment)라고 부른다.
이때 바이트 경계에 맞추기 위해서 객체의 자료 끝에 추가적인 바이트들을 채우게 된다.
	*/
	//정적 멤버 변수, 정적멘버 함수를 가질 수 있다.
	static unsigned count;   //정적 멤버로서 가질것이다 선언
	//클래스 객체의 소속이 아닌, 클래스 형식의 소속, 객체를 생성하지 않아도 선언된다



	enum class Type const type;
	union    //공용체, -> 색상 코드 
	{
		char  c;
		int     i;
		float  f;

		//mutable int i;   const 여도 값의 변환이 가능해진다
	};

	//생성자를 선언하면 기존의 Test(){} 가 사라진다
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
#pragma region 컴파일과정,오류 LNK2019,1120
//void function();  //선언만 있고 정의가 없는 경우 LNK2019, LNK1120
//함수는 앞에 extern 이 생략되어 있다(External) 
//외부로부터 해당함수의 정의를 가져오겠다는 뜻을 의미
//빌드를 하면 컴파일을 하고 링크를 한다
//-> .ogj(완료된 이진코드 파일)이진 코드로 바꾸고 링킹을 시작
//->  .ogj(완료된 이진코드 파일) 들의 호출과 정의를 링커가 이어준다
//링킹과정까지 끝나면 exe 파일 
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
	//color.code = 0xDC143C;  // 60 20 220 0 으로 나뉘어 들어감

	//big endian									 00000101
	//little endian - 대부분이 채택하는 방식  10100000

	{
		Test test(Test::Type::Char);

		test.Set('a');
		//test.Set(99);
		//test.Set(99.9f);  //이와같은 예외의 상황에 프로그램을 중단하고 수정하도록
							//assert를 사용한다
		std::cout << test.Count() << std::endl;
	}



	//컨트롤 K+s : 코드 조각 감싸기
#pragma region constexpr, assert, static_assert
	{
		//	int const i = 1;
		int constexpr i = 1;
		// #define I 1 과 유사점을 가지지만 형식과 지역의 구분차이가 있다
		//int arr[i];

		static_assert(i < 5, "Max of i is 5."); // assert 보다 강력하게 아예 실행을 시키지 않는다
													//컴파일타임에서 구분 가능한경우.. 
	}
#pragma endregion


	return 0;
}