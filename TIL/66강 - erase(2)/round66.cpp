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
	myVector.erase(myIter);
	int i_2 = *myIter; // ����ó�� �߻�.

	for (myIter = myVector.begin(); myIter != myVector.end(); ++myIter)
	{
		cout << *myIter << endl;
	}

	return 0;
}