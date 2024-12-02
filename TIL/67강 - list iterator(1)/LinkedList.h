#pragma once

#include <assert.h>

// 구조체 템플릿
template<typename T>
struct tListNode
{
	T		      data;
	tListNode<T>* pPrev; // 이전 노드의 주소.
	tListNode<T>* pNext;

	tListNode() // 구조체는 클래스와 같으므로 생성자 함수 생성 가능.
		// 노드 초기화
		: data()
		, pPrev(nullptr)
		, pNext(nullptr)
	{

	}

	// 생성자도 함수 오버로딩 가능.
	tListNode(const T& _data, tListNode<T>* _pPrev, tListNode<T>* _pNext)
		// 받아온 인자로 초기화
		: data(_data)
		, pPrev(_pPrev)
		, pNext(_pNext)
	{

	}
};

// 클래스 템플릿
template<typename T> // 사용자가 집어넣은 자료형으로 노드 생성 시작.
class CList
{
private:
	tListNode<T>* m_pHead; // 받은 자료형 포인터로 헤드 노드를 가리킨다.
	tListNode<T>* m_pTail; // 꼬리 노드(마지막 노드의 주소)
	int		      m_icount;

public:
	void push_back(const T& _data);
	void push_front(const T& _data);
	int size() { return m_icount; }

public:
	class iterator;
	iterator begin();
	iterator end();
	iterator erase(iterator& _iter);
	iterator insert(const iterator& _iter, const T& _data);

public:
	CList();
	~CList();

	class iterator
	{
	private:
		CList<T>* m_pList;
		tListNode<T>* m_pNode; // null 인 경우, end iterator 로 간주하기로 한다.
		bool	      m_bValid;

	public:
		T& operator* ()
		{
			return m_pNode->data;
		}

		bool operator ==(const iterator& _otherIter)
		{
			if (m_pList == _otherIter.m_pList && m_pNode == _otherIter.m_pNode)
			{
				return true;
			}

			return false;
		}

		bool operator !=(const iterator& _otherIter)
		{
			return !(*this == _otherIter); // 연산자 함수 재활용 후 부정을 반환
		}

		iterator& operator ++()
		{
			// end 에서 ++ 한 경우, 유효한 iterator 일 경우
			if (nullptr == m_pNode || !m_bValid)
			{
				assert(nullptr);
			}

			m_pNode = m_pNode->pNext; // 다음 노드로 갱신

			return *this;
		}

		iterator operator ++(int)
		{
			iterator copyIter(*this);

			++(*this);

			return copyIter;
		}

		iterator& operator --()
		{
			if (nullptr == m_pNode || !m_bValid)
			{
				assert(nullptr);
			}

			m_pNode = m_pNode->pPrev; // 이전 노드로 갱신

			return *this;
		}

		iterator operator --(int)
		{
			iterator copyIter(*this);

			--(*this);

			return copyIter;
		}

	public:
		iterator()
			: m_pList(nullptr)
			, m_pNode(nullptr)
			, m_bValid(false)
		{

		}

		iterator(CList<T>* _pList, tListNode<T>* _pNode)
			: m_pList(_pList)
			, m_pNode(_pNode)
			, m_bValid(false)
		{
			if (nullptr != _pList && nullptr != _pNode)
			{
				m_bValid = true;
			}
		}

		~iterator()
		{

		}

		friend class CList;
	};
};

template<typename T>
inline void CList<T>::push_back(const T& _data)
{
	// 입력된 데이터를 저장할 노드를 동적할당 한다.
	// 지역변수에 임시적으로 새 노드 생성.
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, nullptr); // 오버로딩 생성자 함수로 노드 초기화.

	// 처음 입력된 데이터라면
	if (nullptr == m_pHead)
	{
		m_pHead = pNewNode; // this->m_pHead
		m_pTail = pNewNode;
	}
	else
	{
		// 데이터가 1개 이상인 상태에서 들어온 경우
		// 현재 가장 마지막 데이터(Tail)를 저장하고 있는 노드와
		// 새로 생성된 노드가 서로 가리키게 한다.
		m_pTail->pNext = pNewNode;
		pNewNode->pPrev = m_pTail;

		// 꼬리 노드 갱신
		m_pTail = pNewNode;
	}

	// 데이터 개수 증가
	++m_icount;
}

template<typename T>
inline void CList<T>::push_front(const T& _data)
{
	// 새로 생성된 노드의 다음을 현재 헤드 노드의 주소값으로 채운다.
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, m_pHead);

	// 현재 헤드 노드의 이전 노드 주소값을 새로 생성된 노드의 주소로 채운다.
	m_pHead->pPrev = pNewNode;

	// 헤드 노드를 새로 생성한 노드로 갱신
	m_pHead = pNewNode;

	// 데이터 개수 증가
	++m_icount;
}

template<typename T>
CList<T>::CList() // 생성자 함수, 리스트 초기화.
	: m_pHead(nullptr) // 초기엔 가리키는 주소 없음.
	, m_pTail(nullptr)
	, m_icount(0)
{

}

template<typename T>
inline CList<T>::~CList() // 소멸자 함수.
{
	// 반복문을 통해 노드들을 정방향으로 지우기
	tListNode<T>* pDeleteNode = m_pHead; // 지역변수에 헤드 노드의 주소 저장.

	while (true)
	{
		if (nullptr == pDeleteNode)
		{
			break; // 다음 노드의 주소가 더 이상 없으면 중지.
		}

		tListNode<T>* pNext = pDeleteNode->pNext; // 지역변수에 다음 노드의 주소 임시 저장.
		delete(pDeleteNode); // 노드가 할당된 힙 메모리 해제.
		pDeleteNode = pNext; // 다음 반복에서 참조할 노드의 주소를
		// 임시 저장해둔 다음 노드의 주소로 변경.
	}
}

template<typename T>
inline typename CList<T>::iterator CList<T>::begin()
{
	return iterator(this, m_pHead); // 리스트 객체와, 그 리스트의 헤드 노드를 가리키는
	// iterator 를 반환한다.
}

template<typename T>
inline typename CList<T>::iterator CList<T>::end()
{
	return iterator(this, nullptr);
}

template<typename T>
inline typename CList<T>::iterator CList<T>::insert(const iterator& _iter, const T& _data)
{
	if (end() == _iter)
	{
		assert(nullptr);
	}

	// 리스트에 추가되는 데이터를 저장할 노드 생성
	tListNode<T>* pNode = new tListNode<T>(_data, nullptr, nullptr);

	// iterator 가 가리키는 노드가 헤드노드인 경우
	if (_iter.m_pNode == m_pHead)
	{
		_iter.m_pNode->pPrev = pNode;
		pNode->pNext = _iter.m_pNode;

		m_pHead = pNode;
	}
	else
	{
		// iterator 가 가리키고 있는 노드의 이전으로 가서
		// 다음 노드 주소 파트를 새로 생성한 노드로 지정
		_iter.m_pNode->pPrev->pNext = pNode;

		// 새로 생성한 노드의 이전 노드는 iterator 가 가리키는 노드의 이전 노드로 지정
		pNode->pPrev = _iter.m_pNode->pPrev;

		// iterator 가 가리키는 노드의 이전 노드는 새로 생성한 노드로 지정
		_iter.m_pNode->pPrev = pNode;

		// 새로 생성한 노드의 다음 노드는 iterator 가 가리키는 노드로 지정
		pNode->pNext = _iter.m_pNode;
	}

	return iterator();
}
