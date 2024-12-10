#include <iostream>
#include "Arr.h"
#include <time.h> // 시간 확인과 랜덤 함수 사용 목적

void BubbleSort(int* _pData, int _iCount)
{
	// 데이터가 1개 이하면 정렬하지 않음.
	if (_iCount <= 1)
		return;

	// 오름차순 정렬(버블 정렬 알고리즘 사용)
	while (true)
	{
		bool bFinish = true; // 버블 정렬중에 교체가 일어났는지 확인용.

		int iLoop = _iCount - 1; // 데이터 수가 n개라면, 비교하는 횟수는 n-1번이다.

		// 버블 정렬 한 사이클 수행 구문.
		for (int i = 0; i < iLoop; ++i)
		{
			if (_pData[i] > _pData[i + 1])
			{
				int iTemp = _pData[i]; // 옮길 값을 지역변수에 임시 저장.
				_pData[i] = _pData[i + 1]; // 교체.
				_pData[i + 1] = iTemp; // 저장해둔 값 적용.

				bFinish = false; // 교체가 일어남을 알림.
			}
		}

		if (bFinish)
			break; // 버블 정렬 한 사이클을 돌았을 때 교체가 일어나지 않았다면, 전체적으로 정렬이 끝났으므로 루프 종료.
	}
}

void Test()
{

}

int main()
{
	// 함수 포인터
	// 함수의 주소를 전달해 다른 함수에서 전달한 함수의 기능을 사용.
	// 함수의 이름 자체가 주소로 인정된다.

	// 함수 포인터 선언 방법
	void(*pFunc)(void) = nullptr; // 반환 타입 void, 함수 포인터 변수, 인자 void
	// 선언 당시에 주소에 해당하는 함수의 형태(반환 타입, 인자 타입)를 맞춰줘야 한다.
	pFunc = Test;

	// 또는 void(*pFunc)(void) = Test;

	pFunc(); // Test 함수를 호출한다.

	int iArr[10] = { 87, 644, 21, 55, 879, 654, 55, 131 };

	BubbleSort(iArr, 10);

	tArr s1 = {};

	InitArr(&s1);

	srand(time(nullptr));

	// 1 ~ 100 까지의 임의의 난수 데이터 저장.
	for (int i = 0; i < 10; ++i)
	{
		int iRand = rand() % 100 + 1;
		PushBack(&s1, iRand);
	}

	// 데이터 확인.
	printf("정렬 전\n");
	for (int i = 0; i < s1.iCount; ++i)
	{
		printf("%d\n", s1.pInt[i]);
	}

	// 데이터 정렬 후 재확인.
	printf("\n정렬 후\n");

	Sort(&s1, &BubbleSort); // 함수 이름 자체가 주소이지만, & 연산자를 붙여 의도를 명시적으로 표현해도 된다.

	for (int i = 0; i < s1.iCount; ++i)
	{
		printf("%d\n", s1.pInt[i]);
	}

	// 프로그램 종료하기 전, 할당받은 힙 메모리 해제.
	ReleaseArr(&s1);

	return 0;
}

// 개인적으로 버블 정렬 외에 다양한 정렬 방식을 구현해 보자
// - 삽입 정렬
// - 선택 정렬
// - 합병 정렬(merge)
// - 쾌속 정렬(quick)
// - 힙 정렬(완전 이진트리, 배열)

// 위 함수들을 구현해서 Sort 함수로 전달해 테스트 해보기.