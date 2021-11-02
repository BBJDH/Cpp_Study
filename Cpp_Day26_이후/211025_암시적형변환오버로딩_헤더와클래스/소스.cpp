#include<cstring>
#include<iostream>
#include<cassert>
#include<cstdint>

using namespace std;
#pragma region 개체와 객채 그리고 인스턴스

#pragma endregion
/*
TODO: String 이 char *const 로 암시적취급될 때 처리
*/

class String
{
private:
    char * text;

    void Assign(char const* const str)
    {
        unsigned size = strlen(str) + sizeof(char);
        text = new char[size];
        strcpy_s(text, size, str);
    }
public:
    


    void Print()
    {
        cout << "문자열 : " << text << endl;
        cout << "문자열 주소 : " << static_cast<void*>(text) << endl;
    }
    String()
    {
        cout << "Default Constructor Call" << endl;
    }
    //변환 생성자
    explicit String(char const* const  text_arg)
    {
        Assign(text_arg);
        cout << "Constructor Call : has arg" << endl;

    }
    String(String const& other)
    {
        Assign(other.text);
        cout << "Copy Constructor Call" << endl;
    }
    ~String()
    {
        cout << "Destuctor Call" << endl;
        delete[] text;
    }

#pragma region =오버로딩
    String& operator =(String const& other)
    {
        if (this != &other)
        {
            delete[] text;
            Assign(other.text);

            return *this;
        }

        return *this;   //copy constructor call
    }

#pragma region +오버로딩
    String& operator +(String const& other)
    {
        unsigned size = strlen(text) + sizeof(char);
        char* temp = new char[size] {};
        strcpy_s(temp, size, text);
        size = strlen(text) + strlen(other.text) + sizeof(char);
        delete[] text;
        text = new char[size] {};
        strcat_s(text, size, temp);
        strcat_s(text, size, other.text);

        delete[] temp;

        return *this;   //copy constructor call
    }
#pragma endregion
#pragma region +오버로딩 두번째
    //String operator +(String const& other) const //본래의 대상을 건드리지 않기에 const
    //{
    //    char buffer[1024]{};

    //    strcpy_s(buffer,1024, text);
    //    strcat_s(buffer,1024, other.text);

    //    return String(buffer);   //copy constructor call
    //}
#pragma endregion


#pragma region ==오버로딩
    bool operator ==(String const& other)
    {

        return strcmp(text, other.text) ? 0 : 1;   //copy constructor call
    }
#pragma endregion

#pragma region +=오버로딩
    String& operator +=(String const& other)  //+,=오버로딩이 필요하다
    {
        return  *this + other;
    }
#pragma endregion
    String& operator -(int const n)
    {
        if ((text != nullptr) && (strlen(text) >= n))
        {
            unsigned size = strlen(text) + sizeof(char);
            char* const temp = new char[size];
            strcpy_s(temp, size, text);
            delete[] text;
            size -= n;
            text = new char[size] {};
            strncpy_s(text, size, temp, size - 1);
            delete[] temp;
            return *this;
        }
        else
        {
            cout << "-(int)값이 너무 크거나 nullptr 입니다" << endl;
            delete[] text;
            text = nullptr;
            return *this;
        }
    }
#pragma region 원소 접근 연산자
    //char& operator [](unsigned const index)
    //{
    //    assert(index < strlen(text));
    //    return text[index];
    //}

    //char const& operator [](unsigned const index) const
    //{

    //    return const_cast<String&>(*this)[index];
    //}
#pragma endregion
#pragma region 암시적 형변환
    //string이 char const*로 취급될때 char const*로 반환
    //[]연산자 오버로딩과 중복된다 []도 가능해짐
    //헌데 이렇게 하면 클래스의 private 원소에 접근이 가능해진다(주소접근)
    // 하지만 strlen()처럼 char const*로 처리하고싶은겨우 필요하다
    //operator char* ()  const
    //{                        
    //    return text;
    //}

    //explicit - > 명시적인 이라는 뜻
     explicit operator char* ()  const  // -> 암시적으로는 금지, 명시적으로는 가능(static_cast)
    {                        
        return text;
    }
    size_t Length() const
    {
        return strlen(text);
    }
#pragma endregion


};

void Test(String const )
{
}
enum class Shape : unsigned char
{
    Spade,
    Diamond,
    Heart,
    Clover,
    Max
};

class S
{
public:
    enum 
    {
        Spade,
        Diamond,
        Heart,
        Clover,
        Max
    };
};

#pragma region 연사자 외부 오버로딩 inline 사용

//inline -> 반복문은 인라인이 안된다 간단한 구문만 가능
//인라인을 희망한다 강제로 하려면 __forceinline
//이진파일에서의 용량이 증가한다
//형식 내부에서 정의된 함수는 자동으로 inline
inline Shape operator +(Shape const& shape, int const value)
{
    Shape const result = static_cast<Shape>(static_cast<int>(shape) + value);

    assert(Shape::Spade <= result and result <= Shape::Max);
    return result;
}
inline Shape& operator +=(Shape& shape, int const value)
{
    return shape = shape + value;
}
inline Shape& operator ++(Shape& shape) //전위 증가 연산자
{
    return shape += 1;
}
inline Shape operator ++(Shape& shape, int)  //후위 증가 연산자, 일종의 약속, int를 붙이면 후위다
{
    Shape const result = shape;

    ++shape;

    return result;
}
#pragma region 전위 후위 연산자 두번째 (int의 전위 후위 사용)
//Shape operator ++(Shape& shape)  //후위 증가 연산자, 일종의 약속, int를 붙이면 후위다
//{
//
//   // return reinterpret_cast<Shape&>(++reinterpret_cast<int&>(shape));
//}
//Shape operator ++(Shape& shape, int)  //후위 증가 연산자, 일종의 약속, int를 붙이면 후위다
//{
//    return Shape(static_cast<int>(shape)++);
//  //  return Shape(reinterpret_cast<int&>(shape)++);
//}  
#pragma endregion

#pragma endregion

//operator int(Shape & shape) // 암시적으로 인트형으로 취급될때

int main()
{

    Test (static_cast<String>("Test"));   //변환 생성자

    
    String s = static_cast<String>( "text");
    

    ////explicit 사용시 명시적으로 형변환을 해주어야 한다
    //static_cast<char*>(s)[0] = 'T';     

    cout << static_cast<char *>(s)<< endl;



    return 0;

}

