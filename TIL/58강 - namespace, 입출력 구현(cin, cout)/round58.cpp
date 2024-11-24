#include <iostream>

// namespace: 이름 공간
namespace MYSPACE
{
	int g_int; // 함수 내부에 있는 변수가 아니기 때문에 전역변수이다.
}

namespace OTHERSPACE
{
	int g_int;
}

// std:: 키워드를 사용하기 귀찮을 때 사용하는 문법
using namespace std;

// namespace 안에 특정 기능만 키워드 생략시키기
using std::cout;
using std::wcout; // 2바이트 단위 문자열 출력 기능.
using std::cin;
using std::endl;

void MyEndL()
{
	wprintf(L"\n");
}

// 연산자 오버로딩 함수로 입출력 함수 구현
class CMyOStream
{
	// 클래스에 멤버를 지정해두지 않으면 해당 자료형의 크기 단위는
	// 기본적으로 1바이트로 할당된다.
public:
	// 연산자 함수: 숫자 출력
	CMyOStream& operator << (int _iData)
	{
		wprintf(L"%d", _iData);
		return *this;
	}

	// 연산자 함수: 문자열 출력
	CMyOStream& operator << (const wchar_t* _pString)
	{
		wprintf(L"%s", _pString);
		return *this;
	}

	// 연산자 함수: 줄바꿈 문자 출력
	CMyOStream& operator << (void(*_pFunc)(void)) // 함수 포인터를 인자로 받음.
	{
		_pFunc();
		return *this;
	}

	// 연산자 함수: 문자 입력
	CMyOStream& operator >> (int& _iData)
	{
		scanf_s("%d", &_iData);
		return *this;
	}
};

CMyOStream mycout;

int main()
{
	// :: 은 특정 위치의 내부를 확인하는 기호이다.
	// 위 전역변수 g_int 를 접근하는 문법.
	MYSPACE::g_int = 0;

	// C++ #include <iostream> 에서 표준으로 제공해주는 모든 기능들은
	// std 라는 namespace 안에 있다.
	std::cout << "안녕" << 10 << std::endl;

	int iInput = 0;
	std::cin >> iInput;

	// namespace 문법을 통해서 변수명 중복을 해결할 수 있는 특징이 있다.
	// 다른 namespace 에 이름이 같은 변수 접근.
	OTHERSPACE::g_int = 0;

	// 위에서 using namespace 를 작성했으므로 키워드 생략 가능.
	cin >> iInput;

	cout << "안녕" << 10 << endl;
	wcout << "안녕" << 10 << endl;

	// 그러나 MYSPACE, OTHERSPACE 은 내부의 변수명이 서로 같으므로,
	// 두 공간 모두 using namespace 를 사용하게 되면 변수 중복이 일어날 수 밖에 없다.
	// 따라서 공간 자체를 using namespace 하기 보단
	// using std::endl 와 같이 특정 공간에 특정 기능을 자주 사용할 것 같은 것만
	// using 해주는게 좋다.

	// 표준으로 제공해주는 기능인 cout, cin 은 특정 클래스의 객체 변수명이다.
	// 해당 변수는 extern 형태의 외부 변수이며, #include <iostream> 헤더를
	// 참조하게 되면, 참조한 해당 cpp 파일에서 cout, cin 등의 외부변수를 사용할 수
	// 있게 되는것이다.

	// 한글 깨짐 방지 함수들
	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, L"korean");

	// 연산자 오버로딩 함수들 테스트
	int a = 0;
	mycout >> a;

	mycout << 10 << L" " << 20 << L" " << L"문자열" << MyEndL;
	// MyEndL 의 글자색과 cout, wcout의 endl 의 글자색이 같다.
	// MyEndL 의 정체는 함수 이므로, endl 의 정체도 함수인 것을 알 수 있다.

	return 0;
}