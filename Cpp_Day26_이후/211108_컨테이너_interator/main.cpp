#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

int main()
{
	vector<int> v = {1,2,3,4,5};
	

	/*���� �д� �ɷ��� �� �⸣�� �; ���� �����غ��ҽ��ϴ�
	�ش� �����ε��Լ��� ����� ��尡 �ƴҶ� (_container_debug_level>0) 
	���ܸ� �������� �ʴ� �Լ���� �ؼ��߽��ϴ�(noexcept Ű���� ���)
	�ٸ� ����� ����� _stl_verify(�׻� �����ؾ��ϴ� ����,���� ó�� ����) �� ����Ͽ� 
	_pos(�迭�� index)�� �迭�� ������(capacity�� �ƴ�)�� �Ѿ �����ϴ� ��� ���ܸ� �߻��ϰ� �մϴ�
	(�̸� ���� noexcept Ű����� ������ ��带 �������� ������� �����Ͽ����ϴ�.) ������ ����غ���,*/
	//cout<<v[-1]; //release ��忡�� ���������� �����Ⱚ�� �����ϰ� �ΰ��ֽ��ϴ�

	//�ݸ� at�� ��Ȯ�ϰ� ������ ����� �����ϸ� ���ܸ� ó���մϴ�


	v.data(); //�迭�� ���� �ּҸ� ��ȯ
	v.push_back(5);
	v.emplace_back();//push_back���� ���ɸ鿡�� ����
	v.reserve(50); //��������� ����
	v.resize(100);
	v.assign(100,3);  //100�� ����� 3���� ��� �ʱ�ȭ

	//for (size_t i = 0; i < 100; i++)
	//{
	//	cout << v[i];
	//}

	v.begin();
	v.end();
	for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
		cout << *i; //*�����ε� 
	//���� ��� For (Range-Based For)
	//�ܼ� ó������ ������ �ݺ�
	cout << endl;
	for (int& i : v)
		cout << i;
	cout << endl;

	//�����̳��� �������� �����
	
	v.begin(); vector<int>::iterator;
	v.rbegin(); vector<int>::reverse_iterator; //�ڿ��� ���� ����
	v.cbegin(); vector<int>::const_iterator;
	v.crbegin(); vector<int>::const_reverse_iterator;

	v.clear();// ������ ����
	v.shrink_to_fit(); //����� �°� ���δ�
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
	//	//int&& i = static_cast<int &&>(j); //lvalue : �̸��� �پ��ִ°� ,rvalue : 
	//	int && i = move(j); //static_cast<int &&> constexpr�� �Ǿ������� std�� �����ִ�

	//	cout << &i << endl;

	//}
	return 0;
}