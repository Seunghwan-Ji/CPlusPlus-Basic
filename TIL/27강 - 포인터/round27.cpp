#include <stdio.h>

int main()
{
	// 포인터 변수
	// 주소를 저장하는 변수
	// 문법: 자료형 + * 변수명
	// 해당 포인터에게 전달된 주소를 해석하는 단위

	int i = 100; // 정수 자료형
	float f = 3.f; // 실수 자료형

	int* pInt = (int*)&f;
	// int* pInt: 정수형 자료의 변수만 취급하는 포인터 변수
	// (int*)&f: 실수 타입의 f 변수를 저장하고 있는 메모리 위치를 int* 타입의 포인터로 바라보겠다는 의미.(실제로 정수로 형변환이 되는게 아니다.)
	// int* pInt = &f;: f는 실수 타입이기 때문에 이 문장은 컴파일러가 방어적으로 문법 오류를 발생시킨다.

	// 주소로 접근
	i = *pInt; // 포인터 변수 역참조
	printf("%d", i);
	// 이전에 선언된 포인터 변수에 *을 붙이면 메모리 주소 대신 그 주소의 실제 값을 참조 한다고해서 역참조라고 한다.
	// 포인터는 실제 값인 실수 3.f를 이진수로 볼 것이다.
	// 그러나 정수형 포인터 변수는 값을 정수로 보기 때문에, 이진수를 실수로 변환하는게 아닌 정수로 변환한다.
	// 따라서 부호 비트, 지수부, 가수부로 이루어진 32비트(int=4byte)를
	// 실수가 아닌 정수로 변환하기 때문에 값이 매우 큰 값으로 변수 i에 저장된다.

	// 주소의 단위
	// BYTE

	return 0;
}