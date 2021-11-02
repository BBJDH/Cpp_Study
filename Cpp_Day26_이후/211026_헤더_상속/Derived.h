#pragma once


//상속
class Derived : public Base //상속대상에 대한 외부의 접근권한
{									//private로 하면 외부에서 get set 이용 불가
									//이후 자식클래스도 접근 불가
	//Crtl+. 또는 알트 엔터엔터
public:
	void Print() const;

};

//class Derived2 : Base //명시적으로 상속 클래스 접근제한자를 사용하지않을경우
//{							//클래스는 프라이빗 스트럭트는 퍼블릭
//public:
//	Derived2()
//	{
//		Set(5);
//	}
//
//};