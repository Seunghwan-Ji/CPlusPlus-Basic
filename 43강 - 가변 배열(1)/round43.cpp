#include <stdio.h>
#include <wchar.h> // 와이드 문자 스트링 길이 계산
#include <assert.h> // 예외처리 용도
#include <iostream> // Input Output Stream: C++의 표준 입출력 클래스가 정의되어 있는 헤더파일

// 변수
// 지역(스택)
// 전역, 정적, 외부(데이터)

// 메모리 영역
// 스택
// 데이터
// ROM
// 힙 영역(동적할당)

int main()
{
	// 가변배열
	// 배열 개수를 선언할 때에는 변수를 사용할 수 없다.
	int a = 100;
	scanf_s("%d", &a);
	// int arr[a] = {};
	// 이 경우 프로그램을 실행해봐야 배열의 크기를 정할 수 있기 때문에 스택 메모리에 할당할 수 없다.
	// 따라서 크기가 변하는 가변배열은 힙 메모리를 활용해야 한다.

	// 객체(Instance)
	// ex) int: 자료형, 설계도
	//   int a: 변수, 설계도에서 만든 객체

	return 0;
}