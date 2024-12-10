#include <iostream>

#include <map> // 레드블랙 이진탐색트리가 구현되어 있는 자료구조.
#include <set>

#include <string>

using std::wcout;
using std::endl;

using std::map;
using std::make_pair;

using std::set;

using std::wstring;

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

	_wsetlocale(LC_ALL, L"korean");

	wchar_t szFind[20] = L"츄";
	mapIter = mapData.find(szFind); // const wchar_t* 는 주소를 받아오는 타입이므로,
	// 문자열은 같은데 주소가 다르면 탐색이 안되는 문제가 있다.
	// 따라서 문자열을 다루는 클래스가 필요하다.
	if (mapIter == mapData.end()) // 저장하지 않은 이름을 탐색할 경우.
	{
		wcout << L"데이터를 찾을 수 없음:(" << endl;
	}
	else
	{
		wcout << L"이름: " << mapIter->second.szName << endl;
		wcout << L"나이: " << mapIter->second.age << endl;
		wcout << L"성별: ";
		if (MAN == mapIter->second.gender)
		{
			wcout << L"남자" << endl;
		}
		else if (WOMAN == mapIter->second.gender)
		{
			wcout << L"여자" << endl;
		}
		else
		{
			wcout << L"알 수 없음:(" << endl;
		}
	}

	map<wstring, tStdInfo> mapStdInfo;

	wstring str;
	str = L"abcdef"; // '=' 오퍼레이터 함수가 구현되어 있다.
	// 이 문자열 객체 str 은 주소를 가리키는게 아닌,
	// 자신의 공간안에 문자 데이터를 복사해와서 자체적으로 관리한다.
	str += L"hijk"; // '+=' 오퍼레이터 함수, 문자열을 이어붙일 수 있다.
	str += L"lmnop";
	str[1] = L'c'; // 인덱싱과 값 수정 오퍼레이터 함수도 지원한다.
	// 수정하는 곳은 ROM 영역이 아닌 다른 공간에 복사해왔기 때문에
	// 당연히 수정이 가능하다.

	str = L"ksjdghfjkghksdfhklhgdkljsfhgksdhf";
	// 힙 메모리 영역에서 동적할당하는 클래스이며, 문자열이 길어지면 재할당하는 가변배열과 비슷하다.
	// 표준 vector 의 vector<wchar_t> 와 유사할 것이다.

	// 이외에도 ==, !=, <, > 등의 비교 연산자 기능의 오퍼레이터도 있다.
	// 이진탐색트리 구조인 map 클래스에 문자열을 데이터를 넣게되면,
	// 루트 노드에서 왼쪽으로 갈지, 오른쪽으로 갈지를 str 클래스의 비교 연산자 오퍼레이터를
	// 활용하여 방향을 결정해줄 것이다.

	// map 의 키 값은 비교 연산자가 구현된 클래스만 사용될 수 있다.
	// str 클래스는 비교 연산자가 구현되어 있기 때문에 가능한 것이다.

	return 0;
}