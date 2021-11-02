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
�����ð��� �ܺο����� ������ �����ε�
*/
int main()
{
    String s1("Test");
    s1.Print();
    s1[0] = 'B';
    s1.Print();

    //String const u = String("Text");
    String const u("Text");
    cout << u[0] << endl;

    //String s2("");
    //s2.Print();

    //s1 = "aergeth";
    //s1.Print();

    //s1 = s1 - 3;
    //s1.Print();
    //char ch[6];
    //strncpy_s(ch, 6, "dddddddd", 5);
    //cout << ch << endl;

    //cout << "\n=����" << endl;
    //s1 = s2 = "Hi";
    //s1.Print();
    //s2.Print();

    //cout << "\n+����" << endl;
    //s1.Print();
    //s2.Print();
    //s1 = s1 + s2;
    //s1.Print();
    //s2.Print();

    //s1 = s2;
    //cout << "\n==����" << endl;
    //s1.Print();
    //s2.Print();
    //if (s1 == s2)
    //    cout << "TRUE!" << endl;

    //cout << "\n+=����" << endl;
    //s1.Print();
    //s2.Print();
    //s1 += "x";
    //s1.Print();
    //s2 += s1;
    //s2.Print();

    return 0;
    return 0;
}