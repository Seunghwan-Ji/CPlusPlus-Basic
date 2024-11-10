#include <stdio.h>
#include <wchar.h> // 와이드 문자 스트링 길이 계산
#include <assert.h> // 예외처리 용도

// 메모리 영역
// 1. 스택
// 2. 데이터
// 3. 힙
// 4. ROM(작성 코드)

// 함수 오버로딩
// 이름이 같은 함수를 여러개 만듬, 인자의 타입이나 개수의 차이에 따라 동일한 이름의 함수를 여러개 작성할 수 있다.
// 클래스에서 다루는 '함수 오버라이딩'은 다른 개념이다.
void Test(int a)
{

}

void Test(float a)
{

}

unsigned int GetLength(const wchar_t* _pStr)
{
	int icount = 0; // 문자 개수 체크 용도

	while (true)
	{
		wchar_t c = _pStr[icount];

		if (0 == c)
		{
			break;
		}

		++icount;
	}

	return icount;
}

// 문자열 이어 붙이기 함수 구현
void StrCat(wchar_t* _pDest, unsigned int _iBufferSize, const wchar_t* _pSrc) // 배열 사이즈는 양수일 것이기 때문에 unsigned 를 붙인다.
{
	// 예외처리
	// 이어붙인 최종 문자열 길이가, 목적지 저장 공간을 넘어서려는 경우.
	int iDestLen = GetLength(_pDest);
	int iSrcLen = GetLength(_pSrc);

	if (_iBufferSize < iDestLen + iSrcLen + 1) // NULL 문자 공간까지 계산
	{
		assert(nullptr); // 인자로 받은 _iBufferSize 사이즈 보다 초과시 예외처리
	}

	// 문자열 이어 붙이기 구상
	// 1. Dest 문자열의 끝을 확인(문자열이 이어 붙을 시작 위치)
	// 2. 반복적으로 Src 문자열을 Dest 끝 위치에 복사하기
	// 3. Src 문자열의 끝을 만나면 반복 종료

	// iDestLen: Dest 문자열의 끝 인덱스
	for (int i = 0; i < iSrcLen + 1; ++i) // iSrcLen + 1: null(메모리 공간의 0) 문자를 포함시키기 위해 한 번더 반복.
	{
		_pDest[iDestLen + i] = _pSrc[i];
	}
}

int main()
{
	Test(10);
	Test(4.15f);

	// 문자열 이어 붙이기
	wchar_t szString[100] = L"abc";

	wcscat_s(szString, 100, L"def"); // 매개변수: 문자열 배열의 시작 주소, 원본 배열의 사이즈, 이어붙일 와이드 바이트(유니코드)형 문자열
	wprintf(L"%s\n", szString);

	wcscat_s(szString, 100, L"ghi");
	wprintf(L"%s\n", szString);


	wchar_t szString2[5] = L"abc";

	// wcscat_s(szString2, 5, L"defghi"); 이어 붙인 문자의 형태가 사이즈를 초과해서 예외처리 발생.

	StrCat(szString2, 5, L"d");
	wprintf(L"%s\n", szString2);

	// StrCat(szString2, 5, L"de"); null 문자를 포함해 사이즈가 6으로 초과하므로 위에 구현한 함수에서 예외처리 발생.

	// wcscmp: 두 문자열이 일치하면 0, 사전순으로 왼쪽이 먼저면 -1, 오른쪽이 먼저면 1 을 반환하는 함수.
	int iRet = wcscmp(L"abc", L"abc");
	printf("%d\n", iRet);

	return 0;
}