#include <iostream>
#include "LinkedList.h"

int main()
{
	CList<int> list; // int 형태의 리스트와 노드가 만들어진다.
	// CList: 클래스 템플릿
	// CList<int>: 완전한 클래스

	// 정수 0~3 까지 저장, 디버깅을 통해 리스트를 확인해보자.
	for (int i = 0; i < 4; ++i)
	{
		list.push_back(i);
	}

	// printf(): C언어 출력 함수
	// std::cout: C++ 출력 기능
	std::cout << "안녕" << 10 << std::endl; // std::endl: 줄바꿈
	// 특징: %d, %s 등을 사용할 필요없이 자동으로 자료형을 분석하여 출력해준다.

	// scanf(): C언어 입력 함수
	// std::cin: C++ 입력 기능
	int iInput = 0;
	std::cin >> iInput;

	return 0;
}