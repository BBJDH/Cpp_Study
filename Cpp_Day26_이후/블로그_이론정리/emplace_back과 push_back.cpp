#include <iostream>
#include <vector>
using namespace std;


class Base
{
public:
    Base() :Num{0} { cout << "Constructor Call!\n"; }
    Base(int const& num) :Num{ num } { cout << "Constructor Call!\n"; }
    Base(Base const & base) :Num{ base.Num } { cout << "Copy Constructor Call!\n"; }
	Base(Base && base)noexcept { this->Num = move(base.Num);  cout << "Move Constructor Call!\n"; }

private:
    int Num{};
};


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<Base> Vector1{};

    //vector1.push_back({ 1 });
	//vector1.emplace_back( 1 );

    vector<unique_ptr<int>> Unique_Ptr_Vector{};
    Unique_Ptr_Vector.push_back(unique_ptr<int>(new int(123)));
    Unique_Ptr_Vector.emplace_back(unique_ptr<int>(new int(123)));
    Unique_Ptr_Vector.push_back(nullptr);
    Unique_Ptr_Vector.emplace_back(nullptr);

	
    return 0;
}
