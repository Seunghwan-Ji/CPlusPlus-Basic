#include <iostream>
#include <map> // 레드블랙 이진탐색트리가 구현되어 있는 자료구조.
#include <set>

using std::cout;
using std::endl;

using std::map;
using std::make_pair;

using std::set;

// 전처리기 구문
#define MAN 1
#define WOMAN 2

struct tStdInfo
{
	wchar_t		  szName[20];
	unsigned char age;
	unsigned char gender;

	tStdInfo()
		: szName{}
		, age(0)
		, gender(0)
	{
	}

	tStdInfo(const wchar_t* _pName, unsigned char _age, unsigned char _gender)
		: szName{}
		, age(_age)
		, gender(_gender)
	{
		wcscpy_s(szName, _pName); // 문자열 복사 함수 (목적지, 가져올 원본)
	}

};

int main()
{
	set<int> setInt; // 이진탐색트리 기반의 탐색에 용이한 자료구조.(힙 메모리 영역)

	setInt.insert(100);
	setInt.insert(50);
	setInt.insert(150);

	const wchar_t* pStr = L"ROM 영역 문자열";

	map<const wchar_t*, tStdInfo> mapData; // <키 값, 실제 데이터>

	tStdInfo info(L"홍길동", 18, MAN);
	tStdInfo info2(L"츄", 25, WOMAN);

	mapData.insert(make_pair(L"홍길동", info)); // make_pair: 두 데이터를 묶음으로 만들어주는 함수.
	mapData.insert(make_pair(L"츄", info2));    // 그 묶음을 pair 라고 부른다.

	map<const wchar_t*, tStdInfo>::iterator mapIter;
	mapIter = mapData.find(L"홍길동"); // find: 키 값으로 데이터를 찾았을 때, pair 형태로 반환.
	// pair 에 해당하는 노드는 iterator 가 가리키고 있도록 구현되어 있다.
	*mapIter; // 포인터 역참조 기능을 가진 연산자 오버로딩 함수도 구현되어 있다.

	// pair 는 구조체 형태이다.
	// 형태 예시:
	struct pair_example
	{
		const wchar_t* first;
		tStdInfo	   second;
	};

	(*mapIter).first; // pair 의 첫번째 데이터.
	(*mapIter).second; // pair 의 두번째 데이터.

	// 역참조할 곳이 구조체나 클래스일 경우 사용하는 화살표 연산자도 구현되어 있다.
	mapIter->first;
	mapIter->second;

	// 저장하지 않은 이름을 탐색할 경우.
	// find 함수는 end iterator 를 반환한다.
	mapIter = mapData.find(L"파우더");
	if (mapIter == mapData.end())
	{
		cout << "데이터를 찾을 수 없음:(" << endl;
	}

	return 0;
}