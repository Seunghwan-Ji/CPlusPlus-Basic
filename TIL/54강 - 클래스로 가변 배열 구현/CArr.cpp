#include "CArr.h"
#include <assert.h>

// CArr::함수명
// CArr 클래스 내부의 멤버 함수를 의미한다.

CArr::CArr() // 생성자 함수
// 객체가 생성될 때, 클래스의 멤버 변수를 특정 값으로 초기화.
	: m_pInt(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pInt = new int[2]; // new   : 동적할당 함수, C++ 에서의 malloc 함수
	// int[2]: int 자료형을 2개 만큼 할당, 8바이트 공간
}

CArr::~CArr()
{
	delete[] m_pInt; // 위와 같이 int 단위가 여러개 있을땐, [] 기호를 붙여줘야 한다.
	// 배열 형태의 메모리를 지울 때 [] 기호를 붙임.
}

void CArr::push_back(int _Data)
{
	// 힙 영역에 할당한 공간이 다 찼을 경우의 조건
	if (this->m_iMaxCount <= this->m_iCount)
	{
		// 재할당
		resize(this->m_iMaxCount * 2);
	}

	// 데이터 추가
	this->m_pInt[this->m_iCount++] = _Data; // 추가할 데이터 위치 = 쌓인 데이터 개수, iCount++: 후위 연산자, 앞에 연산이 끝나고 ++ 수행.
	// 힙 메모리도 배열처럼 연속된 메모리 블록으로 할당되기 때문에 [] 연산자로 인덱싱 표현이 가능하다.

	// this-> 는 지워서 생략해도 된다.
	// 어차피 위 함수는 객체를 통해서 호출되기 때문에 기본적으로 객체의 주소를 함수 내부에 받아놓고 있고,
	// 위 멤버 변수들은 해당 객체의 멤버들이기 때문이다.
}

void CArr::resize(int _iResizeCount)
{
	// 현재 최대 수용량 보다 더 적거나 같은 수치로 확장하려는 경우의 조건.
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr); // 예외 처리
	}

	// 1. 리사이즈 시킬 개수만큼 동적할당 한다.
	int* pNew = new int[_iResizeCount];

	// 2. 기존 공간에 있던 데이터들을 새로 할당한 공간으로 복사시킨다.
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pInt[i];
	}

	// 3. 기존 공간의 메모리는 해제한다.
	delete[] m_pInt;

	// 4. 새로 할당된 공간을 가리키게 한다.
	m_pInt = pNew;

	// 5. iMaxCount 의 값을 수정한다.
	m_iMaxCount = _iResizeCount;
}

int& CArr::operator[](int idx) // 가변 배열에서 참조할 인덱스를 인자로 받는다.
{
	return m_pInt[idx]; // 반환 타입은 레퍼런스
	// 본래 함수의 반환 값은 호출 당한 함수 쪽에서 함수가 종료될 때 내부적으로 임의의 공간에 반환 값을 복사하여 임시적으로 저장해두고 종료된다.
	// 그리고 임시적으로 저장된 곳의 반환 값을 호출한 쪽에서 받아가는 원리이다.
	// 따라서 반환 값을 받아가는 쪽은 복사된 값을 받아가는 것이므로, m_pInt[idx] 은 실제 객체의 주소로 접근한 것이 아니다.
	// 그렇기 때문에 여기서 반환 타입을 &(레퍼런스) 으로 해주면 레퍼런스의 메모리 주소 공유 특성을 활용해 해결 할 수 있다.
	// 반환 시키고자 하는 변수의 참조를 전달 시킴으로써, 받아간 쪽에서는 반환 타입이지만,
	// 레퍼런스 특성상 다른 변수와 동일한 메모리 공간을 공유하므로, 받아간 쪽에서 인덱싱을 통해 주소로 접근해서 값을 수정할 수 있게 되는것이다.
}
