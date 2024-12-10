#include "common.h"
#include <stdio.h>

void Static_and_Extern_Test()
{
	g_iStatic; // 이 파일 내의 정적 변수 'g_iStatic'을 지칭한다.

	printf("g_iStaic 의 값: %d\n", g_iStatic);
	printf("g_iExtern 의 값: %d\n", g_iExtern);
}