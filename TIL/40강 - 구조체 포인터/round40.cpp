#include <stdio.h>
#include <wchar.h> // 와이드 문자 스트링 길이 계산
#include <assert.h> // 예외처리 용도

typedef struct _tagMyST
{
	int	  a; // 멤버라고 부른다.(a, f 는 변수가 아님)
	float f;
	// 총 8바이트 크기
}MYST;

int main()
{
	// 구조체와 포인터
	MYST s = {}; // 8바이트 자료형 변수 s

	MYST* pST = &s; // 8바이트 포인터 변수에 8바이트 변수 s의 주소 저장

	(*pST).a = 100; // 역참조로 s의 주소로 접근해서 8바이트 공간 중에서, int형 a 파트 4바이트 공간에 100을 저장
	(*pST).f = 3.14f; // float형 f 파트 4바이트 공간에 실수 3.14를 저장
	// 역참조를 먼저 해야하기에, 괄호를 묶은것이다.

	// 같은 표현
	pST->a = 100;
	pST->f = 3.14f;

	return 0;
}