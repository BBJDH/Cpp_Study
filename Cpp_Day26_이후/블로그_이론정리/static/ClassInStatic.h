class HasStatic
{
public:

	static int const StaticNum = 100;
	
};
class ClassInSameCPP
{
public:

	static int GetStaticNum() 
	{
		return HasStatic::StaticNum;
	}

};
