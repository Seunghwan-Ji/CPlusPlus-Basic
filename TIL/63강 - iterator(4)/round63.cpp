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

	// ������ ������ �����ε� �Լ� �׽�Ʈ(++(����), --(����), ==, !=)
	CArr<int>::iterator myIter = myVector.begin();
	*myIter;

	for (; myIter != myVector.end(); ++myIter)
	{
		cout << *myIter << endl;
	}
	/*for (; ���ǽ�; ������)�� �ǹ�
	�ʱ���� ����θ� ������ ���۵� �� �ƹ� �͵� ���� �ʴ´ٴ� �ǹ��Դϴ�.
	�׷��� ���ǽİ� �������� ������ ���������� �۵��մϴ�.
	�̴� �ʱⰪ�� �̹� ������ �� ��쳪 �ݺ� ������ �ʱ�ȭ�� �ʿ����� ���� ��쿡 �����մϴ�.*/

	myIter = myVector.begin();

	// ������� ���� �Ʒ� �����ڵ��� � ��� �Լ��� ȣ���ϴ��� Ȯ���غ���.
	myIter++;
	++myIter;

	return 0;
}