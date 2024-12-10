#include <stdio.h> // 코드를 컴파일 하기 전에 전처리(먼저 처리) 하는 구문.

int main()
{
	// 콘솔: 입력/출력 장치, 입력/출력 콘솔창, 윈도우에서는 명령 프롬프트라고 불림. 리눅스에서는 쉘.

	// printf: 출력 함수
	//printf("ㅎㅇ\n");
	//printf("abcdef %d\n", 10); // %d: 두번째 인자의 정수로 치환.
	//printf("abcdef %f\n", 3.14f); // %f: 두번째 인자의 실수로 치환.

	for (int i = 0; i < 10; ++i)
	{
		printf("Output i : %d\n", i);
	}

	// scanf: 입력 함수
	int iInput = 0;
	scanf_s("%d", &iInput); // scanf 함수 사용 양식

	return 0;
}