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
	tPair<int, int> pair; // 페어(키, 데이터)

	// 데이터 추가
	pair.first = 100;
	bstInt.insert(pair);

	pair.first = 150;
	bstInt.insert(pair);

	pair.first = 50;
	bstInt.insert(pair);

	return 0;
}