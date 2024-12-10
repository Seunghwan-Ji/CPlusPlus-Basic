#include <iostream>
#include "CArr.h"
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	CArr<int> myVector;

	myVector.push_back(1);
	myVector.push_back(2);
	myVector.push_back(3);

	CArr<int>::iterator myIter = myVector.begin();
	*myIter;

	for (; myIter != myVector.end(); ++myIter)
	{
		cout << *myIter << endl;
	}

	myIter = myVector.begin();

	// ����, ���� ������ �Լ� �׽�Ʈ
	int iData = *(myIter++);
	// int iData = *(++myIter);


	// vector::erase
	vector<int> vecInt;

	vecInt.push_back(100);
	vecInt.push_back(200);
	vecInt.push_back(300);
	vecInt.push_back(400);

	vector<int>::iterator vecIter = vecInt.begin();
	vecIter = vecInt.erase(vecIter); // vecIter �� ����Ű�� ���� �����, ���� ����ų ���� ��ȯ�Ѵ�.
	int i = *vecIter; // 200

	return 0;
}