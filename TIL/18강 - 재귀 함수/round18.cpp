#include <stdio.h> // 코드를 컴파일 하기 전에 전처리(먼저 처리) 하는 구문.

// 재귀 함수
// 자기 자신 함수를 호출해도 다른 함수를 호출하는 것처럼 스택 메모리 영역에서 새로운 공간을 사용한다.
int Factorial(int iNumber) // iNumber = n
{
	int iValue = 1;

	for (int j = 0; j < iNumber - 1; ++j)
	{
		iValue *= (j + 2);
	}

	// Factorial(10);
	// 단점, 속도가 느리다.
	// 재귀 함수를 잘못 사용시 함수 스택 메모리가 쌓여서 '스택 오버 플로우' 오류가 발생한다.

	// 재귀 함수를 올바르게 사용할 시 이점
	// 가독성, 구현의 용이

	printf("%d! = %d\n", iNumber, iValue);

	return iValue;
}

int main()
{
	int iValue = Factorial(4);

	return 0;
}