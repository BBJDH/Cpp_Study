#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

void printstr(char const* str)
{
	cout << str << endl;
}
class Usevector 
{
public:
	Usevector():num(0)
	{
		cout << "Constructor Call!" << endl;

	}
	Usevector(Usevector& usevector) :num(usevector.num)
	{
		cout << "Copy Constructor Call!" << endl;
	}
	Usevector(Usevector&& usevector) :num(usevector.num)
	{
		cout << "move Constructor Call!" << endl;
	}

	Usevector(int const val):num(val)
	{
		cout << "Constructor Call!(has val)" << endl;
	}

	~Usevector()
	{
		cout << "Destructor Call!" << endl;

	}

	void print_vector(int const * arr, size_t const size)
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void print_vector_useiter(vector<int> &  v)
	{
		
		for (vector<int>::iterator i = v.begin(); i < v.end(); ++i)
		{
			cout << *i << " ";
		}
		cout << endl;
	}
	void print_vector_useiter_reverse(vector<int>  & v)
	{
		
		for (vector<int>::reverse_iterator  i = v.rbegin(); i < v.rend(); ++i)
		{
			cout << *i << " ";
		}
		cout << endl;
	}
	void print_vector_useiter_const(vector<int>& v)
	{
		
		for (vector<int>::const_iterator i = v.cbegin(); i < v.cend(); ++i)
		{
			cout << *i << " ";
			//*i = 5; //수정 불가
		}
		cout << endl;
	}
	void print_allocsize(vector<int>const& vector)
	{
		cout << "현재 메모리 할당된 크기 : " << vector.capacity() << endl;
	}
	int const getnum()const
	{
		return num;
	}
private:
	int num;

};
int main()
{

	//u.print_vector(v1.data(), v1.size());
	//vector.data 는 실제 값이 있는배열의 시작 주소를, size는 배열의 사이즈를 전달
	//vector.capacity는 할당된 크기를 나타낸다
	//u.print_allocsize(v1);
	//reserve() 는 이 할당된 크기를 조절할 수 있다.
	//v1.reserve(10);
	//u.print_allocsize(v1);

	//resize() 는 값이 있는 배열의 크기를 조절 할 수 있다. (capacity를 초과하는경우 capacity도 커진다)
	//(기존 사이즈를 초과하는 경우두번째 인수로 값을 채우거나, 두번째 인수가 없는 경우 0으로 초기화)

	//v1.resize(12,3);
	//u.print_vector(v1.data(), v1.size());
	//cout << "size :" << v1.size() << "\ncapacity: " << v1.capacity() << endl;

	//vector<Usevector> test;
	//test.push_back(0);  //move constuctor를 한번더 호출한다
	//test.emplace_back(0);   // 생성자 한번만 호출

	//v1[0]; //내부 noexcept, 릴리즈모드에서 예외를 내보내지 않음
	//v1.at(0);//항상 예외를 확인함

	//v1.assign(20, 4); //20size, 원소를 3으로 채운다
	//u.print_vector_useiter_const(v1);

	//v1.assign(15, 3); //15size, 원소를 3으로 채운다(size까지 변동)
	//u.print_vector_useiter_const(v1);


	//v.begin(); vector<int>::iterator;
	//v.rbegin(); vector<int>::reverse_iterator; //rbegin 과 rend로 뒤에서 부터 접근하도록수행도 가능
	//v.cbegin(); vector<int>::const_iterator;
	//v.crbegin(); vector<int>::const_reverse_iterator;
	
	//u.print_vector(v1.data(), v1.size());
	//u.print_vector_useiter(v1);
	//u.print_vector_useiter_reverse(v1);
	//u.print_vector_useiter_const(v1);  
	//범위 기반 For (Range-Based For)
	//단순 처음부터 끝까지 반복
	//cout << endl;
	//for (int& i : v1)
	//	cout << i;
	//cout << endl;
	
	//cout << "size :" << v1.size() << ", capacity: " << v1.capacity() << endl;

	//v1.clear(); // 내부 값을 모두 지운다
	//cout << "size :" << v1.size() << " capacity: " << v1.capacity() << endl;
	//v1.shrink_to_fit(); //현재 컨테이너의 capacity를 size에 맞춘다 
	//					//-> 남용하면 퍼포먼스에 영항이 있다 
	//cout << "size :" << v1.size() << " capacity: " << v1.capacity() << endl;

	
	
	//int num = 99;	
	//v1.insert(v1.cbegin(), num);     //타입에 맞는 변수를 해당 iterator에 삽입
	//u.print_vector_useiter_const(v1);

	//v1.insert(v1.cbegin(), {1, 2, 3, 4}); //처음에 {1,2,3,4}를 추가 (initializer_list<int> 사용)
	//u.print_vector_useiter_const(v1);  
	
	//v1.insert(v1.cbegin(), 5,1); //1을 처음위치에 5개 추가
	//u.print_vector_useiter_const(v1);

	vector<int> v1 = { 1,2,3,4,5,6,7 };

	Usevector u;

	u.print_vector_useiter_const(v1); 
	cout << "<<insert>>" << endl;
    v1.insert(v1.cbegin(),int(50)); //&&_val 상수값을 넘겨주거나 특정 공간채로 주고싶은 경우 (move() 사용)
	u.print_vector_useiter_const(v1);

	//vector<int> v2{ 0,1,2,3 };
	//v1.insert(v1.cbegin(), v2.begin()+1, v2.end()); // 해당위치(처음위치)에서 해당 이터레이터 구간만큼 삽입
	//u.print_vector_useiter_const(v1);

	//v1.erase(v1.cbegin()); //원하는 곳을 지우거나
	//u.print_vector_useiter_const(v1);

	//v1.erase(v1.cbegin() + 1, v1.cend() - 1); //원하는 구간을 삭제
	//u.print_vector_useiter_const(v1);

	
		



#pragma region 강의 내용

	/*정의 읽는 능력을 좀 기르고 싶어서 관련 공부해보았습니다
	해당 오버로딩함수는 디버그 모드가 아닐때 (_container_debug_level>0)
	예외를 내보내지 않는 함수라고 해석했습니다(noexcept 키워드 명시)
	다만 디버그 모드라면 _stl_verify(항상 만족해야하는 수식,예외 처리 구문) 을 사용하여
	_pos(배열의 index)가 배열의 사이즈(capacity가 아님)를 넘어서 참조하는 경우 예외를 발생하게 합니다
	(이를 통해 noexcept 키워드는 릴리즈 모드를 기준으로 명시함을 유추하였습니다.) 실제로 사용해보면,*/
	//cout<<v[-1]; //release 모드에서 정상적으로 쓰레기값을 참조하게 두고있습니다

	//반면 at은 명확하게 범위를 벗어나서 접근하면 예외를 처리합니다


	//v.data(); //배열의 시작 주소를 반환
	//v.push_back(5);
	//v.emplace_back();//push_back보다 성능면에서 좋다
	//v.reserve(50); //예약공간을 조절
	//v.resize(100);
	//v.assign(100,3);  //100개 사이즈를 3으로 모두 초기화

	////for (size_t i = 0; i < 100; i++)
	////{
	////	cout << v[i];
	////}

	//v.begin();
	//v.end();
	//for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	//	cout << *i; //*오버로딩 
	

	////컨테이너의 공통적인 내용들
	//


	//v.clear();// 데이터 날림
	//v.shrink_to_fit(); //사이즈에 맞게 줄인다
	//cout << v.size() << ", " << v.capacity() << endl;




	//v.erase();
	//{
	//	int j =5;
	//	cout << &j << endl;
	//	//int&& i = static_cast<int &&>(j); //lvalue : 이름이 붙어있는값 ,rvalue : 
	//	int && i = move(j); //static_cast<int &&> constexpr로 되어있으며 std에 속해있다

	//	cout << &i << endl;
	//}  
#pragma endregion

	//char const str[3][5] = { "iam","iron","man" };

	//printstr(str[0]);



	return 0;
}