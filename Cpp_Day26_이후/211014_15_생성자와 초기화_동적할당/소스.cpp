#include<malloc.h>
#include<cstring>
#include<iostream>


class Dog
{
public:
	enum Breed
	{
		Jindo,
		Shiba,
		Samoyed,
		Bulldog
	};


	void PrintDogName()
	{
		std::cout << this->name;
	}

	Dog() : breed(Dog::Jindo), weight(1), height(1), age(1) {};
	//멤버 초기화 목록
	Dog(Breed const breed, char const* const name, float const height, float const weight, int age)
		: breed(breed), name(nullptr/*_strdup(name)*/), weight(weight), height(height), age(1)   //여기는 생성과 동시에 진행
	{
		//생성 이후 진행
		//this->age = age;
		//this->length = length;
		//this->height = height;
		//this->weight = weight;
		//Dog::age = 1;
		//Dog::height = height;
		//Dog::weight = weight;    //둘다 가능

		unsigned size = strlen(name) + sizeof(char);   //strlen 은 문자열뒤의 /0를 카운트하지않으므로 하나더 사이즈 추가
		Dog::name = new char[size] {}; //해당 공간 초기화

		strcpy_s(Dog::name, size, name);

	}
	~Dog()
	{
		if (Dog::name != nullptr)
			delete Dog::name;
	}
private:
	//Dog* const Parent;
	// (*dog1.parent).parent == dog1.parent->parent 로 부모접근이 가능





private:
	//private 로 기본 세팅된다
	Breed const breed = Breed::Jindo;
	char* name;
	unsigned		    age;   //unsigned int 로 자동 선언됨, signed 도 가능
	float		    height;
	float		    weight;


};


int main()
{
	/*
		복사 초기화 (Copy Initialization, =)
		   - 기본적인 초기화 방식
		직접 초기화 (Direct Initialization, () )
		   - 초기화할 값이 없을 경우, 괄호를 쓰지 않음
		균일 초기화 (Uniform Initialization, {} )
			- Dog dog3{ Dog::Bulldog, 100.0, 3.0};
			  double => int 로  암시적 축소변환에 엄격함


	*/
	//Dog dog0;     //Dog dog0() 는 함수 생성으로 오해함 dog0{}; 는 가능
	//Dog dog1(Dog::Bulldog ,1 ,1);
	//Dog dog2 = Dog(Dog::Jindo, 1, 1);
	//Dog dog3{ Dog::Bulldog, 100.0, 3.0};
	//Dog dog4 = { Dog::Bulldog, 100.0, 3.0 };   //생성자가 있기에 가능하다
	////실무 팁
	//Dog dog5 = Dog(); 
	//Dog dog6
	//{ 
	//	Dog::Bulldog,
	//	100.0,
	//	3.0
	//};
	Dog dog10
	{
		Dog::Samoyed,
		"river",
		100,
		3,
		1,
	};

	dog10.PrintDogName();


	//C 에서의 동적할당 malloc 쓰기전에
	//<malloc.h> 를 선언
	//C++ 버전인 <cstdio>, <cstring> 등이 존재
	//windows.h 는 ms 개발용으로 쓰인다
	//
	// 	   C의 동적 할당과의 차이점
	// 
	// 	     - 언어에서 지원하는 기능으로, 헤더를 추가할 필요가 없다.
	// 	     - 사용자가 크기를 알려 줄 필요가 없다.
	// 	     - 할당한 공간의 포인터에 대해 형 변환(캐스팅)을 수행할 필요가 없다.
	// 	     - 생성한 형식에 대한  개체의 생성자, 소멸자가 호출된다.
	// 	     - 단일 개체와 배열을 할당하고 해제하는 방법이 다르다.
	// 	  
	// 
	//
	//동적 할당 비교
	{
		int* ip = new int; //또는 int()
		delete ip;

		int* p_arr = new int[5]{ 0,2,3 };
		delete[] p_arr;
	}

	//int* ip = malloc(4);    //C++ 에서는 이런 암시적 형변환이 불가하다
	//그렇다면
	{
		int* ip2 = static_cast<int*>(malloc(4));

		free(ip2);
	}
	// -> static_cast는 논리적으로 안전한 형변환을 지원하지만
	//추가적으로 포인터 암시적 형변환이 가능하다
	//스태틱 캐스트를 사용하는게 논리적으로 안전하도록 도와준다
	// 추가 팁 괄호와 띄워쓰기는 병기된다
	// return(0) ==return 0;
	//sizeof ip 도 가능 하지만 자료형은 불가능 sizeof(int)


	//만약 ip가 다시 사용될 여지가 있다면 꼭 nullptr로 초기화된다
	//이를 예외 처리하기위해



	return 0;
}