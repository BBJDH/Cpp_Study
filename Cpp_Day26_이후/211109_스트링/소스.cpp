#include<string>
#include<iostream>
#include<map>  //내부적으로 정렬을 시행
#include<unordered_map> //내부적으로 정렬X 해쉬를 사용
//hash 잘게 쪼개다
//찾을때는 해슁 해서 찾는다
//다른키에대해서 해슁 했을때 같은 값이 나올 수 있다.

//갯수가 많아지면 unordered_map 이 유리
//해슁 기법을 한번 찾아보자

using namespace std;

int main()
{
#pragma region string
	//string str = "test";

//string text = "hey";

//str = str + text;
//cout << str.find("es") << endl; //찾아서 첫 원소 위치 반환

//cout << str.substr(4, 4) << endl; //substr, count

//str.c_str(); //constant_string
//str.data(); // char const* 반환 동일
//str.length(); //문자열 길이 반환.
//str.size();   //위와 동일
//str.append("plus"); //strcat 기능 동일 하지만 +오버로딩이있다


////find
////str.find() == string::npos; //찾지 못했을때 반환

////find :문자열에서 문자열을 검색한다.
////rfind : 문자열에서 문자열을 뒤에서부터 검색한다
////find_first_not_of : 첫번째로 해당 문자가 아닌

//cout <<boolalpha<< (str.find("test") == string::npos) << endl;  
#pragma endregion



		//map -> 대항하다? 맵핑의 의미인가
		//선형 컨테이너가 아닌 트리구조
		map<string, int> msi;
	{

		pair<string, int> psi; //first, second
		psi.first = "name";
		psi.second = 0;

		msi.emplace(psi);
	}
	{
		msi.emplace(make_pair("same",1));
	}
	{
		msi["game"] = 2;
		msi["game"] = 5;  //덮어씌워진다

		msi.try_emplace("game", 2); //만약 키값이 없으면 할당

	}

	cout << msi.at("name") << endl;
	cout << msi["game"] << endl;

	return 0;

}