#include <iostream>

#include <map> // ����� ����Ž��Ʈ���� �����Ǿ� �ִ� �ڷᱸ��.
#include <set>

#include <string>

#include "CBST.h" // ���� ������ ����Ž��Ʈ�� �ڷᱸ��.

using std::wcout;
using std::endl;

using std::map;
using std::make_pair;

using std::set;

using std::wstring;

int main()
{
	CBST <int, int> bstInt; // ����Ž��Ʈ��

	// ������ �߰�
	bstInt.insert(make_bstPair(100, 0));
	bstInt.insert(make_bstPair(150, 0));
	bstInt.insert(make_bstPair(50, 0));

	// ����� �׽�Ʈ
	CBST<int, int>::iterator bstIter = bstInt.begin();
	bstIter = bstInt.find(150);

	return 0;
}