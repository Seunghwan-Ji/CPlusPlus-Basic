#include <iostream>
#include "LinkedList.h"
#include <list>

using std::cout;
using std::endl;
using std::list;

int main()
{
	// 표준 리스트의 insert 함수
	list<int> stdList;
	stdList.push_back(100);
	stdList.push_back(300);

	list<int>::iterator stdIter = stdList.begin();
	stdIter = stdList.insert(++stdIter, 200); // 300 이전 자리에 200이 들어간다.
	// insert 함수는 추가한 데이터 200을 가리키는 iterator 를 반환한다.
	// 그 반환 iterator 를 stdIter 변수에 받아줬다.
	*stdIter; // 200

	// 실제 구현
	CList<int> myList;
	myList.push_back(100);
	myList.push_back(300);
	myList.push_back(400);

	CList<int>::iterator listIter = myList.begin();
	++listIter; // iterator 가 300을 가리킨다.

	listIter = myList.insert(listIter, 200); // 200 추가

	// 리스트 내부 값 순회
	cout << "==================" << endl;
	cout << "list iterator test" << endl;
	for (listIter = myList.begin(); listIter != myList.end(); ++listIter)
	{
		cout << *listIter << endl;
	}
	cout << "==================" << endl;

	return 0;
}