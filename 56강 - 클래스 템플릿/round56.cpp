#include <iostream>
#include "CArr.h"

int main()
{
	CArr<int> carr;
	carr.push_back(10);
	carr.push_back(20);
	carr.push_back(30);

	int iData = carr[1];

	CArr<float> carr2;
	carr2.push_back(3.14f);
	carr2.push_back(6.28f);
	carr2.push_back(30.444f);

	float fData = carr2[1];

	return 0;
}