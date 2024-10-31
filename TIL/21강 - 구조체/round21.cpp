#include <stdio.h> // 코드를 컴파일 하기 전에 전처리(먼저 처리) 하는 구문.

// 컴파일러: 사람이 이해할 수 있는 코드(소스 코드)를 컴퓨터가 실행할 수 있는 **기계어 코드(바이너리 코드)**로 변환하는 프로그램.

// 자료형 = 데이터 타입
// 사용자 정의 자료형 = 사용하고 싶은 데이터 타입의 집합(나만의 자료형 커스텀)
// 구조체
typedef struct _tagMyST // 구조체 문법
{
	int a;
	float f;
	// a, f는 변수로 선언된게 아니다.
	// 사용자 정의 타입에 세부적인 파트로 접근할 때 int는 a, float은 f 라고 이름을 명시해 둔다.
}MYST; // 이름 부여, 4바이트(int) + 4바이트(float) = 8바이트 크기의 사용자 정의 자료형 'MYST' 타입

// 구조체안에 다른 구조체 넣기
typedef struct _tagBig
{
	MYST k;
	int a;
	char c;
}BIG;

// typedef: 타입 재정의를 의미
typedef int INT; // 기존의 자료형을 새로운 이름으로 재정의.

// struct: 기본 자료형이 아닌 구조체 형태의 사용자 정의 자료형을 의미
struct NewStruct
{
	int a;
	short s;
};

// typedef을 통해 이름 부여
typedef struct NewStruct2
{
	int a;
	short s;
}NEWST; // 이름

int main()
{
	// 구조체
	MYST t;
	t.a = 10; // a: int(위에서 명시함)
	t.f = 10.2312f; // f: float(위에서 명시함)

	int iSize = sizeof(MYST);
	printf("%d\n", iSize);

	INT a; // 기존 int 자료형을 이름을 바꿔 재정의한 것이기 때문에 컴파일러가 int로 받아들인다.

	struct NewStruct s; // C언어 문법에서는 'NewStruct'가 구조체 자료형임을 'struct'로 표기해줘야한다.

	NEWST s; // 'struct'표기가 귀찮으면, 'typedef'을 통해 재정의 하여 이름을 부여하고, 'struct' 표기 없이 이름으로 선언할 수 있다.

	NewStruct s; // C++ 에서는 'struct'를 표기하지 않아도 되고, 'typedef'으로 이름 부여할 필요 없이 이렇게 선언 가능(C++에서 개선된 케이스)
	// 따라서, 위에서 'typedef'으로 구조체를 작성한 것들은 C언어 스타일이다.

	// Window API의 함수들은 모든 구조체가 'typedef'으로 작성되어 있다.
	// 이유는 C와 C++ 양쪽 다 문제 없이 사용하기 위해서다.

	// 배열과 구조체의 초기화
	// 배열 초기값 설정
	int arr[10] = { 1, 2, 3, 4, 5, 6 }; // 7번째 칸 ~ 10번째 칸은 자동으로 0으로 초기화된다.

	// 구조체 초기값 설정
	MYST t = { 100, 3.14f }; // a(정수): 100, f(실수): 3.14...
	t.a = 10; // 정수 파트 값 변경
	t.f = 10.2312f; // 실수 파트 값 변경

	return 0;
}