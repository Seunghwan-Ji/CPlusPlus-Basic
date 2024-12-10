#include <iostream>
#include "LinkedList.h"
#include <list>

using std::cout;
using std::endl;
using std::list;

int main()
{
	// ǥ�� ����Ʈ�� insert �Լ�
	list<int> stdList;
	stdList.push_back(100);
	stdList.push_back(300);

	list<int>::iterator stdIter = stdList.begin();
	stdIter = stdList.insert(++stdIter, 200); // 300 ���� �ڸ��� 200�� ����.
	// insert �Լ��� �߰��� ������ 200�� ����Ű�� iterator �� ��ȯ�Ѵ�.
	// �� ��ȯ iterator �� stdIter ������ �޾����.
	*stdIter; // 200

	// ���� ����
	CList<int> myList;
	myList.push_back(100);
	myList.push_back(300);
	myList.push_back(400);

	CList<int>::iterator listIter = myList.begin();
	++listIter; // iterator �� 300�� ����Ų��.

	listIter = myList.insert(listIter, 200); // 200 �߰�

	// ����Ʈ ���� �� ��ȸ
	cout << "==================" << endl;
	cout << "list iterator test" << endl;
	for (listIter = myList.begin(); listIter != myList.end(); ++listIter)
	{
		cout << *listIter << endl;
	}
	cout << "==================" << endl;

	return 0;
}