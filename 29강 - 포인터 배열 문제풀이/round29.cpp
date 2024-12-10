#include <stdio.h>

void Test(int* a) // 정수형 변수의 메모리 주소를 인자로 받는 함수
{
	*a = 500;
}

int main()
{
	// 포인터 이해 확인 문제

	// 문제 1.
	short sArr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // 연속적인 주소를 갖는 2바이트 정수 타입 배열

	int* pI = (int*)sArr; // int 타입 포인터 변수 pI = int 타입으로 변환한 sArr 배열의 시작 주소

	int iData = *((short*)(pI + 2)); // 4바이트 단위 만큼 주소를 오른쪽으로 두 번 이동 후, 그 주소를 short 타입으로 변환 및 역참조한 값

	printf("1번 문제 정답: %d\n", iData);


	// 문제 2.
	char cArr[2] = { 1, 1 }; // 연속적인 주소를 갖는 1바이트 정수 타입 배열

	short* pS = (short*)cArr; // short 타입 포인터 변수 pS = short 타입으로 변환한 cArr 배열의 시작 주소

	iData = *pS; // 포인터 변수 pS의 주소를 역참조한 값

	printf("2번 문제 정답: %d\n", iData);


	int a = 100;

	Test(&a); // a의 주소 전달

	printf("a 출력: %d\n", a);
	// 메인 함수의 지역변수 a를 다른 함수 내부에서 변경하고자 할 때, 주소를 전달해주는 방법이 있다.

	scanf_s("%d", &a); // 콘솔창에 값을 입력 해주면, 해당 변수의 주소로 값을 넣어주는 함수이다.

	return 0;
}