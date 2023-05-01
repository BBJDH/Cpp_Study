#pragma once
#include "ClassInStatic.h"


class ClassWithNoStatic
{
public:

	int GetStaticInOtherClass()
	{
		return  HasStatic::StaticNum;
	}

};
