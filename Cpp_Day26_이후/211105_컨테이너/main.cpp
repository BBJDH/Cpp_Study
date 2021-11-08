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


	v.data(); //실제 배열의 시작 주소를 반환


	return 0;
}