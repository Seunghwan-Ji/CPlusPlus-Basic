#include <iostream>
#include "CArr.h"

using std::cout;
using std::endl;

int main()
{
	CArr<int> myVector;

	myVector.push_back(1);
	myVector.push_back(2);
	myVector.push_back(3);

	CArr<int>::iterator myIter = myVector.begin();
	// 다음 기능들을 사용하기 위해선 operator 함수들을 구현해야 한다.
	// *myIter
	// ++(전위, 후위), --, ==, !=

	return 0;
}