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
	*myIter;

	return 0;
}