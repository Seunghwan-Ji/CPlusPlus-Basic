#include <stdio.h> // 코드를 컴파일 하기 전에 전처리(먼저 처리) 하는 구문.

// 만든 기능이 자주 쓰일 거 같다면, 함수로 작성해서 모듈화하자
// 팩토리얼, n! 계산 함수
// ex) 4! = 1 * 2 * 3 * 4
int Factorial(int iNumber) // iNumber = n
{
	int iValue = 1;

	for (int j = 0; j < iNumber - 1; ++j)
	{
		iValue *= (j + 2);
	}

	printf("%d! = %d\n", iNumber, iValue);

	return iValue; // 팩토리얼 계산 결과
}

int main()
{
	// 팩토리얼 계산 함수 호출
	int iValue = Factorial(4);
	iValue = Factorial(10);

	return 0;
}