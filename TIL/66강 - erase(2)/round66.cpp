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
	//myVector.erase(myIter);
	//int i_2 = *myIter; // 예외처리 발생.

	for (myIter = myVector.begin(); myIter != myVector.end(); ++myIter)
	{
		cout << *myIter << endl;
	}

	// 표준 벡터의 erase 함수 활용
	vector<int> vecInt;

	// 1 ~ 10 을 벡터에 입력
	for (int i = 0; i < 10; ++i)
	{
		vecInt.push_back(i + 1);
	}

	// 1 ~ 5 숫자 제거
	//vector<int>::iterator vecIter = vecInt.begin();
	//for (; vecIter != vecInt.end();)
	//{
	//	if (1 <= *vecIter && *vecIter <= 5)
	//	{
	//		// 제거
	//		vecIter = vecInt.erase(vecIter);
	//	}
	//	else
	//	{
	//		// 지우고 나면 데이터가 당겨지므로, 조건을 충족하지 않을 때만 iterator 를 증가시킨다.
	//		++vecIter;
	//	}
	//}

	// 짝수만 제거
	vector<int>::iterator vecIter = vecInt.begin();
	for (; vecIter != vecInt.end();)
	{
		if (0 == *vecIter % 2)
		{
			// 제거 후 iterator 갱신.
			vecIter = vecInt.erase(vecIter);
		}
		else
		{
			// 지우고 나면 데이터가 당겨지므로, 조건을 충족하지 않을 때만 iterator 를 증가시킨다.
			++vecIter;
		}
	}

	// 결과 출력
	for (int i = 0; i < vecInt.size(); ++i)
	{
		cout << vecInt[i] << endl;
	}

	return 0;
}