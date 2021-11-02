#include<cstring>
#include<iostream>
#include<cassert>

using namespace std;
#pragma region ��ü�� ��ä �׸��� �ν��Ͻ�
/*
��ü(Entity) : Ư�� ������ ������ �ִ�
��ü(Object) : �������� �ǹ�
�ν��Ͻ� : ��ü�κ��� ������ ��ü�� �ִ� (�޸𸮿� �ε�� ���)
*/
#pragma endregion
//TODO : ������ ǥ�� , ����- �۾�������� Ȯ�ΰ��� 
class String
{
private:
    char* text;

    void Assign(char const* const str)
    {
        unsigned size = strlen(str) + sizeof(char);
        text = new char[size];
        strcpy_s(text, size, str);
    }
public:

    void Print()
    {
        cout << "���ڿ� : " << text << endl;
        cout << "���ڿ� �ּ� : " << static_cast<void*>(text) << endl;
    }
    String()
    {
        cout << "Default Constructor Call" << endl;
    }
    String(char const* const  text_arg)
    {
        Assign(text_arg);
        cout << "Constructor Call : has arg" << endl;

    }
    String(String const& other)
    {
        Assign(other.text);
        cout << "Copy Constructor Call" << endl;
    }

    /*



    */
#pragma region =�����ε�
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

#pragma region +�����ε�
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
#pragma region +�����ε� �ι�°
    //String operator +(String const& other) const //������ ����� �ǵ帮�� �ʱ⿡ const
    //{
    //    char buffer[1024]{};

    //    strcpy_s(buffer,1024, text);
    //    strcat_s(buffer,1024, other.text);

    //    return String(buffer);   //copy constructor call
    //}
#pragma endregion


#pragma region ==�����ε�
    bool operator ==(String const& other)
    {

        return strcmp(text, other.text) ? 0 : 1;   //copy constructor call
    }
#pragma endregion

#pragma region +=�����ε�
    String& operator +=(String const& other)  //+,=�����ε��� �ʿ��ϴ�
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
            cout << "-(int)���� �ʹ� ũ�ų� nullptr �Դϴ�" << endl;
            delete[] text;
            text = nullptr;
            return *this;
        }
    }
    char& operator [](unsigned const index)
    {
        assert(index < strlen(text));
        return text[index];
    }

    char const& operator [](unsigned const index) const
    {

        return const_cast<String&>(*this)[index];
    }

};
/*
TODO: String �� char *const �� �Ͻ�����޵� �� ó��
*/

enum class Shape : unsigned char
{
    Spade,
    Diamond,
    Heart,
    Clover,
    Max
};
#pragma region ������ �ܺ� �����ε� inline ���

//inline -> �ݺ����� �ζ����� �ȵȴ� ������ ������ ����
//�ζ����� ����Ѵ� ������ �Ϸ��� __forceinline
//�������Ͽ����� �뷮�� �����Ѵ�
//���� ���ο��� ���ǵ� �Լ��� �ڵ����� inline
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
inline Shape& operator ++(Shape& shape) //���� ���� ������
{
    return shape += 1;
}
inline Shape operator ++(Shape& shape, int)  //���� ���� ������, ������ ���, int�� ���̸� ������
{
    Shape const result = shape;

    ++shape;

    return result;
}
#pragma region ���� ���� ������ �ι�° (int�� ���� ���� ���)
//Shape operator ++(Shape& shape)  //���� ���� ������, ������ ���, int�� ���̸� ������
//{
//
//   // return reinterpret_cast<Shape&>(++reinterpret_cast<int&>(shape));
//}
//Shape operator ++(Shape& shape, int)  //���� ���� ������, ������ ���, int�� ���̸� ������
//{
//    return Shape(static_cast<int>(shape)++);
//  //  return Shape(reinterpret_cast<int&>(shape)++);
//}  
#pragma endregion

#pragma endregion

//operator int(Shape & shape) // �Ͻ������� ��Ʈ������ ��޵ɶ�

int main()
{
    //

    Shape s = Shape::Max;
    cout << static_cast<int>(s++) << endl;

    for (Shape s = Shape::Spade; s < Shape::Max; s++)
    {
        //  cout << static_cast<int>(s) << endl;
    }

    return 0;

}

