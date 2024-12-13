#include <iostream>

#include <map> // 레드블랙 이진탐색트리가 구현되어 있는 자료구조.
#include <set>

#include <string>

#include "CBST.h" // 직접 구현한 이진탐색트리 자료구조.

using std::wcout;
using std::endl;

using std::map;
using std::make_pair;

using std::set;

using std::wstring;

int main()
{
	CBST <int, int> bstInt; // 이진탐색트리

	// 데이터 추가
	bstInt.insert(make_bstPair(100, 0)); //      100
	bstInt.insert(make_bstPair(150, 0)); //   50      150
	bstInt.insert(make_bstPair(50, 0));  // 25  75  125  175
	bstInt.insert(make_bstPair(25, 0));
	bstInt.insert(make_bstPair(75, 0));
	bstInt.insert(make_bstPair(125, 0));
	bstInt.insert(make_bstPair(175, 0));

	// 중위 선행자와 중위 후속자는 자식이 하나 또는 없는 경우 밖에 없다.

	CBST<int, int>::iterator bstIter;
	bstIter = bstInt.find(150);

	// 데이터 삭제
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