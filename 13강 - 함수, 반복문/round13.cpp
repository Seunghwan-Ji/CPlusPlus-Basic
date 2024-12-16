#include <stdio.h> // 스탠다드 인풋 아웃풋 헤더, 구현되어 있는 표준 입출력 함수를 가져온다는 의미.(라이브러리 개념)
// printf();, scanf(); 등의 함수가 구현되어 있다.

// 함수
int Add(int a, int b)
{
	return a + b;
}

int main()
{	
	int iData = Add(100, 200);

	// 반복문
	//for (/*반복자 초기화*/; /*반복자 조건 체크*/; /*반복자 변경*/)
	//{

	//}

	for (int i = 0; i < 10; ++i)
	{
		// 현재 지역변수 i가 10보다 작으면 1을 증가 시킴.
		// i가 10이되면 중지.
		// 즉, i는 0~9까지 변하고 10번 반복.
		printf("Output Test\n");
		// "Output Test" 문장이 10번 출력됨.
	}

	//while (/*조건 체크*/)
	//{

	//}

	// 위에 for 반복문과 같은 표현.
	int i = 0;
	while (i < 10)
	{
		printf("Output Test\n");

		++i;
	}

	// continue
	for (int i = 0; i < 4; ++i)
	{
		if (i % 2 == 1)
		{
			continue; // i를 2로 나눈 나머지가 1일 경우 아래 코드를 수행하지 않고 다음 반복으로 넘어감.
			// while문 안에서도 사용가능
		}

		printf("Output Test\n");
		// "Output Test" 문장이 i가 0일 때와 2일 때, 총 2번 출력됨.
	}

	// break: 반복문에서 이 코드를 만나면 반복문을 종료하고 빠져나감.

	return 0;
}