#include "LinkedList.h"
#include <iostream>

void InitList(tLinkedList* _pList)
{
	_pList->pHeadNode = nullptr; // ������ ����Ʈ�� �ʱ� ��� ����� �ּ� = nullptr
	_pList->iCount = 0; // ������ ����Ʈ�� �ʱ� ������ �� = 0
}

void PushBack(tLinkedList* _pList, int _iData)
{
	tNode* pNode = (tNode*)malloc(sizeof(tNode)); // �� ���� �� �ٸ� ������ ������ �����͸� ������ ���ο� ��� ����.
	pNode->iData = _iData; // ���ڷ� ���� �����͸� iData ��� ��Ʈ�� ����.
	pNode->pNextNode = nullptr; // ���� ������ ���� ���� �����Ͱ� ������ �� ������,
	// ���� ����� �ּҸ� �� �� �����Ƿ�, nullptr �� ����.

// �߰��� �����Ͱ� ó������ �ƴ��� Ȯ��.
	if (0 == _pList->iCount)
	{
		_pList->pHeadNode = pNode; // ó���̸� ��� ���� ����.
	}
	else
	{
		// ���� ������ ��带 ������ ���� ������ ��带 ã�´�.
		// ã�� ����� pNext �� ���� ������ ����� �ּҸ� �־��ش�.

		// ��� 1: �� ����� pNextNode �� ������ ���� nullptr �̸� ���� �ּҰ� ���ٴ� ���̹Ƿ�, �ش� ��尡 ������ ����� ���̴�.
		// ������ �ݺ� Ƚ���� �����Ƿ� while ������ �ۼ�.
		// ù ��° ������ ������� ��ȸ �غ��� ã�ƺ���.
		tNode* pCurFinalNode = _pList->pHeadNode; // �켱 ù ��° ����� ��� ����� �ּҸ� ���������� ��Ƴ��´�.
		while (true)
		{
			if (nullptr == pCurFinalNode->pNextNode)
			{
				break; // ���� �ּҰ� nullptr �̸� ���� Ż��.
			}

			pCurFinalNode = pCurFinalNode->pNextNode; // ���������� ���� ����� �ּҷ� ����.
		}

		// �ݺ��� ������ �����ٸ� ���������� ���� ������ ��带 ������ ���� ������ ����� �ּҰ� ����Ǿ� ���� ���̴�.
		// �ش� ����� ���� �ּ� pNextNode �� ���� ������ ��� pNode �� �ּҸ� �־�����.
		pCurFinalNode->pNextNode = pNode;
	}

	++_pList->iCount; // ���� ������ �� ����.
}

void PushFront(tLinkedList* _pList, int _iData)
{
	// ���ο� ��� ����.
	tNode* pNewNode = (tNode*)malloc(sizeof(tNode));

	// ���ο� ��忡 ������ ����.
	pNewNode->iData = _iData;

	// ���ο� ����� ���� ��带 ������ ����Ʈ ��ü�� ��� ���� ����.
	pNewNode->pNextNode = _pList->pHeadNode;

	// ������ ����Ʈ ��ü�� ��� ��带 �����ص� ���ο� ���� ����.
	_pList->pHeadNode = pNewNode;

	// ������ ī��Ʈ �� ����.
	++_pList->iCount;
}

// �� ��� �޸� ���� �Լ�
// ��� ȣ�� �������, ������ ��忡�� ��� ������ �������� ����.
// ���� ��� �� �� ������, �� ��ŭ ��� ȣ���� �Ǳ� ������ ȿ�������� �ʴ�.
void ReleaseNode(tNode* _pNode)
{
	if (nullptr == _pNode) // ������ ����� ���� ���� nullptr �̹Ƿ�,
	{                      // �Լ��� ���ڷ� nullptr �ּҸ� �޾����� �� ���ǿ� �ɸ� ���̴�.
		return; // ���� �Լ� ������ ����鼭, ���� ��带 �������� ����� ������ �غ� �ϴ� �ܰ�.
	}

	ReleaseNode(_pNode->pNextNode); // nullptr �ּҰ� ���� ������, ��� ���� ����� �ּҸ� �־� ��� ȣ��.

	free(_pNode); // ��带 ����� ���� ȣ��� ���ư� �� ��带 ����� ���� �ݺ��� �������� ��� ������ ����.
}

void ReleaseList(tLinkedList* _pList)
{
	// ReleaseNode(_pList->pHeadNode);

	// �ݺ����� ���� ������ ���������� �����
	tNode* pDeleteNode = _pList->pHeadNode; // ���������� ��� ����� �ּ� ����.

	while (true)
	{
		if (nullptr == pDeleteNode)
		{
			break; // ���� ����� �ּҰ� �� �̻� ������ ����.
		}

		tNode* pNext = pDeleteNode->pNextNode; // ���������� ���� ����� �ּ� �ӽ� ����.
		free(pDeleteNode); // ��尡 �Ҵ�� �� �޸� ����.
		pDeleteNode = pNext; // ���� �ݺ����� ������ ����� �ּҸ� �ӽ� �����ص� ���� ����� �ּҷ� ����.
	}
}
