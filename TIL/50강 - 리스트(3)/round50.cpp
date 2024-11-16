#include <iostream>
#include "LinkedList.h"

int main()
{
	tLinkedList list = {}; // 구조체 초기화.
	InitList(&list); // 연결형 리스트 초기화.

	// 정수 데이터 추가
	PushFront(&list, 100);
	PushFront(&list, 200);
	PushFront(&list, 300);

	// 출력으로 데이터 확인.
	tNode* pNode = list.pHeadNode; // 헤드 노드 주소.
	for (int i = 0; i < list.iCount; ++i) // 리스트에 담긴 데이터 수 만큼 반복.
	{
		printf("%d\n", pNode->iData); // 노드에 담긴 데이터 출력.
		pNode = pNode->pNextNode; // 다음 노드로 갱신.
	}

	ReleaseList(&list); // 연결형 리스트 힙 메모리 해제(노드 삭제)

	return 0;
}