#include <stdio.h> // 코드를 컴파일 하기 전에 전처리(먼저 처리) 하는 구문.
#include "common.h" // 해당 헤더 파일 내용 복붙

// 변수의 종류
// 1. 지역 변수
// 2. 전역 변수
// 3. 정적 변수(static)
// 4. 외부 변수(extern)

// 메모리 영역
// 1. 스택 영역(지역 변수가 해당됨)
// 2. 데이터 영역(전역 변수가 해당됨)
// 3. 읽기 전용(코드, ROM(Read Only Memory))
// 4. 힙 영역

int Test()
{
	static int i = 0; // 최초 한 번 선언되었을 때만 초기화.
	++i;

	return i;
}

int main()
{
	Test();
	Test();
	Test();
	Test();
	int iCall = Test();
	printf("Test 함수 호출 횟수: %d\n", iCall);

	g_iStatic = 100; // 이 파일 내의 정적 변수 'g_iStatic'을 지칭한다.
	g_iExtern = 500; // common.h 헤더 파일에서 변수 g_iExtern 이 있다는 정보를 받고, 컴파일러를 통해서 문법 컴파일 과정으로 값 변경을 시도한다.
	// 링커의 링크 과정을 통해 변수 g_iExtern 이 있는 위치인 extern.cpp 파일에서 해당 값을 변경한다.
	Static_and_Extern_Test(); // 정적 변수 g_iStatic 에 100을 넣었지만, test.cpp 파일에서 g_iStatic 의 값을 출력해 보면 0 이다.
	// 외부 변수 g_iExtern 의 값은 500이 나온다.

// 따라서 변수 하나를 모든 파일에서 값을 조절하고 싶다면,
// 헤더에서 외부 변수를 사용하여 변수명만 알리고, 초기화된 값이 선언된 별도의 cpp 파일에서 값을 참조하게 하자.

// 특정 변수를 다른 파일에서 값을 변경하지 못하게 하고 싶다면, 정적 변수를 사용하자.

	return 0;
}