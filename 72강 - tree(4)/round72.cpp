#include <iostream>
#include <map> // ����� ����Ž��Ʈ���� �����Ǿ� �ִ� �ڷᱸ��.
#include <set>

using std::cout;
using std::endl;

using std::map;
using std::make_pair;

using std::set;

// ��ó���� ����
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
		wcscpy_s(szName, _pName); // ���ڿ� ���� �Լ� (������, ������ ����)
	}

};

int main()
{
	set<int> setInt; // ����Ž��Ʈ�� ����� Ž���� ������ �ڷᱸ��.(�� �޸� ����)

	setInt.insert(100);
	setInt.insert(50);
	setInt.insert(150);

	const wchar_t* pStr = L"ROM ���� ���ڿ�";

	map<const wchar_t*, tStdInfo> mapData; // <Ű ��, ���� ������>

	tStdInfo info(L"ȫ�浿", 18, MAN);
	tStdInfo info2(L"��", 25, WOMAN);

	mapData.insert(make_pair(L"ȫ�浿", info)); // make_pair: �� �����͸� �������� ������ִ� �Լ�.
	mapData.insert(make_pair(L"��", info2));    // �� ������ pair ��� �θ���.

	map<const wchar_t*, tStdInfo>::iterator mapIter;
	mapIter = mapData.find(L"ȫ�浿"); // find: Ű ������ �����͸� ã���� ��, pair ���·� ��ȯ.
	// pair �� �ش��ϴ� ���� iterator �� ����Ű�� �ֵ��� �����Ǿ� �ִ�.
	*mapIter; // ������ ������ ����� ���� ������ �����ε� �Լ��� �����Ǿ� �ִ�.

	// pair �� ����ü �����̴�.
	// ���� ����:
	struct pair_example
	{
		const wchar_t* first;
		tStdInfo	   second;
	};

	(*mapIter).first; // pair �� ù��° ������.
	(*mapIter).second; // pair �� �ι�° ������.

	// �������� ���� ����ü�� Ŭ������ ��� ����ϴ� ȭ��ǥ �����ڵ� �����Ǿ� �ִ�.
	mapIter->first;
	mapIter->second;

	// �������� ���� �̸��� Ž���� ���.
	// find �Լ��� end iterator �� ��ȯ�Ѵ�.
	mapIter = mapData.find(L"�Ŀ��");
	if (mapIter == mapData.end())
	{
		cout << "�����͸� ã�� �� ����:(" << endl;
	}

	return 0;
}