#include <stdio.h> // 코드를 컴파일 하기 전에 전처리(먼저 처리) 하는 구문.

// 재귀 함수 팩토리얼
int Factorial_Re(int iNumber)
{
	if (iNumber == 1)
	{
		return 1;
	}

	return iNumber * Factorial_Re(iNumber - 1);
	// 4 * 3!
	// 3 * 2!
	// 2 * 1!

	// 2 * 1
	// 3 * 2
	// 4 * 6
}

// 피보나치 수열
// 1 1 2 3 5 8 13 21 34 55...
// 1 + 1 = 2
// 1 + 2 = 3
// 2 + 3 = 5
// ...
// n>2일 때, n번째 수는 (n-2)번 계산한다.(3번째 수는 한 번, 4번째 수는 두 번)
int Fibonacci(int iNumber) // 함수로 피보나치 수열 구현
{
	if (iNumber == 1 || iNumber == 2)
	{
		return 1; // n번째 숫자중에 첫번째와 두번째 수는 1 고정
	}

	int iPrev1 = 1;
	int iPrev2 = 1;
	int iValue = 0;

	for (int i = 0; i < iNumber - 2; ++i)
	{               // (n-2)번 반복
		iValue = iPrev1 + iPrev2;
		iPrev1 = iPrev2;
		iPrev2 = iValue;
	}

	return iValue;
}

// 재귀 함수로 피보나치 수열 구현
// n번째 수 = (n-2)째 수 + (n-1)째 수
int Fibonacci_Re(int iNumber)
{
	if (iNumber == 1 || iNumber == 2)
	{
		return 1; // 첫번째 두번째 수는 1 고정
	}

	return Fibonacci_Re(iNumber - 2) + Fibonacci_Re(iNumber - 1);
	// Fibonacci_Re(2) + Fibonacci_Re(3)
	// 1 + Fibonacci_Re(1) + Fibonacci_Re(2)
	// 1 + 1 + 1
	// = 3
}
// 일반 재귀 함수는 속도가 느리기 때문에 수십번째 수를 구하기 위해 걸리는 시간은 일주일이 넘어간다.
// 그러므로 나중에 배울 메모리 사용량을 줄이는 꼬리 재귀를 활용해야 한다.

int main()
{
	int iValue = Factorial_Re(4); // 4!
	printf("%d\n", iValue);

	iValue = Fibonacci(4); // 4번째 수
	printf("%d\n", iValue);

	iValue = Fibonacci_Re(4);
	printf("%d\n", iValue);

	return 0;
}