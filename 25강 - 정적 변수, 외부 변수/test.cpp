#include "common.h"
#include <stdio.h>

void Static_and_Extern_Test()
{
	g_iStatic; // �� ���� ���� ���� ���� 'g_iStatic'�� ��Ī�Ѵ�.

	printf("g_iStaic �� ��: %d\n", g_iStatic);
	printf("g_iExtern �� ��: %d\n", g_iExtern);
}