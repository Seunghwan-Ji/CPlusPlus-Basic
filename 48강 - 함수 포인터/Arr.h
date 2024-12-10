#pragma once

// 가변 배열 기능을 갖춘 자료형, 이 자료형으로 생성한 변수 객체들로 가변배열 기능을 사용하기 위한 목적이다.
typedef struct _tabArr
{
	int* pInt; // 데이터를 받아 저장할 때, 자료형의 크기 자체가 한계가 있기 때문에, 힙 메모리의 시작 주소를 받는 용도.
	int  iCount; // 데이터를 받을 때마다 힙 메모리 주소로 접근했을 때,
	// 시작 주소로부터 몇번째 만큼 떨어진 위치에 저장해야 하는지 참조하기 위해 데이터를 받은 횟수를 기록하는 용도.
	int  iMaxCount; // 힙 메모리에 데이터가 모두 채워졌을 때 한계치를 늘리기 위해,
	// 힙 메모리의 전체 칸 수를 기록하여 iCount 와 비교하는 용도.
}tArr;

// 가변 배열 초기화 함수
void InitArr(tArr* _pArr); // 초기화만 하기에 반환값은 필요하지 않으므로, void 타입.

// 데이터 추가 함수
void PushBack(tArr* _pArr, int _iData); // 추가할 데이터를 인자로 받도록 한다.

// 공간 추가 확장 함수
// void Reallocate(tArr* _pArr); 메인 함수에서는 호출할 일이 없고, 실제 구현되어있는 Arr.cpp 파일 내에서만 사용되는 함수이므로,
//                               선언하지 않아도 된다.

// 힙 메모리 해제 함수
void ReleaseArr(tArr* _pArr);

// 데이터 정렬 함수
void Sort(tArr* _pArr, void(*SortFunc)(int*, int));
//                     반환 타입 void, 임의의 함수 주소, 그 함수의 인자 타입 구성