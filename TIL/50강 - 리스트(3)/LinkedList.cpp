#include "LinkedList.h"
#include <iostream>

void InitList(tLinkedList* _pList)
{
	_pList->pHeadNode = nullptr; // 연결형 리스트의 초기 헤드 노드의 주소 = nullptr
	_pList->iCount = 0; // 연결형 리스트의 초기 데이터 수 = 0
}

void PushBack(tLinkedList* _pList, int _iData)
{
	tNode* pNode = (tNode*)malloc(sizeof(tNode)); // 힙 영역 내 다른 임의의 공간에 데이터를 저장할 새로운 노드 생성.
	pNode->iData = _iData; // 인자로 받은 데이터를 iData 멤버 파트에 복사.
	pNode->pNextNode = nullptr; // 현재 생성한 노드는 다음 데이터가 들어오기 전 까지는,
	// 다음 노드의 주소를 알 수 없으므로, nullptr 로 설정.

// 추가한 데이터가 처음인지 아닌지 확인.
	if (0 == _pList->iCount)
	{
		_pList->pHeadNode = pNode; // 처음이면 헤드 노드로 지정.
	}
	else
	{
		// 현재 생성한 노드를 제외한 가장 마지막 노드를 찾는다.
		// 찾은 노드의 pNext 에 현재 생성한 노드의 주소를 넣어준다.

		// 방법 1: 각 노드의 pNextNode 를 참조해 값이 nullptr 이면 다음 주소가 없다는 뜻이므로, 해당 노드가 마지막 노드일 것이다.
		// 정해진 반복 횟수가 없으므로 while 문으로 작성.
		// 첫 번째 노드부터 순서대로 조회 해보며 찾아보자.
		tNode* pCurFinalNode = _pList->pHeadNode; // 우선 첫 번째 노드인 헤드 노드의 주소를 지역변수에 담아놓는다.
		while (true)
		{
			if (nullptr == pCurFinalNode->pNextNode)
			{
				break; // 다음 주소가 nullptr 이면 루프 탈출.
			}

			pCurFinalNode = pCurFinalNode->pNextNode; // 지역변수를 다음 노드의 주소로 변경.
		}

		// 반복문 수행이 끝났다면 지역변수는 현재 생성한 노드를 제외한 가장 마지막 노드의 주소가 저장되어 있을 것이다.
		// 해당 노드의 다음 주소 pNextNode 에 현재 생성한 노드 pNode 의 주소를 넣어주자.
		pCurFinalNode->pNextNode = pNode;
	}

	++_pList->iCount; // 쌓인 데이터 수 증가.
}

void PushFront(tLinkedList* _pList, int _iData)
{
	// 새로운 노드 생성.
	tNode* pNewNode = (tNode*)malloc(sizeof(tNode));

	// 새로운 노드에 데이터 저장.
	pNewNode->iData = _iData;

	// 새로운 노드의 다음 노드를 연결형 리스트 객체의 헤드 노드로 설정.
	pNewNode->pNextNode = _pList->pHeadNode;

	// 연결형 리스트 객체의 헤드 노드를 생성해둔 새로운 노드로 갱신.
	_pList->pHeadNode = pNewNode;

	// 데이터 카운트 수 증가.
	++_pList->iCount;
}

// 각 노드 메모리 해제 함수
// 재귀 호출 방식으로, 마지막 노드에서 헤드 노드까지 역순으로 해제.
// 쌓인 노드 수 가 많으면, 그 만큼 재귀 호출이 되기 때문에 효율적이지 않다.
void ReleaseNode(tNode* _pNode)
{
	if (nullptr == _pNode) // 마지막 노드의 다음 노드는 nullptr 이므로,
	{                      // 함수가 인자로 nullptr 주소를 받았으면 이 조건에 걸릴 것이다.
		return; // 쌓인 함수 스택을 지우면서, 같이 노드를 역순으로 지우기 시작할 준비를 하는 단계.
	}

	ReleaseNode(_pNode->pNextNode); // nullptr 주소가 나올 때까지, 계속 다음 노드의 주소를 넣어 재귀 호출.

	free(_pNode); // 노드를 지우고 이전 호출로 돌아가 또 노드를 지우는 것을 반복해 마지막에 헤드 노드까지 삭제.
}

void ReleaseList(tLinkedList* _pList)
{
	// ReleaseNode(_pList->pHeadNode);

	// 반복문을 통해 노드들을 정방향으로 지우기
	tNode* pDeleteNode = _pList->pHeadNode; // 지역변수에 헤드 노드의 주소 저장.

	while (true)
	{
		if (nullptr == pDeleteNode)
		{
			break; // 다음 노드의 주소가 더 이상 없으면 중지.
		}

		tNode* pNext = pDeleteNode->pNextNode; // 지역변수에 다음 노드의 주소 임시 저장.
		free(pDeleteNode); // 노드가 할당된 힙 메모리 해제.
		pDeleteNode = pNext; // 다음 반복에서 참조할 노드의 주소를 임시 저장해둔 다음 노드의 주소로 변경.
	}
}
