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
	tPair<int, int> pair; // ���(Ű, ������)

	// ������ �߰�
	pair.first = 100;
	bstInt.insert(pair);

	pair.first = 150;
	bstInt.insert(pair);

	pair.first = 50;
	bstInt.insert(pair);

	return 0;
}