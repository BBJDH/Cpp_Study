#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

int main()
{
	vector<int> v = {1,2,3,4,5};
	

	/*정의 읽는 능력을 좀 기르고 싶어서 관련 공부해보았습니다
	해당 오버로딩함수는 디버그 모드가 아닐때 (_container_debug_level>0) 
	예외를 내보내지 않는 함수라고 해석했습니다(noexcept 키워드 명시)
	다만 디버그 모드라면 _stl_verify(항상 만족해야하는 수식,예외 처리 구문) 을 사용하여 
	_pos(배열의 index)가 배열의 사이즈(capacity가 아님)를 넘어서 참조하는 경우 예외를 발생하게 합니다
	(이를 통해 noexcept 키워드는 릴리즈 모드를 기준으로 명시함을 유추하였습니다.) 실제로 사용해보면,*/
	//cout<<v[-1]; //release 모드에서 정상적으로 쓰레기값을 참조하게 두고있습니다

	//반면 at은 명확하게 범위를 벗어나서 접근하면 예외를 처리합니다


	v.data(); //배열의 시작 주소를 반환
	v.push_back(5);
	v.emplace_back();//push_back보다 성능면에서 좋다
	v.reserve(50); //예약공간을 조절
	v.resize(100);
	v.assign(100,3);  //100개 사이즈를 3으로 모두 초기화

	//for (size_t i = 0; i < 100; i++)
	//{
	//	cout << v[i];
	//}

	v.begin();
	v.end();
	for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
		cout << *i; //*오버로딩 
	//범위 기반 For (Range-Based For)
	//단순 처음부터 끝까지 반복
	cout << endl;
	for (int& i : v)
		cout << i;
	cout << endl;

	//컨테이너의 공통적인 내용들
	
	v.begin(); vector<int>::iterator;
	v.rbegin(); vector<int>::reverse_iterator; //뒤에서 부터 진행
	v.cbegin(); vector<int>::const_iterator;
	v.crbegin(); vector<int>::const_reverse_iterator;

	v.clear();// 데이터 날림
	v.shrink_to_fit(); //사이즈에 맞게 줄인다
	cout << v.size() << ", " << v.capacity() << endl;

	vector<int> v2{0,1,2,3};
	//v.insert(v.cbegin(), {1, 2, 3, 4});
	//v.insert(v.cbegin(), 5,1);
	//v.insert(v.cbegin(), ); &&_val
	v.insert(v.cbegin(), v2.begin()+1, v2.end());


	//v.erase();
	//{
	//	int j =5;
	//	cout << &j << endl;
	//	//int&& i = static_cast<int &&>(j); //lvalue : 이름이 붙어있는값 ,rvalue : 
	//	int && i = move(j); //static_cast<int &&> constexpr로 되어있으며 std에 속해있다

	//	cout << &i << endl;

	//}
	return 0;
}