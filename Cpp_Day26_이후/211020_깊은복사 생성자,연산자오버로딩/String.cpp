#include<cstring>
#include<iostream>

using namespace std;

class String
{


private:
    char* text;
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
        unsigned size = strlen(text_arg) + sizeof(char);
        text = new char[size];
        strcpy_s(text, size, text_arg);
    }
    String(String const& other) :String(other.text)
    {
        cout << "Copy Constructor Call" << endl;
    }
#pragma region =�����ε�
    String operator =(String const& other)
    {
        unsigned const size = strlen(other.text) + sizeof(char);
        delete[] text;
        text = new char[size] {};
        strcpy_s(text, size, other.text);
        return *this;   //copy constructor call
    }

#pragma region +�����ε�
    String operator +(String const& other)
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

#pragma region ==�����ε�
    bool operator ==(String const& other)
    {

        return strcmp(text, other.text) ? 0 : 1;   //copy constructor call
    }
#pragma endregion

#pragma region +=�����ε�
    String operator +=(String const& other)  //+,=�����ε��� �ʿ��ϴ�
    {
        *this = *this + other;
        return *this;   //copy constructor call
    }
#pragma endregion
    String operator -(int const n)
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


};
/**/

int main()
{
    String s1("");
    s1.Print();
    String s2("");
    s2.Print();

    s1 = "aergeth";
    s1.Print();

    s1 = s1 - 3;
    s1.Print();
    //char ch[6];
    //strncpy_s(ch, 6, "dddddddd", 5);
    //cout << ch << endl;

    //cout << "\n=����" << endl;
    //s1 = s2 = "Hi";
    //s1.Print();
    //s2.Print();

    //cout << "\n+����" <<endl;
    //s1.Print();
    //s2.Print();
    //s1 = s1 + s2;
    //s1.Print();
    //s2.Print();

    //s1 = s2;
    //cout << "\n==����" << endl;
    //s1.Print();
    //s2.Print();
    //if (s1==s2)
    //    cout << "TRUE!" << endl;

    //cout << "\n+=����" << endl;
    //s1.Print();
    //s2.Print();
    //s1 += "x";
    //s1.Print();
    //s2 += s1;
    //s2.Print();

    return 0;
}