#pragma once
class Base
{
public:
	void Set(int const i);
	int Get() const;


private:

	int i = 0;
//protected:   자식클래스는 i에 접근 가능
//	int i = 0;
};

