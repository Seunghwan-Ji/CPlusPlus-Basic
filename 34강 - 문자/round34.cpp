#include <stdio.h>

int main()
{
	// 문자
	// char(1), wchar(2)
	// 문자를 전용으로 나타내기 위한 자료형.
	// 표현 방식은 정수형이지만, 정수를 넣게 되면 정수에 대응하는 문자까지도 보여준다.
	// 1바이트는 0~255까지 수를 나타낼 수 있지만, utf-8 형식은 최상위 비트에 1을 사용하기 때문에 7비트를 사용하여 127가지가 되며,
	// 아스키 코드표에서도 127가지의 문자들이 맵핑된다.

	char c = 'a';
	wchar_t wc = L'a';

	return 0;
}