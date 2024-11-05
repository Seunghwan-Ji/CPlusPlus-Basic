#include <stdio.h>

void main()
{
	// 1. const
	const int i = 100;

	// const 와 포인터
	int a = 0;
	int* pInt = &a;

	*pInt = 1;
	pInt = nullptr; // 포인터 변수가 가리키는 주소가 없도록 초기화.

	// 포인터는 주소를 가리킬 수 있고, 그 주소의 값을 변경할 수 있는 두 가지 역할을 갖는다.

	// const 포인터
	int b = 0;
	const int* pConstInt = &a; // 포인터가 가리키는 주소의 값을 상수화.
	// *pConstint = 100; // 역참조해서 값을 수정할 수 없다.
	pConstInt = &b; // 가리키는 주소는 변경할 수 있다.

	// 포인터 const
	int* const pIntConst = &a; // 포인터 변수 자체를 상수화, 가리키는 주소가 고정.
	*pIntConst = 400; // 값은 변경 가능.
	//pIntConst = &b; // 주소는 변경 불가능.

	// 가리키는 주소와 그 주소의 값 둘 다 상수화
	const int* const pConstIntConst = nullptr;
	// 초기화 시 가리킨 주소만 가리킴, 가리키는 주소의 값을 수정할 수 없음.

	// const와 포인터 문법 암기 팁
	// const + 수식어
	// 수식어를 기준으로 상수화 시킨다고 이해하기.
	// ex)
	// const int*: 주소로 접근했을 때 정수형 자료형으로 보는 값을 상수화
	// const pIntConst: 주소가 저장된 포인터 변수의 주소를 상수화.

	int const* p = &a; // 'const int* p = &a;' 이것과 같은 표현이다.
	// *을 수식하는건 int*을 수식하는거랑 같다.
	// 따라서 같은 문장이지만, 잘 안 쓰인다.
	// *p = 0; 값 변경 불가능.


	// 혼동하지 않아야 할 사항
	int a = 0;
	const int* pInT = &a;
	// *pInT = 100;
	a = 100; // 선언된 변수 a 자체는 포인터 변수 pInT 와 별개 이므로,
	// 당연히 값을 수정할 수 있다.

	int* j = &a;
	*j = 100; // 마찬가지로 이 포인터 변수 또한 pInT 와 별개 이므로,
	// 값을 수정할 수 있다.
}