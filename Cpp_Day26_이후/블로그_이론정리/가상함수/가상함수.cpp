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
    virtual ~Base(){}
public:
    int a=-2;
    char b=0xff;
    float c;
    double d;
    
};

class Derived : public Base {
public:
    void Print() override
    {
        cout << "Print() : Derived class\n";
    }

    void Show() 
    {
        cout << "Show() : Derived class\n";
    }
    ~Derived() override {  }
};

int main()
{
    //Base* Base_Ptr;
    //Derived Derived_Instance;
    //Base_Ptr = &Derived_Instance;

    // Virtual function, binded at runtime
    //Base_Ptr->Print();

    // Non-virtual function, binded at compile time
    //Base_Ptr->Show();

    Base* TestBaseClass = new Base();
    Derived* TestDerivedClass = new Derived();

    Base* UpCastVFTable = dynamic_cast<Derived*>(TestDerivedClass);

    printf("%p\n", &(TestBaseClass->a));
    printf("%p\n", &(TestBaseClass->b));
    printf("%p\n", &(TestBaseClass->c));
    printf("%p\n", &(TestBaseClass->d));
    UpCastVFTable->Print();
    delete TestBaseClass;
    delete UpCastVFTable;

    return 0;
}