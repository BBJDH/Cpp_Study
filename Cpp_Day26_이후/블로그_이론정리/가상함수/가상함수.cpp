#include<iostream>
using namespace std;

class Base {
public:
    virtual void Print()
    {
        cout << "Print() : Base class\n";
    }

    void Show()
    {
        cout << "Show() : Base class\n";
    }
};

class Derived : public Base {
public:
    void Print()
    {
        cout << "Print() : Derived class\n";
    }

    void Show()
    {
        cout << "Show() : Derived class\n";
    }
};

int main()
{
    Base* Base_Ptr;
    Derived Derived_Instance;
    Base_Ptr = &Derived_Instance;

    // Virtual function, binded at runtime
    Base_Ptr->Print();

    // Non-virtual function, binded at compile time
    Base_Ptr->Show();

    return 0;
}