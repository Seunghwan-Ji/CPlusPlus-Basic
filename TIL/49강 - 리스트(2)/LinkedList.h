#pragma once

typedef struct _tagNode // _tagNode: ����ü ���ǿ��� ���Ǵ� ������ �±� �̸�
{
	int              iData; // ������ ������
	struct _tagNode* pNextNode; // ���� ����� �ּ�
	// struct �� ���̴� ����:
	// C ��Ÿ�Ͽ����� ����ü�� ������ ���ǵ��� ���� ���¿��� �ڽ��� �̸��� ������ ��,
	// struct �� �Բ� ����ؾ� ������ �߻����� �ʴ´�.
}tNode; // tNode: typedef�� ����Ͽ� ����ü�� ���� �����ϰ� ������ �� �ֵ��� ���� �̸�.

typedef struct _tagList
{
	tNode* pHeadNode; // ù ��° ����� �ּ�
	int	   iCount; // ���� ������ ����
}tLinkedList;

// ������ ����Ʈ �ʱ�ȭ
void InitList(tLinkedList* _pList);

// ������ ����Ʈ�� ������ �߰�
void PushBack(tLinkedList* _pList, int _iData);
void PushFront(tLinkedList* _pList, int _iData); // �����Ͱ� �ڰ� �ƴ� �տ� �߰��Ǵ� �Լ�.

// ������ ����Ʈ �޸� ����
void ReleaseList(tLinkedList* _pList);