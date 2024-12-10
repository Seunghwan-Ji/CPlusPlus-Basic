#include <iostream>
#include "CArr.h"
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	CArr<int> myVector;

	myVector.push_back(10);
	myVector.push_back(20);
	myVector.push_back(30);

	CArr<int>::iterator myIter = myVector.begin();
	*myIter;

	// erase �Լ� �׽�Ʈ
	// myIter = myVector.erase(myIter); // 10 ����
	myIter = myVector.erase(++myIter); // 20 ����
	int i_1 = *myIter;

	// �Ѽյ� iterator ������ �غ���
	//myVector.erase(myIter);
	//int i_2 = *myIter; // ����ó�� �߻�.

	for (myIter = myVector.begin(); myIter != myVector.end(); ++myIter)
	{
		cout << *myIter << endl;
	}

	// ǥ�� ������ erase �Լ� Ȱ��
	vector<int> vecInt;

	// 1 ~ 10 �� ���Ϳ� �Է�
	for (int i = 0; i < 10; ++i)
	{
		vecInt.push_back(i + 1);
	}

	// 1 ~ 5 ���� ����
	//vector<int>::iterator vecIter = vecInt.begin();
	//for (; vecIter != vecInt.end();)
	//{
	//	if (1 <= *vecIter && *vecIter <= 5)
	//	{
	//		// ����
	//		vecIter = vecInt.erase(vecIter);
	//	}
	//	else
	//	{
	//		// ����� ���� �����Ͱ� ������Ƿ�, ������ �������� ���� ���� iterator �� ������Ų��.
	//		++vecIter;
	//	}
	//}

	// ¦���� ����
	vector<int>::iterator vecIter = vecInt.begin();
	for (; vecIter != vecInt.end();)
	{
		if (0 == *vecIter % 2)
		{
			// ���� �� iterator ����.
			vecIter = vecInt.erase(vecIter);
		}
		else
		{
			// ����� ���� �����Ͱ� ������Ƿ�, ������ �������� ���� ���� iterator �� ������Ų��.
			++vecIter;
		}
	}

	// ��� ���
	for (int i = 0; i < vecInt.size(); ++i)
	{
		cout << vecInt[i] << endl;
	}

	return 0;
}