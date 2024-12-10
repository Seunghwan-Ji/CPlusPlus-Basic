#include <iostream>
#include "LinkedList.h"

int main()
{
	tLinkedList list = {}; // ����ü �ʱ�ȭ.
	InitList(&list); // ������ ����Ʈ �ʱ�ȭ.

	// ���� ������ �߰�
	PushFront(&list, 100);
	PushFront(&list, 200);
	PushFront(&list, 300);

	// ������� ������ Ȯ��.
	tNode* pNode = list.pHeadNode; // ��� ��� �ּ�.
	for (int i = 0; i < list.iCount; ++i) // ����Ʈ�� ��� ������ �� ��ŭ �ݺ�.
	{
		printf("%d\n", pNode->iData); // ��忡 ��� ������ ���.
		pNode = pNode->pNextNode; // ���� ���� ����.
	}

	ReleaseList(&list); // ������ ����Ʈ �� �޸� ����(��� ����)

	return 0;
}