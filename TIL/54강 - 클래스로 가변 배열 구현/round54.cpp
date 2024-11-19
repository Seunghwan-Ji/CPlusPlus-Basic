#include <iostream>
#include "CArr.h"

class CTest
{
private:
	int a;

public:
	CTest()
		: a(10)
	{

	}

};

int main()
{
	// 구조체 --> 클래스

	// 객체지향 언어 특징
	// 1. 캡슐화
	// 기능을 수행하기 위해 필요한 멤버 선언, 묶음, 은닉성
	// 멤버 함수들

	// 2. 상속

	// 3. 다형성

	// 4. 추상화

	// 구조체 버전 가변배열 --> 클래스 버전


	// C++ 동적할당 new, delete
	CTest* pTest = new CTest;
	delete pTest;

	// CArr(C++ 클래스로 만든 가변 배열) 사용 예시
	CArr carr;
	carr.push_back(10);
	carr.push_back(20);
	carr.push_back(30);

	// carr 은 지역변수이기 때문에, 메인 함수가 종료될 때 사라진다.
	// 따라서 그 시점에 컴파일러가 소멸자를 호출해주기 때문에 수동으로 메모리를 해제해줄 필요가 없다.

	// 기존(C 구조체로 만든 가변 배열) 사용 예시
	/*
	tArr arr = {};
	InitArr(&arr);

	push_back(&arr, 10);
	push_back(&arr, 20);
	push_back(&arr, 30);

	ReleaseArr(&arr);
	*/

	// 객체를 배열처럼 사용하기
	int iData = carr[1];
	carr[1] = 100;

	return 0;
}