#pragma once

typedef struct _tagNode // _tagNode: 구조체 정의에서 사용되는 원래의 태그 이름
{
	int              iData; // 저장할 데이터
	struct _tagNode* pNextNode; // 다음 노드의 주소
	// struct 를 붙이는 이유:
	// C 스타일에서는 구조체가 완전히 정의되지 않은 상태에서 자신의 이름을 참조할 때,
	// struct 와 함께 사용해야 오류가 발생하지 않는다.
}tNode; // tNode: typedef를 사용하여 구조체를 보다 간결하게 참조할 수 있도록 만든 이름.

typedef struct _tagList
{
	tNode* pHeadNode; // 첫 번째 노드의 주소
	int	   iCount; // 쌓인 데이터 개수
}tLinkedList;

// 연결형 리스트 초기화
void InitList(tLinkedList* _pList);

// 연결형 리스트에 데이터 추가
void PushBack(tLinkedList* _pList, int _iData);
void PushFront(tLinkedList* _pList, int _iData); // 데이터가 뒤가 아닌 앞에 추가되는 함수.

// 연결형 리스트 메모리 해제
void ReleaseList(tLinkedList* _pList);