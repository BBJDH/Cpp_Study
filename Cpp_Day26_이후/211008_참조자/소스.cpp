#include<iostream>
using namespace std;

void Allocate(int*& ipr);
int main()
{
	//int  f =  2;  //������� ����� ���ڸ��������� Ȯ�� ���� 
	////float f = 5.0f / 2.0f;  //int�� floatȭ
	////()ĳ��Ʈ ������ ���� 
	//// ������, ã�� �����
	//cout << f << endl;

	//int& i = (int&)(f);

	//i = 8; //��
	//cout << f << endl;

	//float& fr = (float&)(f); //const f �ε��� ()ĳ��Ʈ�� ����ϸ� Ǯ�� �־�����

	//fr = 7.0f;  //��


	//ĳ��Ʈ ������ (sizeof ó��)
	//static_cast<int> : �������� ������ ���Ŀ� ���� ��ȯ
	//dynmic_cast : �ٿ� ĳ���ÿ����� ��ȯ
	//const_cast : const �����ڿ� ���� ��ȯ(������ ��ȯ) - �Ͻ������� const ������ ���
	// 	   ->���� ������ ���ٰ� Ȯ�������� Ÿ �Լ����� ĳ�����ؼ� ����
	//reinterpret_cast : �ּҿ� ������ ���� ��ȯ(������ ��ȯ)

	{
		long const  num = 0;
		//(�ڷ��� &) ������ ���۷����� ĳ����
		int& ref = (int&)(num); //�׳� int������ ĳ��Ʈ�ؼ� ���� �ȹٲ�� ������� ���ε�.. 
										//const �ε� ���� Ǯ�����
	//reinterpret_cast : �ּҿ� ������ ���� ��ȯ
	//�������� ����� const �̸� ���� ����
		int const& ref = reinterpret_cast<int const&>(num);
		//���� ���� const�� �����ؼ� �����ϰ� ������� ��
		//ref = 10; // ����, �����ϴ�!

	//const_cast : const �����ڿ� ���� ��ȯ
		int  ref = reinterpret_cast<int&>(const_cast<long&>(num));  //const�� num�� ĳ��Ʈ
		//ref = 5; //����, �����ϴ�!
		//const_cast<long&>(num) = 5; //const�ε� �����ϰ� �Ѵ� �����ϴ�
		//void test(int& ref); ���� test(num)���� ȣ���� �Ұ���������
		//void test(int& const_cast<int&> ref)��  test(num)���� ȣ�� ����?

	}
	//cout << f << endl;

	int* p = nullptr;

	Allocate(p);
	*p = 5;
	cout << *p << endl;
	return 0;
}
void Allocate(int*& ipr)    //�����͸� ���۷����� �޾� ����
{
	ipr = (int*)(malloc(sizeof(int)));
}