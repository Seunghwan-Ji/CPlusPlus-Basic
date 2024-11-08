#include <stdio.h>
#include <wchar.h> // 와이드 문자 스트링 길이 계산

// 메모리 영역
// 1. 스택
// 2. 데이터
// 3. 힙
// 4. ROM(작성 코드)

unsigned int GetLength(const wchar_t* _pStr)
{
	int icount = 0; // 문자 개수 체크 용도

	while (true)
	{
		// wchar_t c = *(_pStr + icount); 시작 주소로 부터 2바이트 단위로 icount 만큼 증가.
		wchar_t c = _pStr[icount]; // 인자로 받은 배열의 시작 주소는 배열의 이름이기 때문에 이렇게도 작성해볼 수 있다.

		// if (c == 0) 0 = '\0'(null 문자), 0 대신 '\0' 이렇게 작성해도 된다.
		if (0 == c) // == 을 = 으로 잘못 입력하는 실수를 방지하기 위해 습관적으로 상수를 먼저 적고 뒤에 변수명을 적는게 좋다.
		{
			break;
		}

		++icount;
	}

	// 개선(작성자 의도 파악은 전자의 반복문 형태가 보기 좋다.)
	/*while (0 != _pStr[icount])
	{
		++icount;
	}*/

	return icount;
}

int main()
{
	wchar_t szName[10] = L"Raimond";

	int iLen = GetLength(szName);
	printf("문자열의 길이: %d", iLen);

	return 0;
}