 #include<cstring>
#include<iostream>
#include<cassert>

using namespace std;

enum class Shape : unsigned char
{
	Spade,
	Diamond,
	Heart,
	Clover,
	Max

};

class String
{
public:

	String():text(nullptr)
	{
		cout << "constructor call : Default" << endl;
	}
	String(char const * const ch)
	{
		unsigned const size = strlen(ch) + sizeof(char);
		this->text = new char[size];
		//this->text = static_cast<char*>(malloc(size*sizeof(char)));
		strcpy_s(this->text,size, ch);
		cout << "constructor call : Has argument" << endl;
	}

	//과제 copy Constructor에 깊은 복사를 구현 같은 크기로 동적할당하여
	// 	  복사를 수행, other.text와 같은 크기의 공간을 this->text에 할당하고
	// 	   문자열을 복사하는 코드
	String(String const& other) :String(other.text) 
	{
		cout << "copy constructor" << endl;
	}
	
	//대입 연산에는 반환 값이 있다.
	// x = 0 에서 오른쪽의 수식의 값을 =에서 반환
	//대입이 완료된 자기 자신으로 반환
#pragma region =첫번째 방법
	String& operator =(String const& other)
	{
		////어떤 내용을 수행해야 하는지 정의
		unsigned size = strlen(other.text) + sizeof(char);
		text = new char[size];
		strcpy_s(text, size, other.text);
		return *this;  //그냥 this 는 주소이다 
	}
#pragma endregion
#pragma region =두번째 방법
	//String& operator =(String const& other)
	//{
	//	//copy constuctor를 사용해서 반환할 수 있는가
	//	String *s = new String(other);

	//	return *s;
	//}  
#pragma endregion
	String& operator +(String const& other)
	{
		unsigned size = strlen(text) + strlen(other.text)-1;

		char* const chtemp = new char[strlen(text) + sizeof(char)]{};
		strcpy_s(chtemp, sizeof(chtemp), text);
		delete[] text;
		text = nullptr;
		text = new char[size] {};
	    strcat_s(text, size, chtemp);
		strcat_s(text, size, other.text);

		
		return *this;
	}


	void Print() const
	{
		cout << text << endl;
		cout <<"text의 주소는 : "<< static_cast<void*>(text) << endl;   //void 포인터로 캐스트해서 확인한다

	}
	~String()
	{
		delete[] text;
	}
	
private:
	char* text;

};

int main()
{
	//for (Shape s = Shape::Spade; s < Shape::Max; s = static_cast<Shape>(static_cast<int>(s) + 1))
	//{
	//}
	String t("String");
	//String s = t;    //얕은 복사, 값을 1대1로 대입,
	//String s(t);   copy constructor
	String s("hi ");
	//s = t;
	//t.Print();
	//s.Print();

	s = s + t;
	t.Print();
	s.Print();
#pragma region 스트링 붙이기 테스트
	//char* ch1 = new char[3]{"hi"};
	//char* ch2 = new char[6]{ "hello" };
	//char* ch3 = new char[8]{ "" };
	//strcat_s(ch3, sizeof(ch3), ch1);
	//strcat_s(ch3, sizeof(ch3), ch2);

	//cout << ch3 << endl;  
#pragma endregion



	return 0;
}