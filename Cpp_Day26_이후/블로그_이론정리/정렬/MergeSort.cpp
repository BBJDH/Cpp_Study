#include <iostream>
#include <vector>

using namespace std;

//�������� �迭 �ѹ��� ����
vector<int> SortedArr{};

template<typename T>
void Merge(vector<T> & InputArr, int const IndexOfStart, int const IndexOfMiddle, int const IndexOfEnd)
{
	int IndexOfSortedArr = 0;
	int IndexOfLeftArr = IndexOfStart;
	int IndexOfRightArr = IndexOfMiddle+1;

	//�������� ����ؼ� �迭�� ����� ��� �� ���� ��� - ��� 1500ms
	//vector<int> SortedArr{};
	//SortedArr.resize(IndexOfEnd - IndexOfStart + 1);
	//�� ū���� ���Ͽ� ����
	while (IndexOfLeftArr <= IndexOfMiddle and IndexOfRightArr<= IndexOfEnd)
	{
		if(InputArr[IndexOfLeftArr]<= InputArr[IndexOfRightArr])
		{

			SortedArr[IndexOfSortedArr] = InputArr[IndexOfLeftArr];
			IndexOfLeftArr++;
		}
		else
		{

			SortedArr[IndexOfSortedArr] = InputArr[IndexOfRightArr];
			IndexOfRightArr++;
		}
		IndexOfSortedArr++;
	}
	//���� ���� Ȥ�� ������ �迭�� ��Ҹ� �߰�
	while (IndexOfLeftArr<= IndexOfMiddle)
	{

		SortedArr[IndexOfSortedArr] = InputArr[IndexOfLeftArr];
		IndexOfSortedArr++;
		IndexOfLeftArr++;
	}
	while (IndexOfRightArr <= IndexOfEnd)
	{

		SortedArr[IndexOfSortedArr] = InputArr[IndexOfRightArr];
		IndexOfSortedArr++;
		IndexOfRightArr++;
	}
	for(int i= 0; i< IndexOfEnd - IndexOfStart + 1; i++)
	{
		InputArr[IndexOfStart + i] = SortedArr[i];
	}
}


template<typename T>
void MergeSort(vector<T> & InputArr, int const IndexOfStart, int const IndexOfEnd)
{
	if ((IndexOfEnd - IndexOfStart) < 1)
		return;
	int IndexOfMiddle = (IndexOfStart + IndexOfEnd) / 2;

	MergeSort(InputArr, IndexOfStart,IndexOfMiddle);
	MergeSort(InputArr, IndexOfMiddle+1,IndexOfEnd);
	Merge(InputArr, IndexOfStart, IndexOfMiddle, IndexOfEnd);
}


int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	vector<int> Arr{};

	int Size = 0;
	int IndexOfPrint = 0;

	cin >> Size>> IndexOfPrint;

	SortedArr.resize(Size);
	Arr.resize(Size);
	for(int i=0; i<Size; i++)
	{
		cin >> Arr[i];
	}

	MergeSort<int>(Arr,0, Size -1);

	//for (int const elem : Arr)
	//	cout << elem << "\n";
	cout << Arr[IndexOfPrint - 1];
	return 0;
}