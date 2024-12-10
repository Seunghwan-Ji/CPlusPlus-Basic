#pragma once

#include <assert.h>

// Ŭ���� ���ø�
template<typename T> // �� ������ ���� inner class �� ���ø��� �ȴ�.
class CArr
{
private:
	T* m_pData; // ���α׷��� 64��Ʈ ȯ���̹Ƿ�, T �� ũ��� 8����Ʈ.
	// �Ʒ� ��� ���� ������ �����ϴ� ��� �����̹Ƿ� ġȯ���� �ʴ´�.
	int  m_iCount;
	int  m_iMaxCount;

public:
	void push_back(const T& _Data); // �޾ư� �����Ͱ� � �ڷ�������, �󸶳� ū�� �� �� �����Ƿ�,
	// �����͸� ���� ���·� �޴´�.(�ּҿ� �� ��� ���ȭ�ؼ� ����)
	void resize(int _iResizeCount); // ���� �����̴� T �� �ٲ��� �ʴ´�.

	T* data() { return m_pData; } // �迭�� ���� ������ ��ȯ �Լ�
	int size() { return m_iCount; } // ���� ������ ���� ��ȯ �Լ�
	int capacity() { return m_iMaxCount; } // �迭�� �ִ� ĭ �� ��ȯ �Լ�

	T& operator[] (int idx); // �����ϴ� ����� T Ÿ���̹Ƿ� ����������Ƿ�, ��ȯ ���´� T
	// �ε����� ��ȣ �����̹Ƿ� �ٲ��� �ʴ´�.

	class iterator; // iterator Ŭ������ �Ʒ��� ����Ǿ� �����Ƿ�, ���� ������ ���ش�.
	iterator begin();

public:
	CArr(); // ������ �Լ��� ���� ó���ؾ� ��ü�� ������ �� �����ڸ� ȣ���� �� �ִ�.
	~CArr(); // �Ҹ��� �Լ��� ����������.

	// inner class
	class iterator
		// �� Ŭ������ CArr Ŭ������ �����̴�.
		// ���� CArr Ŭ������ �ڷ��� ũ������� �� Ŭ������ �ڷ��� ũ�⸦ �������� �ʴ´�.
		// �� Ŭ������ ��Ī�Ϸ��� �������� ������(::) �� ����� CArr �ȿ� ���� Ŭ������ �����
		// iterator �� ��ü�� �����ؾ��Ѵ�.(�������� Ŭ���� ��Ī���� �ٸ��� ����.)
	{
	private:
		T* m_pData;
		int m_iIdx;

	public:
		iterator()
			: m_pData(nullptr)
			, m_iIdx(-1)
		{

		}

		iterator(T* _pData, int _iIdx)
			: m_pData(_pData)
			, m_iIdx(_iIdx)
		{

		}

		~iterator()
		{

		}
	};
};

// ���ø��� ����� ��� ���� ���� �Լ��鵵 ��� ���Ͽ� �ۼ��ؾ��Ѵ�.
// cpp ���Ͽ� �ۼ��� �Լ����� ������ �Ϸ�� �Լ����̾�� �ϴµ�,
// �ڷ����� ������ ȣ������� �Լ��� ��������� ġȯ�� �ڷ��� Ÿ���� �Լ����̱� �����̴�.
// ���� ���ø� ���Ǹ� cpp ���Ͽ� �ִ� ���,
// �����Ϸ��� �� ���Ǹ� ������ �� ���� ������ ��ũ ������ �߻��Ѵ�.

