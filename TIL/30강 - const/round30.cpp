#include <stdio.h>

int main()
{
	// const: 상수 문법 키워드
	volatile const int cInt = 100; // volatile: 휘발성, 이 변수의 메모리 주소를 꼭 확인하라는 명령 키워드.
	// volatile 키워드를 붙이지 않으면, CPU 레지스터 메모리에 임시 저장된 상수값을 읽는다.
	// 컴파일러는 상수값이 변경될리가 없다고 판단하기 때문에, 컴파일 최적화를 위해
	// 실제 메모리 주소로 접근하는게 아닌, 값을 빠르게 가져다 쓸 수 있는 CPU 레지스터 메모리에 접근한다.
	// 그런데 아래와 같이 작성자가 상수의 메모리 주소로 직접 접근해 변경할 수 있기 때문에
	// volatile 키워드를 붙이면 실제 메모리 주소로 접근시켜 값을 확인하게 할 수 있다.

// cInt = 10; cInt는 상수이므로 값을 변경할 수 없다.

// 상수화
// l-value: 변수
// r-value: 상수

	int* pInt = (int*)&cInt; // 상수는 기본적으로 값을 변경할 수 없지만, 메모리 주소로 접근하면 값을 변경할 수 있다.
	*pInt = 300; // 메모리 주소가 저장된 포인터 변수를 역참조해서 값 변경.
	printf("cInt 출력: %d", cInt);

	return 0;
}