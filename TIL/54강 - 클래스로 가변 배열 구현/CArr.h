#pragma once

// 구조체로 구현했던 가변 배열을 클래스로 구현해보기.
class CArr
{
private: // private 키워드는 적지 않아도 멤버들을 감춰주지만, 명시적으로 쓰는 편이다.
	int* m_pInt; // m_ 은 멤버의 약자를 의미.
	int  m_iCount;
	int  m_iMaxCount;

public:
	void push_back(int _Data);
	void resize(int _iResizeCount);

	int& operator[] (int idx); // 객체를 통해 [] 연산자 사용 시 호출되는 함수
	// 객체의 가변 배열을 일반 배열처럼 값을 참조 및 인덱싱하여 값을 변경할 수 있도록 하는 기능.

public:
	CArr(); // 생성자 함수는 공개 처리해야 객체를 생성할 때 생성자를 호출할 수 있다.
	~CArr(); // 소멸자 함수도 마찬가지다.
};