template<typename T>
typename CArr<T>::iterator CArr<T>::begin()
// CArr<T>::iterator : ��ȯ Ÿ��, CArr<T>::begin() : �Լ�
// typename : �� Ű����� ��ȯ Ÿ��(CArr<T>::iterator)��
// Ư�� Ÿ���̶�� ���� �˷��ֱ� ���� ǥ���ؾ��Ѵ�.
{
	// ������ ����Ű�� iterator �� ���� ��ȯ����.
	iterator iter(m_pData, 0); // ������ �����ε� �Լ� ȣ��.
	// ���ڷ� ���� ������, ���� �ε��� �־� �ʱ�ȭ ����.
	return iter;

	// return iterator(m_pData, 0); ���� �������� ���� �ʰ� �ٷ� �ʱ�ȭ �ϸ鼭 ��ȯ
}

template<typename T> // �Ʒ��� �ϼ��� �Լ��� �ƴ� ���ø��̶�� ���� ��Ī�Ѵ�.
CArr<T>::CArr() // CArr Ŭ������ T ���� �ȿ� ����Ǿ� �ִ� ������ �Լ��� ��Ī�Ѵ�.
// CArr<T> ���� CArr ������ �ۼ��ϸ� ���ø��̰�, <T> ���� �ۼ��ؾ�
// Ŭ���� Ǯ������ �ǹ��Ѵ�.
	: m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pData = new T[2]; // ġȯ �ڷ����� T Ÿ������ �����Ҵ�.
}

template<typename T>
CArr<T>::~CArr() // CArr Ŭ������ T ���� �ȿ� ����Ǿ� �ִ� �Ҹ��� �Լ��� ��Ī�Ѵ�.
{
	delete[] m_pData; // ���� ���� int ������ ������ ������, [] ��ȣ�� �ٿ���� �Ѵ�.
	// �迭 ������ �޸𸮸� ���� �� [] ��ȣ�� ����.
}

template<typename T>
void CArr<T>::push_back(const T& _Data)
{
	// �� ������ �Ҵ��� ������ �� á�� ����� ����
	if (this->m_iMaxCount <= this->m_iCount)
	{
		// ���Ҵ�
		resize(this->m_iMaxCount * 2);
	}

	// ������ �߰�
	this->m_pData[this->m_iCount++] = _Data; // �߰��� ������ ��ġ = ���� ������ ����, iCount++: ���� ������, �տ� ������ ������ ++ ����.
	// �� �޸𸮵� �迭ó�� ���ӵ� �޸� ������� �Ҵ�Ǳ� ������ [] �����ڷ� �ε��� ǥ���� �����ϴ�.

	// this-> �� ������ �����ص� �ȴ�.
	// ������ �� �Լ��� ��ü�� ���ؼ� ȣ��Ǳ� ������ �⺻������ ��ü�� �ּҸ� �Լ� ���ο� �޾Ƴ��� �ְ�,
	// �� ��� �������� �ش� ��ü�� ������̱� �����̴�.
}

template<typename T>
void CArr<T>::resize(int _iResizeCount)
{
	// ���� �ִ� ���뷮 ���� �� ���ų� ���� ��ġ�� Ȯ���Ϸ��� ����� ����.
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr); // ���� ó��
	}

	// 1. �������� ��ų ������ŭ �����Ҵ� �Ѵ�.
	T* pNew = new T[_iResizeCount]; // T Ÿ������ ���Ҵ��ϰ�, T Ÿ�� �����ͷ� �ּҸ� �޴´�.

	// 2. ���� ������ �ִ� �����͵��� ���� �Ҵ��� �������� �����Ų��.
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pData[i];
	}

	// 3. ���� ������ �޸𸮴� �����Ѵ�.
	delete[] m_pData;

	// 4. ���� �Ҵ�� ������ ����Ű�� �Ѵ�.
	m_pData = pNew;

	// 5. iMaxCount �� ���� �����Ѵ�.
	m_iMaxCount = _iResizeCount;
}

template<typename T>
T& CArr<T>::operator[](int idx) // ���� �迭���� ������ �ε����� ���ڷ� �޴´�.
{
	return m_pData[idx]; // ��ȯ Ÿ��: ����Ű�� �ּҸ� ���ȭ�� T Ÿ�� ���� ����.
}
