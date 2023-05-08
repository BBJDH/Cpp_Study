#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	map<string, int>TestMap{};
	auto ref =TestMap["ȫ�浿"] = 10;
	TestMap["ȫ�浿"] = 20;
	pair<map<string, int>::iterator,bool> Result = TestMap.insert(make_pair("ȫ�浿", 50));

	return 0;
}