#pragma once

typedef struct _tagNode
{
	int    iData; // 저장할 데이터
	tNode* pNextNode; // 다음 노드의 주소
}tNode;

typedef struct _tagList
{
	tNode* pHeadNode; // 첫 번째 노드의 주소
	int	   iCount; // 쌓인 데이터 개수
}tLinkedList;