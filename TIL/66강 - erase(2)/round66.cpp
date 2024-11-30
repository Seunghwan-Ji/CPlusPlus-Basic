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

	// erase 함수 테스트
	// myIter = myVector.erase(myIter); // 10 삭제
	myIter = myVector.erase(++myIter); // 20 삭제
	int i_1 = *myIter;

	// 훼손된 iterator 역참조 해보기
	myVector.erase(myIter);
	int i_2 = *myIter; // 예외처리 발생.

	for (myIter = myVector.begin(); myIter != myVector.end(); ++myIter)
	{
		cout << *myIter << endl;
	}

	return 0;
}