#pragma once

#include <assert.h>

// ����ü ���ø�
template<typename T>
struct tListNode
{
	T		      data;
	tListNode<T>* pPrev; // ���� ����� �ּ�.
	tListNode<T>* pNext;

	tListNode() // ����ü�� Ŭ������ �����Ƿ� ������ �Լ� ���� ����.
		// ��� �ʱ�ȭ
		: data()
		, pPrev(nullptr)
		, pNext(nullptr)
	{

	}

	// �����ڵ� �Լ� �����ε� ����.
	tListNode(const T& _data, tListNode<T>* _pPrev, tListNode<T>* _pNext)
		// �޾ƿ� ���ڷ� �ʱ�ȭ
		: data(_data)
		, pPrev(_pPrev)
		, pNext(_pNext)
	{

	}
};

// Ŭ���� ���ø�
template<typename T> // ����ڰ� ������� �ڷ������� ��� ���� ����.
class CList
{
private:
	tListNode<T>* m_pHead; // ���� �ڷ��� �����ͷ� ��� ��带 ����Ų��.
	tListNode<T>* m_pTail; // ���� ���(������ ����� �ּ�)
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
		tListNode<T>* m_pNode; // null �� ���, end iterator �� �����ϱ�� �Ѵ�.
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
			return !(*this == _otherIter); // ������ �Լ� ��Ȱ�� �� ������ ��ȯ
		}

		iterator& operator ++()
		{
			// end ���� ++ �� ���, ��ȿ�� iterator �� ���
			if (nullptr == m_pNode || !m_bValid)
			{
				assert(nullptr);
			}

			m_pNode = m_pNode->pNext; // ���� ���� ����

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

			m_pNode = m_pNode->pPrev; // ���� ���� ����

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
	// �Էµ� �����͸� ������ ��带 �����Ҵ� �Ѵ�.
	// ���������� �ӽ������� �� ��� ����.
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, nullptr); // �����ε� ������ �Լ��� ��� �ʱ�ȭ.

	// ó�� �Էµ� �����Ͷ��
	if (nullptr == m_pHead)
	{
		m_pHead = pNewNode; // this->m_pHead
		m_pTail = pNewNode;
	}
	else
	{
		// �����Ͱ� 1�� �̻��� ���¿��� ���� ���
		// ���� ���� ������ ������(Tail)�� �����ϰ� �ִ� ����
		// ���� ������ ��尡 ���� ����Ű�� �Ѵ�.
		m_pTail->pNext = pNewNode;
		pNewNode->pPrev = m_pTail;

		// ���� ��� ����
		m_pTail = pNewNode;
	}

	// ������ ���� ����
	++m_icount;
}

template<typename T>
inline void CList<T>::push_front(const T& _data)
{
	// ���� ������ ����� ������ ���� ��� ����� �ּҰ����� ä���.
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, m_pHead);

	// ���� ��� ����� ���� ��� �ּҰ��� ���� ������ ����� �ּҷ� ä���.
	m_pHead->pPrev = pNewNode;

	// ��� ��带 ���� ������ ���� ����
	m_pHead = pNewNode;

	// ������ ���� ����
	++m_icount;
}

template<typename T>
CList<T>::CList() // ������ �Լ�, ����Ʈ �ʱ�ȭ.
	: m_pHead(nullptr) // �ʱ⿣ ����Ű�� �ּ� ����.
	, m_pTail(nullptr)
	, m_icount(0)
{

}

template<typename T>
inline CList<T>::~CList() // �Ҹ��� �Լ�.
{
	// �ݺ����� ���� ������ ���������� �����
	tListNode<T>* pDeleteNode = m_pHead; // ���������� ��� ����� �ּ� ����.

	while (true)
	{
		if (nullptr == pDeleteNode)
		{
			break; // ���� ����� �ּҰ� �� �̻� ������ ����.
		}

		tListNode<T>* pNext = pDeleteNode->pNext; // ���������� ���� ����� �ּ� �ӽ� ����.
		delete(pDeleteNode); // ��尡 �Ҵ�� �� �޸� ����.
		pDeleteNode = pNext; // ���� �ݺ����� ������ ����� �ּҸ�
		// �ӽ� �����ص� ���� ����� �ּҷ� ����.
	}
}

template<typename T>
inline typename CList<T>::iterator CList<T>::begin()
{
	return iterator(this, m_pHead); // ����Ʈ ��ü��, �� ����Ʈ�� ��� ��带 ����Ű��
	// iterator �� ��ȯ�Ѵ�.
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

	// ����Ʈ�� �߰��Ǵ� �����͸� ������ ��� ����
	tListNode<T>* pNode = new tListNode<T>(_data, nullptr, nullptr);

	// iterator �� ����Ű�� ��尡 ������� ���
	if (_iter.m_pNode == m_pHead)
	{
		_iter.m_pNode->pPrev = pNode;
		pNode->pNext = _iter.m_pNode;

		m_pHead = pNode;
	}
	else
	{
		// iterator �� ����Ű�� �ִ� ����� �������� ����
		// ���� ��� �ּ� ��Ʈ�� ���� ������ ���� ����
		_iter.m_pNode->pPrev->pNext = pNode;

		// ���� ������ ����� ���� ���� iterator �� ����Ű�� ����� ���� ���� ����
		pNode->pPrev = _iter.m_pNode->pPrev;

		// iterator �� ����Ű�� ����� ���� ���� ���� ������ ���� ����
		_iter.m_pNode->pPrev = pNode;

		// ���� ������ ����� ���� ���� iterator �� ����Ű�� ���� ����
		pNode->pNext = _iter.m_pNode;
	}

	return iterator();
}
