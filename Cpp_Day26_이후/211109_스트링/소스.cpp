#include<string>
#include<iostream>
#include<map>  //���������� ������ ����
#include<unordered_map> //���������� ����X �ؽ��� ���
//hash �߰� �ɰ���
//ã������ �ؽ� �ؼ� ã�´�
//�ٸ�Ű�����ؼ� �ؽ� ������ ���� ���� ���� �� �ִ�.

//������ �������� unordered_map �� ����
//�ؽ� ����� �ѹ� ã�ƺ���

using namespace std;

int main()
{
#pragma region string
	//string str = "test";

//string text = "hey";

//str = str + text;
//cout << str.find("es") << endl; //ã�Ƽ� ù ���� ��ġ ��ȯ

//cout << str.substr(4, 4) << endl; //substr, count

//str.c_str(); //constant_string
//str.data(); // char const* ��ȯ ����
//str.length(); //���ڿ� ���� ��ȯ.
//str.size();   //���� ����
//str.append("plus"); //strcat ��� ���� ������ +�����ε����ִ�


////find
////str.find() == string::npos; //ã�� �������� ��ȯ

////find :���ڿ����� ���ڿ��� �˻��Ѵ�.
////rfind : ���ڿ����� ���ڿ��� �ڿ������� �˻��Ѵ�
////find_first_not_of : ù��°�� �ش� ���ڰ� �ƴ�

//cout <<boolalpha<< (str.find("test") == string::npos) << endl;  
#pragma endregion



		//map -> �����ϴ�? ������ �ǹ��ΰ�
		//���� �����̳ʰ� �ƴ� Ʈ������
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
		msi["game"] = 5;  //���������

		msi.try_emplace("game", 2); //���� Ű���� ������ �Ҵ�

	}

	cout << msi.at("name") << endl;
	cout << msi["game"] << endl;

	return 0;

}