#pragma once

// ����ü ���ø�
template<typename T>
struct tListNode
{
	// C++ ����ü ����� Ŭ������ ������ ������ �Ǿ���.
	// �������� ����ü�� Ŭ���� ��� ���� ��Ģ�� ���س���.
	// ����� ���� �ʰ�, �����͸� ���� ���� �������� ����� ���� ����ü ���.
	// ���� ������ ��ɵ��� Ŭ���� ���.
	// ���� ���� �����ڸ� ���� ������ �⺻������ public ���� �����Ѵ�.(Ŭ���������� private)
	T		      data;
	// ���� �Ǵ� ���� ����� ������ Ÿ���� ���� ������ Ÿ������ ���߱� ���� <T> �� �ٿ��ش�.
	// �׷��� ����ü ������ �ڱ� �ڽ��� ����ü �̸��� ��Ī�ϸ�, �����Ϸ��� <T> �� ������ �ʾƵ�
	// �ڵ����� ġȯ �ڷ��� ������ �����͸� ����Ų��.
	// ���⼭�� �ǵ��� ��������� ǥ���ϱ� ���� <T> �� ���δ�.
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
	int m_icount;

public:
	void push_back(const T& _data);
	void push_front(const T& _data);
	// ���ڷ� ���� �������� Ÿ���� �󸶳� ū ũ���� �ڷ������� �𸣹Ƿ�,
	// ���� ����� ���̱� ���� ���� ���·� �ް�, ������ �������� �ʱ� ����
	// ���� ���� ���ȭ�ؼ� �޴´�.

public:
	CList();
	~CList();
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
