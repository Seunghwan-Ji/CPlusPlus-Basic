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

	(*bstIter).first;
	bstIter->first;

	(*bstIter).second;
	bstIter->second;
	// ������ ������ 'bstIter->' ������ ���۷����� �Լ� ȣ���̹Ƿ�,
	// ȭ��ǥ�� �� ���� ����Ͽ� ''bstIter->->' �̷��� ����ϴ°� ������,
	// �����Ϸ��� ���������� ������ ���� ���̴�.
	// ��, '->' ������ ���۷����� �Լ��� ��ȯ���� �ּҰ��� ��츸 �����ȴ�.

	/*bstIter = bstInt.begin();
	for (bstIter = bstInt.begin(); bstIter != bstInt.end(); ++bstIter)
	{
		wcout << bstIter->first << bstIter->second << endl;
	}*/

	return 0;
}