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

	(*bstIter).first;
	bstIter->first;

	(*bstIter).second;
	bstIter->second;
	// 엄밀히 따지면 'bstIter->' 까지는 오퍼레이터 함수 호출이므로,
	// 화살표를 한 번더 사용하여 ''bstIter->->' 이렇게 사용하는게 맞지만,
	// 컴파일러가 문법적으로 보정을 해준 것이다.
	// 단, '->' 연산자 오퍼레이터 함수의 반환값이 주소값일 경우만 보정된다.

	/*bstIter = bstInt.begin();
	for (bstIter = bstInt.begin(); bstIter != bstInt.end(); ++bstIter)
	{
		wcout << bstIter->first << bstIter->second << endl;
	}*/

	return 0;
}