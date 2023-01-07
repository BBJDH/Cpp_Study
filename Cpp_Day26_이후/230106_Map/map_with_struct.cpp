#include <iostream>
#include <map>

using namespace std;

struct Account
{
	string Name;
	int ID;
	int Age;
};

struct Info
{
	string Context;
	string Context2;
	string Context3;
};

bool operator>(Account const& Left, Account const& Right)
{
	return Left.Name > Right.Name;
}
bool operator<(Account const& Left, Account const& Right)
{
	return Left.Name < Right.Name;
}
bool operator==(Account const& Left, Account const& Right)
{
	return Left.Name == Right.Name;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	map<Account, Info> Accounts{};
	Account const Junho = { "¡ÿ»£",1,20 };

	Accounts[Junho] = { "i ","am ","Iron Man" };

	cout << Accounts[Junho].Context << Accounts[Junho].Context2 << Accounts[Junho].Context3;

	return 0;
}