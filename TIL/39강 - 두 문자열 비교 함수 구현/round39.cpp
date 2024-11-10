#include <stdio.h>
#include <wchar.h> // 와이드 문자 스트링 길이 계산
#include <assert.h> // 예외처리 용도

// 메모리 영역
// 1. 스택
// 2. 데이터
// 3. 힙
// 4. ROM(작성 코드)

// 두 문자열 사전순 비교 함수 구현
char StrBalance(const wchar_t* _str1, const wchar_t* _str2)
{
	char result = 0;
	int strIndex = 0;

	while (true)
	{
		// 주소로 접근했을때의 그 값은 아스키 코드표에서 맵핑된 숫자이기에, 비교 연산으로 접근.
		// 맵핑된 숫자가 더 작거나 큰지를 비교.
		if (_str1[strIndex] < _str2[strIndex]) // 왼쪽 문자열 승
		{
			result = -1;
			break;
		}
		else if (_str1[strIndex] > _str2[strIndex]) // 오른쪽 문자열 승
		{
			result = 1;
			break;
		}
		else if (0 == _str1[strIndex] || 0 == _str2[strIndex]) // 두 문자열의 길이가 같으면서 일치할 경우의 조건
		{
			break;
		}
		else // 두 문자가 같을 경우
		{
			++strIndex;
		}
	}

	return result;
}

int main()
{
	int iRet2 = StrBalance(L"cb", L"abc");
	printf("%d\n", iRet2);

	return 0;
}