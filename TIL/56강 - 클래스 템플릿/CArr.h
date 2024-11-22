#pragma once

#include <assert.h>

// 클래스 템플릿
template<typename T>
class CArr
{
private:
	T* m_pData;
	// 아래 멤버 둘은 개수를 저장하는 멤버 변수이므로 치환하지 않는다.
	int  m_iCount;
	int  m_iMaxCount;

public:
	void push_back(const T& _Data); // 받아갈 데이터가 어떤 자료형인지, 얼마나 큰지 알 수 없으므로,
	// 데이터를 참조 형태로 받는다.(주소와 값 모두 상수화해서 받음)
	void resize(int _iResizeCount); // 개수 개념이니 T 로 바꾸지 않는다.

	T& operator[] (int idx); // 참조하는 대상이 T 타입이므로 저장되있으므로, 반환 형태는 T
	// 인덱스는 번호 개념이므로 바꾸지 않는다.

public:
	CArr(); // 생성자 함수는 공개 처리해야 객체를 생성할 때 생성자를 호출할 수 있다.
	~CArr(); // 소멸자 함수도 마찬가지다.
};

// 템플릿을 사용할 경우 실제 구현 함수들도 헤더 파일에 작성해야한다.
// cpp 파일에 작성된 함수들은 구현이 완료된 함수들이어야 하는데,
// 자료형을 대입해 호출해줘야 함수가 만들어지는 치환된 자료형 타입의 함수들이기 때문이다.
// 따라서 템플릿 정의를 cpp 파일에 넣는 경우,
// 컴파일러는 그 정의를 참조할 수 없기 때문에 링크 에러가 발생한다.

template<typename T> // 아래는 완성된 함수가 아닌 템플릿이라는 것을 지칭한다.
CArr<T>::CArr() // CArr 클래스의 T 버전 안에 선언되어 있는 생성자 함수를 지칭한다.
// CArr<T> 에서 CArr 까지만 작성하면 템플릿이고, <T> 까지 작성해야
// 클래스 풀네임을 의미한다.
	: m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pData = new T[2]; // 치환 자료형인 T 타입으로 동적할당.
}

template<typename T>
CArr<T>::~CArr() // CArr 클래스의 T 버전 안에 선언되어 있는 소멸자 함수를 지칭한다.
{
	delete[] m_pData; // 위와 같이 int 단위가 여러개 있을땐, [] 기호를 붙여줘야 한다.
	// 배열 형태의 메모리를 지울 때 [] 기호를 붙임.
}

template<typename T>
void CArr<T>::push_back(const T& _Data)
{
	// 힙 영역에 할당한 공간이 다 찼을 경우의 조건
	if (this->m_iMaxCount <= this->m_iCount)
	{
		// 재할당
		resize(this->m_iMaxCount * 2);
	}

	// 데이터 추가
	this->m_pData[this->m_iCount++] = _Data; // 추가할 데이터 위치 = 쌓인 데이터 개수, iCount++: 후위 연산자, 앞에 연산이 끝나고 ++ 수행.
	// 힙 메모리도 배열처럼 연속된 메모리 블록으로 할당되기 때문에 [] 연산자로 인덱싱 표현이 가능하다.

	// this-> 는 지워서 생략해도 된다.
	// 어차피 위 함수는 객체를 통해서 호출되기 때문에 기본적으로 객체의 주소를 함수 내부에 받아놓고 있고,
	// 위 멤버 변수들은 해당 객체의 멤버들이기 때문이다.
}

template<typename T>
void CArr<T>::resize(int _iResizeCount)
{
	// 현재 최대 수용량 보다 더 적거나 같은 수치로 확장하려는 경우의 조건.
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr); // 예외 처리
	}

	// 1. 리사이즈 시킬 개수만큼 동적할당 한다.
	T* pNew = new T[_iResizeCount]; // T 타입으로 재할당하고, T 타입 포인터로 주소를 받는다.

	// 2. 기존 공간에 있던 데이터들을 새로 할당한 공간으로 복사시킨다.
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pData[i];
	}

	// 3. 기존 공간의 메모리는 해제한다.
	delete[] m_pData;

	// 4. 새로 할당된 공간을 가리키게 한다.
	m_pData = pNew;

	// 5. iMaxCount 의 값을 수정한다.
	m_iMaxCount = _iResizeCount;
}

template<typename T>
T& CArr<T>::operator[](int idx) // 가변 배열에서 참조할 인덱스를 인자로 받는다.
{
	return m_pData[idx]; // 반환 타입: 가리키는 주소만 상수화한 T 타입 참조 형태.
}
