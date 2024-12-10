#pragma once

#include <assert.h>

template<typename T>
class CArr
{
private:
	T* m_pData;
	int  m_iCount;
	int  m_iMaxCount;

public:
	void push_back(const T& _Data);
	void resize(int _iResizeCount);
	T* data() { return m_pData; }
	int size() { return m_iCount; }
	int capacity() { return m_iMaxCount; }
	T& operator[] (int idx);

	class iterator;
	iterator begin();
	iterator end();
	iterator erase(const iterator& _iter);

public:
	CArr();
	~CArr();

	class iterator
	{
	private:
		CArr* m_pArr; // iterator 가 가리킬 데이터를 관리하는 가변 배열 주소
		// 힙 메모리가 재할당되면 배열의 시작 주소가 바뀌므로,
		// CArr의 객체 자체의 주소를 받는다.
		T* m_pData; // 데이터들의 시작 주소
		int   m_iIdx; // 가리키는 데이터의 인덱스

	public:
		T& operator * ()
		{
			// iterator 가 알고있는 주소와 가변 배열이 알고있는 주소가 서로 다를 경우의 조건
			// (공간 확장으로 인해 주소가 달라진 경우)
			// 또는 iterator 가 end iterator 인 경우(인덱스 -1)
			if (m_pArr->m_pData != m_pData || -1 == m_iIdx)
			{
				assert(nullptr); // 예외처리
			}

			return m_pData[m_iIdx];
		}

		// ++(전위)
		iterator& operator ++()
		{
			if (m_pArr->m_pData != m_pData || -1 == m_iIdx)
			{
				assert(nullptr); // 예외처리
			}

			// iterator 가 마지막 데이터를 가리키고 있는 경우
			// --> end iterator 가 된다.
			if (m_pArr->size() - 1 == m_iIdx)
			{
				m_iIdx = -1;
			}
			else
			{
				++m_iIdx;
			}

			return *this;
		}

		// ++(후위)
		iterator operator ++(int)
		{
			iterator copy_iter = *this;

			++(*this);

			return copy_iter;
		}

		// 전위, 후위 -- 연산자를 직접 구현해보자
		iterator& operator --()
		{
			return *this;
		}

		// 비교 연산자 ==
		bool operator ==(const iterator& _otherIter)
		{
			// 두 iterator 객체가 가리키는 시작 주소가 같고, 인덱스가 같은 경우.
			if (m_pData == _otherIter.m_pData && m_iIdx == _otherIter.m_iIdx)
			{
				return true;
			}

			return false;
		}

		// 비교 연산자 !=
		bool operator !=(const iterator& _otherIter)
		{
			return !(*this == _otherIter);
		}

	public:
		iterator()
			: m_pArr(nullptr)
			, m_pData(nullptr)
			, m_iIdx(-1)
		{

		}

		iterator(CArr* _pArr, T* _pData, int _iIdx)
			: m_pArr(_pArr)
			, m_pData(_pData)
			, m_iIdx(_iIdx)
		{

		}

		~iterator()
		{

		}

		friend class CArr; // friend: iterator 클래스가 CArr 클래스와 친구를 선언하게 되면,
		// CArr 클래스는 iterator 클래스의 private 멤버들을 접근할 수 있게 된다.
	};
};

template<typename T>
typename CArr<T>::iterator CArr<T>::begin()
{
	// 시작을 가리키는 iterator 를 만들어서 반환해줌.
	if (0 == m_iCount) // 데이터가 아무것도 들어가 있지 않은 경우.
	{
		return iterator(this, m_pData, -1); // begin() == end()
	}
	else
	{
		return iterator(this, m_pData, 0);
	}
}

template<typename T>
typename CArr<T>::iterator CArr<T>::end()
{
	// 끝의 다음을 가리키는 iterator 를 만들어서 반환해줌.
	return iterator(this, m_pData, -1);
}

template<typename T>
typename CArr<T>::iterator CArr<T>::erase(const iterator& _iter)
{
	// iterator 가 다른 가변 배열(CArr) 쪽 요소를 가리키는 경우.
	// iterator 가 end iterator 인 경우.
	if (this != _iter.m_pArr || end() == _iter)
	{
		assert(nullptr);
	}

	return iterator();
}

template<typename T>
CArr<T>::CArr()
	: m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pData = new T[2]; // 치환 자료형인 T 타입으로 동적할당.
}

template<typename T>
CArr<T>::~CArr()
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
	this->m_pData[this->m_iCount++] = _Data;
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
