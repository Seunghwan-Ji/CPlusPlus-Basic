#include <iostream>

#include <map> // ����� ����Ž��Ʈ���� �����Ǿ� �ִ� �ڷᱸ��.
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

	_wsetlocale(LC_ALL, L"korean");

	wchar_t szFind[20] = L"��";
	mapIter = mapData.find(szFind); // const wchar_t* �� �ּҸ� �޾ƿ��� Ÿ���̹Ƿ�,
	// ���ڿ��� ������ �ּҰ� �ٸ��� Ž���� �ȵǴ� ������ �ִ�.
	// ���� ���ڿ��� �ٷ�� Ŭ������ �ʿ��ϴ�.
	if (mapIter == mapData.end()) // �������� ���� �̸��� Ž���� ���.
	{
		wcout << L"�����͸� ã�� �� ����:(" << endl;
	}
	else
	{
		wcout << L"�̸�: " << mapIter->second.szName << endl;
		wcout << L"����: " << mapIter->second.age << endl;
		wcout << L"����: ";
		if (MAN == mapIter->second.gender)
		{
			wcout << L"����" << endl;
		}
		else if (WOMAN == mapIter->second.gender)
		{
			wcout << L"����" << endl;
		}
		else
		{
			wcout << L"�� �� ����:(" << endl;
		}
	}

	map<wstring, tStdInfo> mapStdInfo;

	wstring str;
	str = L"abcdef"; // '=' ���۷����� �Լ��� �����Ǿ� �ִ�.
	// �� ���ڿ� ��ü str �� �ּҸ� ����Ű�°� �ƴ�,
	// �ڽ��� �����ȿ� ���� �����͸� �����ؿͼ� ��ü������ �����Ѵ�.
	str += L"hijk"; // '+=' ���۷����� �Լ�, ���ڿ��� �̾���� �� �ִ�.
	str += L"lmnop";
	str[1] = L'c'; // �ε��̰� �� ���� ���۷����� �Լ��� �����Ѵ�.
	// �����ϴ� ���� ROM ������ �ƴ� �ٸ� ������ �����ؿԱ� ������
	// �翬�� ������ �����ϴ�.

	str = L"ksjdghfjkghksdfhklhgdkljsfhgksdhf";
	// �� �޸� �������� �����Ҵ��ϴ� Ŭ�����̸�, ���ڿ��� ������� ���Ҵ��ϴ� �����迭�� ����ϴ�.
	// ǥ�� vector �� vector<wchar_t> �� ������ ���̴�.

	// �̿ܿ��� ==, !=, <, > ���� �� ������ ����� ���۷����͵� �ִ�.
	// ����Ž��Ʈ�� ������ map Ŭ������ ���ڿ��� �����͸� �ְԵǸ�,
	// ��Ʈ ��忡�� �������� ����, ���������� ������ str Ŭ������ �� ������ ���۷����͸�
	// Ȱ���Ͽ� ������ �������� ���̴�.

	// map �� Ű ���� �� �����ڰ� ������ Ŭ������ ���� �� �ִ�.
	// str Ŭ������ �� �����ڰ� �����Ǿ� �ֱ� ������ ������ ���̴�.

	return 0;
}