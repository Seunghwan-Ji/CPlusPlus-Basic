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
	bstInt.insert(make_bstPair(100, 0));
	bstInt.insert(make_bstPair(150, 0));
	bstInt.insert(make_bstPair(50, 0));

	// 디버깅 테스트
	CBST<int, int>::iterator bstIter = bstInt.begin();
	bstIter = bstInt.find(150);

	return 0;
}