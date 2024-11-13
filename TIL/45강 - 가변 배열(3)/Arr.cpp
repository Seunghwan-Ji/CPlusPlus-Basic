#include "Arr.h"
#include <iostream>

void InitArr(tArr* _pArr)
{
	// 총 12바이트 자료형 tArr 에서 각 멤버가 할당하고 있는 공간 수정.
	_pArr->pInt = (int*)malloc(sizeof(int) * 2); // int 포인터를 받는 파트는 int로 캐스팅한 힙 메모리 시작 주소 전달(예시로 8바이트 할당)
	// _pArr->pInt = (int*)malloc(8); 같은 표현, 위 매개변수 표현식은 단순히 상수를 표현, int 크기단위 * 2 = 4 * 2 = 8

	_pArr->iCount = 0; // 쌓인 데이터 개수.
	_pArr->iMaxCount = 2; // 8바이트는 int형 2칸이므로, 한계치 사이즈 2로 설정.
}

// 공간 추가 확장 함수
void Reallocate(tArr* _pArr)
{
	// 배열을 공부할 때 인덱스를 초과하여 값을 넣으면, 프로그래머가 의도하지 않은 문제가 발생할 수 있었다.
	// 가변 배열도 마찬가지로 정해진 공간을 초과하면, 힙 영역 내에서 다른 변수의 주소를 가리키게 되는 문제가 있을 수 있다.
	// 따라서 더 큰 공간으로 새롭게 재할당 받는 방법을 사용한다.

	// 1. 먼저 임시로 지역변수에 새로운 공간을 할당받아 놓는다.(예시로 두배 더 큰 공간)
	int* pNew = (int*)malloc(_pArr->iMaxCount * 2 * sizeof(int)); // iMaxCount * 2: 한계치를 기존 사이즈의 두배로 늘린다.

	// 2. 기존 공간에 있던 데이터들을 새로 할당한 공간으로 복사시킨다.
	for (int i = 0; i < _pArr->iCount; ++i)
	{
		pNew[i] = _pArr->pInt[i];
	}

	// 3. 기존 공간의 메모리는 해제한다.
	free(_pArr->pInt);

	// 4. 새로 할당된 공간을 가리키게 한다.
	_pArr->pInt = pNew;

	// 5. iMaxCount 의 값을 수정한다.
	_pArr->iMaxCount *= 2;
}

void PushBack(tArr* _pArr, int _iData)
{
	// 힙 영역에 할당한 공간이 다 찼을 경우의 조건
	if (_pArr->iMaxCount <= _pArr->iCount)
	{
		// 재할당
		Reallocate(_pArr);
	}

	// 데이터 추가
	_pArr->pInt[_pArr->iCount++] = _iData; // 추가할 데이터 위치 = 쌓인 데이터 개수, iCount++: 후위 연산자, 앞에 연산이 끝나고 ++ 수행.
}                                          // 힙 메모리도 배열처럼 연속된 메모리 블록으로 할당되기 때문에 [] 연산자로 인덱싱 표현이 가능하다.

void ReleaseArr(tArr* _pArr)
{
	free(_pArr->pInt); // 힙 메모리 해제
	_pArr->iCount = 0;
	_pArr->iMaxCount = 0;
	// 해제했기 때문에 가리키는 공간이 없으므로 모두 0.
}
