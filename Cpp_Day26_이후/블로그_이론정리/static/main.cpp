#include <iostream>
#include "ClassWithNoStatic.h"

using namespace std;



int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cout<<ClassInSameCPP::GetStaticNum();
	cout<<ClassWithNoStatic::GetStaticInOtherClass();

	return 0;
}