// #: 전처리기 구문, 컴파일 과정에서 가장 먼저 수행된다.('매크로'라고 불린다.)
// 컴파일러가 코드를 컴파일하기 전에 매크로를 치환하는 역할을 하기 때문에
// 세미콜론(;)을 붙이게 된다면 전처리기 지시문이 아닌 일반 코드로 인식되어
// 문법 오류가 발생한다.
#define HUNGRY  1 // 아래 HUNGRY 라는 모든 코드를 1로 치환하는 역할
#define THIRSTY 2
#define TIRED   4

// 일반적으로 16진수로 표현한다.(0x 는 16진수를 나타내는 표기이다.)
// 16진수: 0, 1, ..., 9, A, B, ... F (10진수로 치면 0 ~ 15)
#define HUNGRY  0x001 // 1
#define THIRSTY 0x002 // 2
#define TIRED   0x004 // 4
#define FIRE	0x008 // 8

#define COLD	0x010 // 16 (15 다음으로 16은 16진수로 10이다.)
#define POISON	0x020 // 32
#define POISON1	0x040 // 64
#define POISON2	0x080 // 128

#define POISON3	0x100 // 256
#define POISON4	0x200 // 512
#define POISON5 0x400 // 1024
#define POISON6 0x800 // 2048
// 4개씩 끊으면 이전 16진수와 다음 16진수가 두배씩 차이나는 규칙이 있다.

// 전처리기 구문의 사용 목적
// 1. 가독성
// 2. 유지보수

int main()
{
	// 비트 곱(&), 합(|), xor(^), 반전(~)
	// 비트 단위로 연산을 진행
	// &: 둘다 1인경우 1
	// ex) 1011 & 0101 = 0001

	// |: 둘중 하나라도 1 이면 1
	// ex) 1011 | 0101 = 1111

	// ^: 둘이 같으면 0, 다르면 1
	// ex) 1011 ^ 0101 = 1110

	// ~: 1은 0으로, 0은 1로 반전
	// ex) ~ 1011 = 0100

	unsigned int iStatus = 0;

	// 상태 추가
	iStatus |= HUNGRY; // iStatus 변수 비트에 HUNGRY 변수 비트를 합친다.
	iStatus |= THIRSTY;

	// 상태 확인
	if (iStatus & THIRSTY) // 곱 연산자를 통해서 상태 체크
	{
		// 목마름 상태에 해당하는 비트 자리가 1일 때 수행하고 싶은 문장.
	}

	// 특정 자리 비트 제거
	iStatus &= ~THIRSTY;

	return 0;
}