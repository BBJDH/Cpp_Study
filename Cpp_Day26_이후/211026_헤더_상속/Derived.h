#pragma once


//���
class Derived : public Base //��Ӵ�� ���� �ܺ��� ���ٱ���
{									//private�� �ϸ� �ܺο��� get set �̿� �Ұ�
									//���� �ڽ�Ŭ������ ���� �Ұ�
	//Crtl+. �Ǵ� ��Ʈ ���Ϳ���
public:
	void Print() const;

};

//class Derived2 : Base //��������� ��� Ŭ���� ���������ڸ� ��������������
//{							//Ŭ������ �����̺� ��Ʈ��Ʈ�� �ۺ�
//public:
//	Derived2()
//	{
//		Set(5);
//	}
//
//};