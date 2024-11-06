#include <stdio.h>

int main()
{
	// void*
	void* pVoid = nullptr; // void*: 메모리 주소로 접근했을 때 그 값을 어떤 자료형으로 볼 지 정하지 않음.
	// 그렇기에 모든 자료형 변수의 메모리 주소를 다 받을 수 있다.
	int a = 0;
	float f = 0.f;
	double d = 0.;
	long long ll = 0;

	pVoid = &a;
	pVoid = &f;
	pVoid = &d;
	pVoid = &ll;

	// *pVoid; 주소로 접근했을 때 어떤 자료형으로 볼 지 정하지 않았기 때문에,
	// 비트를 몇 바이트 크기 범위 까지 봐야하는지 알 수 없으므로, 역참조할 수 없다.
	// pVoid + 1; 주소 연산 또한 크기 단위가 존재하지 않으므로 불가능하다.

	return 0;
}