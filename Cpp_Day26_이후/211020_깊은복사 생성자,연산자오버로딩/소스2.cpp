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

	//���� copy Constructor�� ���� ���縦 ���� ���� ũ��� �����Ҵ��Ͽ�
	// 	  ���縦 ����, other.text�� ���� ũ���� ������ this->text�� �Ҵ��ϰ�
	// 	   ���ڿ��� �����ϴ� �ڵ�
	String(String const& other) :String(other.text) 
	{
		cout << "copy constructor" << endl;
	}
	
	//���� ���꿡�� ��ȯ ���� �ִ�.
	// x = 0 ���� �������� ������ ���� =���� ��ȯ
	//������ �Ϸ�� �ڱ� �ڽ����� ��ȯ
#pragma region =ù��° ���
	String& operator =(String const& other)
	{
		////� ������ �����ؾ� �ϴ��� ����
		unsigned size = strlen(other.text) + sizeof(char);
		text = new char[size];
		strcpy_s(text, size, other.text);
		return *this;  //�׳� this �� �ּ��̴� 
	}
#pragma endregion
#pragma region =�ι�° ���
	//String& operator =(String const& other)
	//{
	//	//copy constuctor�� ����ؼ� ��ȯ�� �� �ִ°�
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
		cout <<"text�� �ּҴ� : "<< static_cast<void*>(text) << endl;   //void �����ͷ� ĳ��Ʈ�ؼ� Ȯ���Ѵ�

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
	//String s = t;    //���� ����, ���� 1��1�� ����,
	//String s(t);   copy constructor
	String s("hi ");
	//s = t;
	//t.Print();
	//s.Print();

	s = s + t;
	t.Print();
	s.Print();
#pragma region ��Ʈ�� ���̱� �׽�Ʈ
	//char* ch1 = new char[3]{"hi"};
	//char* ch2 = new char[6]{ "hello" };
	//char* ch3 = new char[8]{ "" };
	//strcat_s(ch3, sizeof(ch3), ch1);
	//strcat_s(ch3, sizeof(ch3), ch2);

	//cout << ch3 << endl;  
#pragma endregion



	return 0;
}