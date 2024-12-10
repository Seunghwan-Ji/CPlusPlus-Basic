#include <iostream>

// namespace: �̸� ����
namespace MYSPACE
{
	int g_int; // �Լ� ���ο� �ִ� ������ �ƴϱ� ������ ���������̴�.
}

namespace OTHERSPACE
{
	int g_int;
}

// std:: Ű���带 ����ϱ� ������ �� ����ϴ� ����
using namespace std;

// namespace �ȿ� Ư�� ��ɸ� Ű���� ������Ű��
using std::cout;
using std::wcout; // 2����Ʈ ���� ���ڿ� ��� ���.
using std::cin;
using std::endl;

void MyEndL()
{
	wprintf(L"\n");
}

// ������ �����ε� �Լ��� ����� �Լ� ����
class CMyOStream
{
	// Ŭ������ ����� �����ص��� ������ �ش� �ڷ����� ũ�� ������
	// �⺻������ 1����Ʈ�� �Ҵ�ȴ�.
public:
	// ������ �Լ�: ���� ���
	CMyOStream& operator << (int _iData)
	{
		wprintf(L"%d", _iData);
		return *this;
	}

	// ������ �Լ�: ���ڿ� ���
	CMyOStream& operator << (const wchar_t* _pString)
	{
		wprintf(L"%s", _pString);
		return *this;
	}

	// ������ �Լ�: �ٹٲ� ���� ���
	CMyOStream& operator << (void(*_pFunc)(void)) // �Լ� �����͸� ���ڷ� ����.
	{
		_pFunc();
		return *this;
	}

	// ������ �Լ�: ���� �Է�
	CMyOStream& operator >> (int& _iData)
	{
		scanf_s("%d", &_iData);
		return *this;
	}
};

CMyOStream mycout;

int main()
{
	// :: �� Ư�� ��ġ�� ���θ� Ȯ���ϴ� ��ȣ�̴�.
	// �� �������� g_int �� �����ϴ� ����.
	MYSPACE::g_int = 0;

	// C++ #include <iostream> ���� ǥ������ �������ִ� ��� ��ɵ���
	// std ��� namespace �ȿ� �ִ�.
	std::cout << "�ȳ�" << 10 << std::endl;

	int iInput = 0;
	std::cin >> iInput;

	// namespace ������ ���ؼ� ������ �ߺ��� �ذ��� �� �ִ� Ư¡�� �ִ�.
	// �ٸ� namespace �� �̸��� ���� ���� ����.
	OTHERSPACE::g_int = 0;

	// ������ using namespace �� �ۼ������Ƿ� Ű���� ���� ����.
	cin >> iInput;

	cout << "�ȳ�" << 10 << endl;
	wcout << "�ȳ�" << 10 << endl;

	// �׷��� MYSPACE, OTHERSPACE �� ������ �������� ���� �����Ƿ�,
	// �� ���� ��� using namespace �� ����ϰ� �Ǹ� ���� �ߺ��� �Ͼ �� �ۿ� ����.
	// ���� ���� ��ü�� using namespace �ϱ� ����
	// using std::endl �� ���� Ư�� ������ Ư�� ����� ���� ����� �� ���� �͸�
	// using ���ִ°� ����.

	// ǥ������ �������ִ� ����� cout, cin �� Ư�� Ŭ������ ��ü �������̴�.
	// �ش� ������ extern ������ �ܺ� �����̸�, #include <iostream> �����
	// �����ϰ� �Ǹ�, ������ �ش� cpp ���Ͽ��� cout, cin ���� �ܺκ����� ����� ��
	// �ְ� �Ǵ°��̴�.

	// �ѱ� ���� ���� �Լ���
	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, L"korean");

	// ������ �����ε� �Լ��� �׽�Ʈ
	int a = 0;
	mycout >> a;

	mycout << 10 << L" " << 20 << L" " << L"���ڿ�" << MyEndL;
	// MyEndL �� ���ڻ��� cout, wcout�� endl �� ���ڻ��� ����.
	// MyEndL �� ��ü�� �Լ� �̹Ƿ�, endl �� ��ü�� �Լ��� ���� �� �� �ִ�.

	return 0;
}