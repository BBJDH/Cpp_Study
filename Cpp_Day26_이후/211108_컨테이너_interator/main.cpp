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
			//*i = 5; //���� �Ұ�
		}
		cout << endl;
	}
	void print_allocsize(vector<int>const& vector)
	{
		cout << "���� �޸� �Ҵ�� ũ�� : " << vector.capacity() << endl;
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
	//vector.data �� ���� ���� �ִ¹迭�� ���� �ּҸ�, size�� �迭�� ����� ����
	//vector.capacity�� �Ҵ�� ũ�⸦ ��Ÿ����
	//u.print_allocsize(v1);
	//reserve() �� �� �Ҵ�� ũ�⸦ ������ �� �ִ�.
	//v1.reserve(10);
	//u.print_allocsize(v1);

	//resize() �� ���� �ִ� �迭�� ũ�⸦ ���� �� �� �ִ�. (capacity�� �ʰ��ϴ°�� capacity�� Ŀ����)
	//(���� ����� �ʰ��ϴ� ���ι�° �μ��� ���� ä��ų�, �ι�° �μ��� ���� ��� 0���� �ʱ�ȭ)

	//v1.resize(12,3);
	//u.print_vector(v1.data(), v1.size());
	//cout << "size :" << v1.size() << "\ncapacity: " << v1.capacity() << endl;

	//vector<Usevector> test;
	//test.push_back(0);  //move constuctor�� �ѹ��� ȣ���Ѵ�
	//test.emplace_back(0);   // ������ �ѹ��� ȣ��

	//v1[0]; //���� noexcept, �������忡�� ���ܸ� �������� ����
	//v1.at(0);//�׻� ���ܸ� Ȯ����

	//v1.assign(20, 4); //20size, ���Ҹ� 3���� ä���
	//u.print_vector_useiter_const(v1);

	//v1.assign(15, 3); //15size, ���Ҹ� 3���� ä���(size���� ����)
	//u.print_vector_useiter_const(v1);


	//v.begin(); vector<int>::iterator;
	//v.rbegin(); vector<int>::reverse_iterator; //rbegin �� rend�� �ڿ��� ���� �����ϵ��ϼ��൵ ����
	//v.cbegin(); vector<int>::const_iterator;
	//v.crbegin(); vector<int>::const_reverse_iterator;
	
	//u.print_vector(v1.data(), v1.size());
	//u.print_vector_useiter(v1);
	//u.print_vector_useiter_reverse(v1);
	//u.print_vector_useiter_const(v1);  
	//���� ��� For (Range-Based For)
	//�ܼ� ó������ ������ �ݺ�
	//cout << endl;
	//for (int& i : v1)
	//	cout << i;
	//cout << endl;
	
	//cout << "size :" << v1.size() << ", capacity: " << v1.capacity() << endl;

	//v1.clear(); // ���� ���� ��� �����
	//cout << "size :" << v1.size() << " capacity: " << v1.capacity() << endl;
	//v1.shrink_to_fit(); //���� �����̳��� capacity�� size�� ����� 
	//					//-> �����ϸ� �����ս��� ������ �ִ� 
	//cout << "size :" << v1.size() << " capacity: " << v1.capacity() << endl;

	
	
	//int num = 99;	
	//v1.insert(v1.cbegin(), num);     //Ÿ�Կ� �´� ������ �ش� iterator�� ����
	//u.print_vector_useiter_const(v1);

	//v1.insert(v1.cbegin(), {1, 2, 3, 4}); //ó���� {1,2,3,4}�� �߰� (initializer_list<int> ���)
	//u.print_vector_useiter_const(v1);  
	
	//v1.insert(v1.cbegin(), 5,1); //1�� ó����ġ�� 5�� �߰�
	//u.print_vector_useiter_const(v1);

	vector<int> v1 = { 1,2,3,4,5,6,7 };

	Usevector u;

	u.print_vector_useiter_const(v1); 
	cout << "<<insert>>" << endl;
    v1.insert(v1.cbegin(),int(50)); //&&_val ������� �Ѱ��ְų� Ư�� ����ä�� �ְ���� ��� (move() ���)
	u.print_vector_useiter_const(v1);

	//vector<int> v2{ 0,1,2,3 };
	//v1.insert(v1.cbegin(), v2.begin()+1, v2.end()); // �ش���ġ(ó����ġ)���� �ش� ���ͷ����� ������ŭ ����
	//u.print_vector_useiter_const(v1);

	//v1.erase(v1.cbegin()); //���ϴ� ���� ����ų�
	//u.print_vector_useiter_const(v1);

	//v1.erase(v1.cbegin() + 1, v1.cend() - 1); //���ϴ� ������ ����
	//u.print_vector_useiter_const(v1);

	
		



#pragma region ���� ����

	/*���� �д� �ɷ��� �� �⸣�� �; ���� �����غ��ҽ��ϴ�
	�ش� �����ε��Լ��� ����� ��尡 �ƴҶ� (_container_debug_level>0)
	���ܸ� �������� �ʴ� �Լ���� �ؼ��߽��ϴ�(noexcept Ű���� ���)
	�ٸ� ����� ����� _stl_verify(�׻� �����ؾ��ϴ� ����,���� ó�� ����) �� ����Ͽ�
	_pos(�迭�� index)�� �迭�� ������(capacity�� �ƴ�)�� �Ѿ �����ϴ� ��� ���ܸ� �߻��ϰ� �մϴ�
	(�̸� ���� noexcept Ű����� ������ ��带 �������� ������� �����Ͽ����ϴ�.) ������ ����غ���,*/
	//cout<<v[-1]; //release ��忡�� ���������� �����Ⱚ�� �����ϰ� �ΰ��ֽ��ϴ�

	//�ݸ� at�� ��Ȯ�ϰ� ������ ����� �����ϸ� ���ܸ� ó���մϴ�


	//v.data(); //�迭�� ���� �ּҸ� ��ȯ
	//v.push_back(5);
	//v.emplace_back();//push_back���� ���ɸ鿡�� ����
	//v.reserve(50); //��������� ����
	//v.resize(100);
	//v.assign(100,3);  //100�� ����� 3���� ��� �ʱ�ȭ

	////for (size_t i = 0; i < 100; i++)
	////{
	////	cout << v[i];
	////}

	//v.begin();
	//v.end();
	//for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	//	cout << *i; //*�����ε� 
	

	////�����̳��� �������� �����
	//


	//v.clear();// ������ ����
	//v.shrink_to_fit(); //����� �°� ���δ�
	//cout << v.size() << ", " << v.capacity() << endl;




	//v.erase();
	//{
	//	int j =5;
	//	cout << &j << endl;
	//	//int&& i = static_cast<int &&>(j); //lvalue : �̸��� �پ��ִ°� ,rvalue : 
	//	int && i = move(j); //static_cast<int &&> constexpr�� �Ǿ������� std�� �����ִ�

	//	cout << &i << endl;
	//}  
#pragma endregion

	//char const str[3][5] = { "iam","iron","man" };

	//printstr(str[0]);



	return 0;
}