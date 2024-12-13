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
	bstInt.insert(make_bstPair(100, 0)); //      100
	bstInt.insert(make_bstPair(150, 0)); //   50      150
	bstInt.insert(make_bstPair(50, 0));  // 25  75  125  175
	bstInt.insert(make_bstPair(25, 0));
	bstInt.insert(make_bstPair(75, 0));
	bstInt.insert(make_bstPair(125, 0));
	bstInt.insert(make_bstPair(175, 0));

	// ���� �����ڿ� ���� �ļ��ڴ� �ڽ��� �ϳ� �Ǵ� ���� ��� �ۿ� ����.

	CBST<int, int>::iterator bstIter;
	bstIter = bstInt.find(150);

	// ������ ����
	bstIter = bstInt.erase(bstIter);
	//      100
	//   50      175
	// 25  75  125  

	bstIter = bstInt.find(100);
	bstIter = bstInt.erase(bstIter);
	//      125
	//   50      175
	// 25  75    

	return 0;
}