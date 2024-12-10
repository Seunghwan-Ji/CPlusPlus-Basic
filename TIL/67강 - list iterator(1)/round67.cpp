#include <iostream>
#include "LinkedList.h"
#include <list>

using std::cout;
using std::endl;
using std::list;

int main()
{
	CList<int> myList;
	myList.push_back(100);
	myList.push_back(200);
	myList.push_back(300);

	CList<int>::iterator listIter = myList.begin();
	*listIter = 150;

	// ����Ʈ ���� �� ��ȸ
	cout << "==================" << endl;
	cout << "list iterator test" << endl;
	for (listIter = myList.begin(); listIter != myList.end(); ++listIter)
	{
		cout << *listIter << endl;
	}
	cout << "==================" << endl;

	// ǥ�� ����Ʈ�� insert �Լ�
	list<int> stdList;
	stdList.push_back(100);
	stdList.push_back(300);

	list<int>::iterator stdIter = stdList.begin();
	stdIter = stdList.insert(++stdIter, 200); // 300 ���� �ڸ��� 200�� ����.
	// insert �Լ��� �߰��� ������ 200�� ����Ű�� iterator �� ��ȯ�Ѵ�.
	// �� ��ȯ iterator �� stdIter ������ �޾����.
	*stdIter; // 200

	return 0;
}